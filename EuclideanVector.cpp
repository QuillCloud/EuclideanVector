#include "EuclideanVector.h"

using evec::EuclideanVector;

// constructor that takes the number of dimensions but no magnitudes
// set dimension as argument 'n'
EuclideanVector::EuclideanVector(const unsigned &n) : num_dim{n} {
    // create double array and set all elements to 0.0
    mag_vec = new double[n];
    std::fill_n(mag_vec, n, 0.0);
}

// default constructor, set dimension as 1 and magnitude as 0.0
EuclideanVector::EuclideanVector() : EuclideanVector(1) {}  // use constructor EuclideanVector{1}

// constructor that takes the number of dimensions and initialises the magnitude in each dimension
// set dimension as argument 'n'.
EuclideanVector::EuclideanVector(const unsigned& n,const double& d) : num_dim{n} {
    // create double array and set all elements to argument 'd'.
    mag_vec = new double[n];
    std::fill_n(mag_vec, n, d);
}

// constructor that takes the start and end of an std::vector<double> iterator
EuclideanVector::EuclideanVector(const std::vector<double>::iterator &begin,
                                 const std::vector<double>::iterator &end) {
    // set dimension as length of vector
    num_dim = end - begin;
    // create double array and set elements as corresponding elements in vector
    mag_vec = new double[num_dim];
    unsigned j = 0;
    for (auto i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        ++j;
    }
}

//constructor that takes the start and end of an std::vector<double> const_iterator
EuclideanVector::EuclideanVector(const std::vector<double>::const_iterator &begin,
                                 const std::vector<double>::const_iterator &end) {
    // set dimension as length of vector
    num_dim = end - begin;
    // create a double array and set elements as corresponding elements in vector
    mag_vec = new double[num_dim];
    unsigned j = 0;
    for (auto i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        ++j;
    }
}

// constructor that takes the start and end of an std::list<double> iterator
EuclideanVector::EuclideanVector(const std::list<double>::iterator &begin,
                                 const std::list<double>::iterator &end) {
    // set dimension as length of list
    num_dim = 0;
    for (auto i = begin; i != end; ++i)
        num_dim++;
    // create double array and set elements as corresponding elements in list
    mag_vec = new double[num_dim];
    unsigned j = 0;
    for (auto i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        ++j;
    }
}

// constructor that takes the start and end of an std::list<double> const_iterator
EuclideanVector::EuclideanVector(const std::list<double>::const_iterator &begin,
                                 const std::list<double>::const_iterator &end) {
    // set dimension as length of list
    num_dim = 0;
    for (auto i = begin; i != end; ++i)
        num_dim++;
    // create double array and set elements as corresponding elements in list
    mag_vec = new double[num_dim];
    unsigned j = 0;
    for (auto i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        ++j;
    }
}

// initialiser-list constructor that creates an Euclidean vector from a list of double values.
EuclideanVector::EuclideanVector(const std::initializer_list<double> &ini_list) {
    // set dimension as size of initialiser-list 'ini_list'
    num_dim = ini_list.size();
    // create double array and set elements as corresponding elements in 'ini_list'
    mag_vec = new double[num_dim];
    unsigned j = 0;
    for (auto i : ini_list) {
        mag_vec[j] = i;
        ++j;
    }
};

// copy constructor
// copy the number of dimensions
EuclideanVector::EuclideanVector(const EuclideanVector& ev) : num_dim{ev.num_dim} {
    // copy the magnitudes in each dimension
    mag_vec = new double[num_dim];
    for (unsigned i = 0; i < ev.num_dim; ++i)
        mag_vec[i] = ev.mag_vec[i];
}

// move constructor
// get the number of dimensions and the magnitudes in each dimension
EuclideanVector::EuclideanVector(EuclideanVector&& ev) : num_dim{std::move(ev.num_dim)},
                                                         mag_vec{std::move(ev.mag_vec)} {
    // clear the argument EuclideanVector
    ev.num_dim = 0;
    ev.mag_vec = nullptr;
}

// destructor
EuclideanVector::~EuclideanVector() {
    // delete the double array
    delete[] mag_vec;
}

