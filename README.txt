Requirement detail see "CS6771 Assignment Two 2017.pdf"

Write a Euclidean Vector Class Library in C++, with its interface given in EuclideanVector.h and its implementation in EuclideanVector.cpp. For assessment purposes, your EuclideanVector.cpp will be compiled with a series of assessment test cases that #include your EuclideanVector.h. 

Euclidean Vectors are commonly used in physics to represent directed quantities. Your Euclidean Vector class should be dimension-agnostic, that is, it should be able to be constructed and operate on data of arbitrary dimensionality. The magnitude in each dimension will always be a double. For example:

evec::EuclideanVector a(1); 	   // a Euclidean Vector in 1 dimension, with default magnitude 0.0.
evec::EuclideanVector b(2,4.0);    // a Euclidean Vector in 2 dimensions with magnitude 4.0 in both dimensions

std::list<double> l;
l.push_back(5.0);
l.push_back(6.5);
l.push_back(7.0);
evec::EuclideanVector c(l.begin(),l.end());	// a Euclidean Vector in 3 dimensions constructed from a list of magnitudes