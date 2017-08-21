//
// Created by Yunhe Zhang on 19/08/2017.
//

#include "EuclideanVector.h"

using evec::EuclideanVector;

//Constructor
EuclideanVector::EuclideanVector(const unsigned int n) : num_dim{n}, mag_vec{new double[n]} {}

EuclideanVector::EuclideanVector() : EuclideanVector(1) {}

EuclideanVector::EuclideanVector(const unsigned int n,const double d) : num_dim{n} {
    mag_vec = new double[n];
    std::fill_n(mag_vec, n, d);
}

EuclideanVector::EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end) {
    num_dim = end - begin;
    mag_vec = new double[num_dim];
    int j = 0;
    for (std::vector<double>::iterator i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        j++;
    }
}

EuclideanVector::EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end) {
    num_dim = 0;
    for (std::list<double>::iterator i = begin; i != end; ++i) num_dim++;
    mag_vec = new double[num_dim];
    int j = 0;
    for (std::list<double>::iterator i = begin; i != end; ++i) {
        mag_vec[j] = *i;
        ++j;
    }
}

EuclideanVector::EuclideanVector(std::initializer_list<double> ini_list) {
    num_dim = ini_list.size();
    mag_vec = new double[num_dim];
    int j = 0;
    for (auto i = ini_list.begin(); i != ini_list.end(); ++i) {
        mag_vec[j] = *i;
        ++j;
    }
};

EuclideanVector::EuclideanVector(const EuclideanVector& ev) : num_dim{ev.num_dim} {
    mag_vec = new double[num_dim];
    for (auto i = 0; i < ev.num_dim; ++i) {
        mag_vec[i] = ev.mag_vec[i];
    }
}

EuclideanVector::EuclideanVector(EuclideanVector&& ev) : num_dim{std::move(ev.num_dim)}, mag_vec{ev.mag_vec} {
    ev.num_dim = 0;
    ev.mag_vec = nullptr;
}

//Destructor
EuclideanVector::~EuclideanVector() {
    delete[] mag_vec;
}

//Operations
EuclideanVector& EuclideanVector::operator=(const EuclideanVector& ev) {
    if (this != &ev) {
        num_dim = ev.num_dim;
        mag_vec = new double[num_dim];
        for (auto i = 0; i < ev.num_dim; ++i) {
            mag_vec[i] = ev.mag_vec[i];
        }
    }
    return *this;
}

EuclideanVector& EuclideanVector::operator=(EuclideanVector&& ev) {
    if (this != &ev) {
        num_dim = std::move(ev.num_dim);
        mag_vec = std::move(ev.mag_vec);
        ev.num_dim = 0;
        ev.mag_vec = nullptr;
    }
    return *this;
}

unsigned int EuclideanVector::getNumDimensions() const {
    return num_dim;
}

double EuclideanVector::get(unsigned int i) const {
    if (num_dim >= i)
        return mag_vec[i];
    else {
        std::cout << "Error: out of range" << std::endl;
        return NULL;
    }
}

double EuclideanVector::getEuclideanNorm() const{
    int sum = 0;
    for (auto i = 0; i < num_dim; ++i) {
        sum += pow(mag_vec[i], 2);
        std::cout << sum << std::endl;
    }
    return sqrt(sum);
}




void EuclideanVector::changefirst() {
    mag_vec[0] = 20;
}
void EuclideanVector::print() {
    for (auto i = 0; i < num_dim; ++i)
        std::cout << mag_vec[i] << " ";
    std::cout << std::endl;
}
