//
// Created by Yunhe Zhang on 19/08/2017.
//

#include "EuclideanVector.h"

using evec::EuclideanVector;

//Constructor
EuclideanVector::EuclideanVector(const unsigned int n) : num_dim{n}, mag_vec{new double[n]} {
    for (auto i = 0; i < num_dim; ++i) {
        mag_vec[i] = 0;
    }
}
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

double EuclideanVector::get(int index) const {
    assert((index >= 0) && (index < num_dim));
    return mag_vec[index];
}

double EuclideanVector::getEuclideanNorm() const{
    double sum = 0;
    for (auto i = 0; i < num_dim; ++i) {
        sum += pow(mag_vec[i], 2);
    }
    return sqrt(sum);
}

EuclideanVector EuclideanVector::createUnitVector() const{
    std::vector<double> v;
    double en = getEuclideanNorm();
    for (auto i = 0; i < num_dim; ++i) {
        v.push_back(mag_vec[i] / en);
    }
    return EuclideanVector(v.begin(), v.end());
}

//set
double& EuclideanVector::operator[](int index) {
    assert((index >= 0) && (index < num_dim));
    return mag_vec[index];
}

double EuclideanVector::operator[](int index) const {
    assert((index >= 0) && (index < num_dim));
    return mag_vec[index];
}

EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& ev) {
    assert(num_dim == ev.num_dim);
    for (auto i = 0; i < num_dim; ++i) {
        mag_vec[i] += ev.mag_vec[i];
    }
    return *this;
}

EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& ev) {
    assert(num_dim == ev.num_dim);
    for (auto i = 0; i < num_dim; ++i) {
        mag_vec[i] -= ev.mag_vec[i];
    }
    return *this;
}

EuclideanVector& EuclideanVector::operator*=(double d) {
    for (auto i = 0; i < num_dim; ++i) {
        mag_vec[i] *= d;
    }
    return *this;
}

EuclideanVector& EuclideanVector::operator/=(double d) {
    for (auto i = 0; i < num_dim; ++i) {
        mag_vec[i] /= d;
    }
    return *this;
}

EuclideanVector::operator std::vector<double>() const {
    std::vector<double> v;
    for (auto i = 0; i < num_dim; ++i) {
        v.push_back(mag_vec[i]);
    }
    return v;
}

EuclideanVector::operator std::list<double>() const {
    std::list<double> l;
    for (auto i = 0; i < num_dim; ++i) {
        l.push_back(mag_vec[i]);
    }
    return l;
}

bool evec::operator==(const EuclideanVector& ev1, const EuclideanVector& ev2) {
    if (ev1.num_dim != ev2.num_dim) {
        return false;
    }
    for (auto i = 0; i < ev1.num_dim; ++i) {
        if (ev1.mag_vec[i] != ev2.mag_vec[i]) {
            return false;
        }
    }
    return true;
}

bool evec::operator!=(const EuclideanVector& ev1, const EuclideanVector& ev2) {
    return !(ev1 == ev2);
}

EuclideanVector evec::operator+(const EuclideanVector& ev1, const EuclideanVector& ev2) {
    assert(ev1.num_dim == ev2.num_dim);
    std::vector<double> v;
    for (auto i = 0; i < ev1.num_dim; ++i) {
        v.push_back(ev1.mag_vec[i] + ev2.mag_vec[i]);
    }
    return EuclideanVector(v.begin(), v.end());
}

EuclideanVector evec::operator-(const EuclideanVector& ev1, const EuclideanVector& ev2) {
    assert(ev1.num_dim == ev2.num_dim);
    std::vector<double> v;
    for (auto i = 0; i < ev1.num_dim; ++i) {
        v.push_back(ev1.mag_vec[i] - ev2.mag_vec[i]);
    }
    return EuclideanVector(v.begin(), v.end());
}

double evec::operator*(const EuclideanVector& ev1, const EuclideanVector& ev2) {
    assert(ev1.num_dim == ev2.num_dim);
    double result = 0;
    for (auto i = 0; i < ev1.num_dim; ++i) {
        result += ev1.mag_vec[i] * ev2.mag_vec[i];
    }
    return result;
}

EuclideanVector evec::operator*(const EuclideanVector& ev, double d_num) {
    std::vector<double> v;
    for (auto i = 0; i < ev.num_dim; ++i) {
        v.push_back(ev.mag_vec[i] * d_num);
    }
    return EuclideanVector(v.begin(), v.end());
}

EuclideanVector evec::operator*(double d_num, const EuclideanVector& ev) {
    std::vector<double> v;
    for (auto i = 0; i < ev.num_dim; ++i) {
        v.push_back(ev.mag_vec[i] * d_num);
    }
    return EuclideanVector(v.begin(), v.end());
}

EuclideanVector evec::operator/(const EuclideanVector &ev, double d_num) {
    std::vector<double> v;
    for (auto i = 0; i < ev.num_dim; ++i) {
        v.push_back(ev.mag_vec[i] / d_num);
    }
    return EuclideanVector(v.begin(), v.end());
}

std::ostream& evec::operator<<(std::ostream &os, const EuclideanVector &ev) {
    os << "[";
    for (auto i = 0; i < ev.num_dim; ++i) {
        os << ev.mag_vec[i];
        if (i != ev.num_dim - 1)
            os << " ";
    }
    os << "]";
    return os;
}

void EuclideanVector::changefirst() {
    mag_vec[0] = 20;
}
void EuclideanVector::print() {
    for (auto i = 0; i < num_dim; ++i)
        std::cout << mag_vec[i] << " ";
    std::cout << std::endl;
}
