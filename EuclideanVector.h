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
#include <cmath>
#include <initializer_list>

namespace evec {
    class EuclideanVector {
    public:
        //Constructors
        EuclideanVector(const unsigned int);
        EuclideanVector();
        EuclideanVector(const unsigned int,const double);
        EuclideanVector(std::vector<double>::iterator, std::vector<double>::iterator);
        EuclideanVector(std::list<double>::iterator, std::list<double>::iterator);
        EuclideanVector(std::initializer_list<double>);
        EuclideanVector(const EuclideanVector&);
        EuclideanVector(EuclideanVector&&);

        //Destructor
        ~EuclideanVector();

        //Operations
        EuclideanVector& operator=(const EuclideanVector&);
        EuclideanVector& operator=(EuclideanVector&&);
        unsigned int getNumDimensions() const;
        double get(unsigned int) const;
        double getEuclideanNorm() const;



        void changefirst();
        void print();


    private:
        unsigned int num_dim = 1;
        double *mag_vec = new double[1];

    };
}

#endif //EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
