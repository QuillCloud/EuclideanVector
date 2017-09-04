#ifndef EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
#define EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <initializer_list>
#include <assert.h>

namespace evec {
    class EuclideanVector {
    public:
        // Constructors part
        EuclideanVector(const unsigned&);
        EuclideanVector();
        EuclideanVector(const unsigned&,const double&);
        EuclideanVector(const std::vector<double>::iterator&,const std::vector<double>::iterator&);
        EuclideanVector(const std::vector<double>::const_iterator&,const std::vector<double>::const_iterator&);
        EuclideanVector(const std::list<double>::iterator&,const std::list<double>::iterator&);
        EuclideanVector(const std::list<double>::const_iterator&,const std::list<double>::const_iterator&);
        EuclideanVector(const std::initializer_list<double>&);
        EuclideanVector(const EuclideanVector&);
        EuclideanVector(EuclideanVector&&);

        //Destructor part
        ~EuclideanVector();

        //Operations part
        EuclideanVector& operator=(const EuclideanVector&);
        EuclideanVector& operator=(EuclideanVector&&);
        unsigned getNumDimensions() const;
        double get(const unsigned& ) const;
        double getEuclideanNorm() const;
        EuclideanVector createUnitVector() const;
        double& operator[](const unsigned& );
        double operator[](const unsigned& ) const;
        EuclideanVector& operator+=(const EuclideanVector&);
        EuclideanVector& operator-=(const EuclideanVector&);
        EuclideanVector& operator*=(const double&);
        EuclideanVector& operator/=(const double&);
        operator std::vector<double>() const;
        operator std::list<double>() const;

        // Nonmember functions
        friend bool operator==(const EuclideanVector&, const EuclideanVector&);
        friend bool operator!=(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
        friend double operator*(const EuclideanVector&, const EuclideanVector&);
        friend EuclideanVector operator*(const EuclideanVector&, const double&);
        friend EuclideanVector operator*(const double&, const EuclideanVector&);
        friend EuclideanVector operator/(const EuclideanVector&, const double&);
        friend std::ostream& operator<<(std::ostream&, const EuclideanVector&);

    private:
        // num_dim contains the number of dimensions
        unsigned num_dim;
        // mag_vec is a double array contain each dimension's magnitude
        double *mag_vec;
        // cache_norm cache the Euclidean norm value, set -1 as no cache.
        mutable double cache_norm = -1;
    };
    // declare nonmember functions outside of class
    bool operator==(const EuclideanVector&, const EuclideanVector&);
    bool operator!=(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator+(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator-(const EuclideanVector&, const EuclideanVector&);
    double operator*(const EuclideanVector&, const EuclideanVector&);
    EuclideanVector operator*(const EuclideanVector&, const double&);
    EuclideanVector operator*(const double&, const EuclideanVector&);
    EuclideanVector operator/(const EuclideanVector&, const double&);
    std::ostream& operator<<(std::ostream&, const EuclideanVector&);
}

#endif //EUCLIDEAN_VECTOR_CLASS_LIBRARY_EUCLIDEANVECTOR_H