// copy assignment
EuclideanVector& EuclideanVector::operator=(const EuclideanVector& ev) {
    // copy the number of dimensions and the magnitudes in each dimension
    if (this != &ev) {
        num_dim = ev.num_dim;
        mag_vec = new double[num_dim];
        for (unsigned i = 0; i < ev.num_dim; ++i)
            mag_vec[i] = ev.mag_vec[i];
        // clear the cache
        cache_norm = -1;
    }
    return *this;
}

// move assignment
EuclideanVector& EuclideanVector::operator=(EuclideanVector&& ev) {
    // get the number of dimensions and the magnitudes in each dimension
    if (this != &ev) {
        num_dim = std::move(ev.num_dim);
        mag_vec = std::move(ev.mag_vec);
        // clear the cache
        cache_norm = -1;
        // clear the argument EuclideanVector
        ev.num_dim = 0;
        ev.mag_vec = nullptr;
    }
    return *this;
}

// returns the number of dimensions
unsigned EuclideanVector::getNumDimensions() const {
    return num_dim;
}

// returns the value of the magnitude in a given dimension
double EuclideanVector::get(const unsigned &index) const {
    // check if index out of range
    assert(index < num_dim);
    return mag_vec[index];
}

// returns the Euclidean norm of the vector
double EuclideanVector::getEuclideanNorm() const {
    // if cache is already set, return cache value without change
    // otherwise calculate Euclidean norm and store in cache, return cache value
    if (cache_norm == -1) {
        auto sum = 0.0;
        for (unsigned i = 0; i < num_dim; ++i)
            sum += pow(mag_vec[i], 2);
        cache_norm = sqrt(sum);
    }
    return cache_norm;
}

// returns an Euclidean vector that is the unit vector of *this vector
EuclideanVector EuclideanVector::createUnitVector() const {
    // create a new EuclideanVector with original EuclideanVector's dimension
    EuclideanVector result(num_dim);
    auto en = getEuclideanNorm();
    // set magnitudes in each dimension as original vector's magnitudes in each dimension divided by Euclidean norm
    for (unsigned i = 0; i < num_dim; ++i)
        result.mag_vec[i] = mag_vec[i] / en;
    return result;
}

// set the value in a given dimension
double& EuclideanVector::operator[](const unsigned &index) {
    // check if index out of range
    assert((index >= 0) && (index < num_dim));
    // clear the cache
    cache_norm = -1;
    return mag_vec[index];
}

// get the value in a given dimension
double EuclideanVector::operator[](const unsigned &index) const {
    // check if index out of range
    assert((index >= 0) && (index < num_dim));
    return mag_vec[index];
}

// adding vectors of the same dimension
EuclideanVector& EuclideanVector::operator+=(const EuclideanVector &ev) {
    // check if vectors have same dimension
    assert(num_dim == ev.num_dim);
    // add two vectors' magnitudes in each dimension and assign to *this vector
    for (unsigned i = 0; i < num_dim; ++i)
        mag_vec[i] += ev.mag_vec[i];
    // clear the cache
    cache_norm = -1;
    return *this;
}

// subtracting vectors of the same dimension.
EuclideanVector& EuclideanVector::operator-=(const EuclideanVector &ev) {
    // check if vectors have same dimension
    assert(num_dim == ev.num_dim);
    // subtract two vectors' magnitudes in each dimension and assign to *this vector
    for (unsigned i = 0; i < num_dim; ++i)
        mag_vec[i] -= ev.mag_vec[i];
    // clear the cache
    cache_norm = -1;
    return *this;
}

// scalar multiplication
EuclideanVector& EuclideanVector::operator*=(const double &d) {
    // magnitudes in each dimension times argument 'd'
    for (unsigned i = 0; i < num_dim; ++i)
        mag_vec[i] *= d;
    // clear the cache
    cache_norm = -1;
    return *this;
}

// scalar division
EuclideanVector& EuclideanVector::operator/=(const double &d) {
    // magnitudes in each dimension divided by argument 'd'
    for (unsigned i = 0; i < num_dim; ++i)
        mag_vec[i] /= d;
    // clear the cache
    cache_norm = -1;
    return *this;
}

