# CxxTestTest
[CxxTest](http://cxxtest.com/)

Generate tests with

    cxxtestgen --error-printer basketTest.hpp vector2Test.hpp -o ./testRunner.cpp
    
and compile the output with your favorite c++14 compliant compiler (such as modern versions of clang++ or g++)

    clang++ --std=c++14 ./testRunner.cpp -o testRunner
    
and run

    ./testRunner
    
