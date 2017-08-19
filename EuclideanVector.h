//
// Created by Yunhe Zhang on 19/08/2017.
//

#ifndef EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
#define EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

namespace evec {
    class EuclideanVector {
    public:
        EuclideanVector() {};
        EuclideanVector(const unsigned int n) : num_dim{n}, mag_vec{new double[n]} {}
        EuclideanVector(const unsigned int n,const double d) : num_dim{n} {
            mag_vec = new double[n];
            std::fill_n(mag_vec, n, d);
        }
        EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end) {
            num_dim = end - begin;
            mag_vec = new double[num_dim];
            int j = 0;
            for (std::vector<double>::iterator i = begin; i != end; ++i) {
                mag_vec[j] = *i;
                j++;
            }
        }
        EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end) {
            num_dim = 0;
            for (std::list<double>::iterator i = begin; i != end; ++i) num_dim++;

            mag_vec = new double[num_dim];
            int j = 0;
            for (std::list<double>::iterator i = begin; i != end; ++i) {
                mag_vec[j] = *i;
                std::cout<<mag_vec[j];
                ++j;
            }
        }
        EuclideanVector(const EuclideanVector &ev) : num_dim{ev.num_dim} {
            mag_vec = new double[num_dim];
            for (auto i = 0; i < ev.num_dim; ++i) {
                mag_vec[i] = ev.mag_vec[i];
            }
        }
        EuclideanVector(EuclideanVector &&ev) : num_dim{std::move(ev.num_dim)}, mag_vec{ev.mag_vec} {
            ev.num_dim = 0;
            ev.mag_vec = nullptr;
        }
        ~EuclideanVector() {
            delete[] mag_vec;
        }
        EuclideanVector& operator=(const EuclideanVector &ev) {
            if (this != &ev) {
                num_dim = ev.num_dim;
                mag_vec = new double[num_dim];
                for (auto i = 0; i < ev.num_dim; ++i) {
                    mag_vec[i] = ev.mag_vec[i];
                }
            }
            return *this;
        }
        int get() const;
        void changefirst();
        void print();


    private:
        unsigned int num_dim = 1;
        double *mag_vec = new double[1];

    };
}

#endif //EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