// type casting to std::vector<double>
EuclideanVector::operator std::vector<double>() const {
    // create std::list<double>
    std::vector<double> v;
    // assign magnitudes in each dimension to corresponding elements in vector
    for (unsigned i = 0; i < num_dim; ++i)
        v.push_back(mag_vec[i]);
    return v;
}

// type casting to std::list<double>
EuclideanVector::operator std::list<double>() const {
    // create std::list<double>
    std::list<double> l;
    // assign magnitudes value in each dimension to corresponding elements in list
    for (unsigned i = 0; i < num_dim; ++i)
        l.push_back(mag_vec[i]);
    return l;
}

// overload of operator '==' for checking if two Euclidean vectors are equal
bool evec::operator==(const EuclideanVector &ev1, const EuclideanVector &ev2) {
    // return false if two vectors' dimensions are different
    if (ev1.num_dim != ev2.num_dim)
        return false;
    // return false if any of two vectors' magnitudes in each dimension are different
    for (unsigned i = 0; i < ev1.num_dim; ++i) {
        if (ev1.mag_vec[i] != ev2.mag_vec[i])
            return false;
    }
    return true;
}

// overload of operator '!=' for checking if two Euclidean vectors are not equal
bool evec::operator!=(const EuclideanVector &ev1, const EuclideanVector &ev2) {
    // return opposite of operator '=='
    return !(ev1 == ev2);
}

// overload of operator '+' for adding vectors of the same dimension
EuclideanVector evec::operator+(const EuclideanVector &ev1, const EuclideanVector &ev2) {
    // check if two vectors have same dimension
    assert(ev1.num_dim == ev2.num_dim);
    // use copy constructor to get copy of first argument vector
    EuclideanVector result(ev1);
    // call 'operator+=' to get result
    result += ev2;
    return result;
}

// overload of operator '-' for substracting vectors of the same dimension
EuclideanVector evec::operator-(const EuclideanVector &ev1, const EuclideanVector &ev2) {
    // check if two vectors have same dimension
    assert(ev1.num_dim == ev2.num_dim);
    // use copy constructor to get copy of first argument vector
    EuclideanVector result(ev1);
    // call 'operator-=' to get result
    result -= ev2;
    return result;
}

// overload of operator '*' for dot-product multiplication
double evec::operator*(const EuclideanVector &ev1, const EuclideanVector &ev2) {
    // check if two vectors have same dimension
    assert(ev1.num_dim == ev2.num_dim);
    double result = 0;
    // multiply two vectors' magnitudes in each dimension and sum them up, return the result
    for (unsigned i = 0; i < ev1.num_dim; ++i)
        result += ev1.mag_vec[i] * ev2.mag_vec[i];
    return result;
}

// overload of operator '*' for scalar multiplication, the vector is at left side
EuclideanVector evec::operator*(const EuclideanVector &ev,const double &d_num) {
    // use copy constructor to get copy of argument vector
    EuclideanVector result(ev);
    // call 'operator*=' to get result
    result *= d_num;
    return result;
}

// overload of operator '*' for scalar multiplication, the vector is at right side
EuclideanVector evec::operator*(const double &d_num, const EuclideanVector &ev) {
    return ev * d_num;
}

// overload of operator '/' for scalar division
EuclideanVector evec::operator/(const EuclideanVector &ev,const double &d_num) {
    // use copy constructor to get copy of argument vector
    EuclideanVector result(ev);
    // use scalar division to get result vector and return it
    result /= d_num;
    return result;
}

// overload of operator '<<', prints out the magnitude in each dimension of the Euclidean Vector
std::ostream& evec::operator<<(std::ostream &os, const EuclideanVector &ev){
    // print out vector's magnitudes in each dimension in form like '[num1 num2 num3]'
    os << "[";
    for (unsigned i = 0; i < ev.num_dim; ++i) {
        os << ev.mag_vec[i];
        if (i != ev.num_dim - 1)
            os << " ";
    }
    os << "]";
    return os;
}