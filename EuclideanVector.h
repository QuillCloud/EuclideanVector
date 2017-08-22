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
#include <assert.h>

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
        double get(int) const;
        double getEuclideanNorm() const;
        EuclideanVector createUnitVector() const;
        double& operator[](int); // for setting via []
        double operator[](int) const;
        EuclideanVector& operator+=(const EuclideanVector&);
        EuclideanVector& operator-=(const EuclideanVector&);
        EuclideanVector& operator*=(double);
        EuclideanVector& operator/=(double);
        operator std::vector<double>() const;
        operator std::list<double>() const;

        //Friends
        friend bool operator==(const EuclideanVector&, const EuclideanVector&);
        friend bool operator!=(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
        friend double operator*(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator*(const EuclideanVector&, double);
        friend EuclideanVector operator*(double, const EuclideanVector&);
        friend EuclideanVector operator/(const EuclideanVector&, double);
        friend std::ostream& operator<<(std::ostream&, const EuclideanVector&);



        void changefirst();
        void print();


    private:
        unsigned int num_dim = 1;
        double *mag_vec = new double[1];

    };
    bool operator==(const EuclideanVector&, const EuclideanVector&);
    bool operator!=(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
    double operator*(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator*(const EuclideanVector&, double);
    EuclideanVector operator*(double, const EuclideanVector&);
    EuclideanVector operator/(const EuclideanVector&, double);
    std::ostream& operator<<(std::ostream&, const EuclideanVector&);
}

#endif //EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
