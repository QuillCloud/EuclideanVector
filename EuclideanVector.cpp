//
// Created by Yunhe Zhang on 19/08/2017.
//

#include "EuclideanVector.h"


int evec::EuclideanVector::get() const {
    return this->num_dim;
}
void evec::EuclideanVector::changefirst() {
    mag_vec[0] = 20;
}
void evec::EuclideanVector::print() {
    for (auto i = 0; i < num_dim; ++i)
        std::cout << mag_vec[i] << " ";
    std::cout << std::endl;
}