#include <cstring>
#include "iostream"
#include "logics.hpp"
#include "logics.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Matrix m1 = Matrix(0);
    int maxThreads =thread::hardware_concurrency();
    int threads = maxThreads;
    if (argc==1){
        throw std::runtime_error("No arguments were given.");
    }
    if (argc>4){
        throw std::runtime_error("Too many arguments were given.");
    }
    for(int i=1;i<argc;i++) {
        if (!strcmp(argv[i],"--help")) {
            utils::printHelp();
            return 0;
        }
        else if (!strcmp(argv[i],"-input")) {
            m1 = utils::getMatrixFromFile(argv[i+1]);
            if (m1.getDimensions()==0){
                throw std::runtime_error("Error in input data");
            }
            i++;
        }
        else if (!strcmp(argv[i],"-random")) {
            m1 = Matrix(std::stoi(argv[i+1]));
            if (m1.getDimensions()==0){
                throw std::runtime_error("Cannot create matrix with this dimension");
            }
            i++;
        }
        else if (!strcmp(argv[i],"-measure")&&argc==3) {
            int dim =std::stoi(argv[i+1]);
            if (dim==0){
                throw std::runtime_error("Cannot create matrix with this dimension");
            }
            utils::measure(dim);
            return 0;
        } else if (!strcmp(argv[i],"-singlethread")){
            threads =1;
        }
        else if (!strcmp(argv[i],"-twothreads")){
            if (maxThreads<2){
                throw std::runtime_error("Too much threads for this machine, maximum number of threads for this machine is: " + to_string(maxThreads));
            }
            threads = 2;
        } else if (!strcmp(argv[i],"-fourthreads")){
            if (maxThreads<4){
                throw std::runtime_error("Too much threads for this machine, maximum number of threads for this machine is: " + to_string(maxThreads));
            }
            threads = 4;
        } else if (!strcmp(argv[i],"-eightthreads")){
            if (maxThreads<8){
                throw std::runtime_error("Too much threads for this machine, maximum number of threads for this machine is: " + to_string(maxThreads));
            }
            threads = 8;
        } else if (!strcmp(argv[i],"-tenthreads")){
            if (maxThreads<10){
                throw std::runtime_error("Too much threads for this machine, maximum number of threads for this machine is: " + to_string(maxThreads));
            }
            threads = 10;
        }
        else {
            throw std::runtime_error("Wrong argument");
        }
    }
    if (m1.getDimensions()==0){
        throw std::runtime_error("Missing matrix \n");
    }
    if (threads>10) threads =10;
    switch(threads){
        case 1: {
            auto start = chrono::high_resolution_clock::now();
            double result = m1.determinant();
            auto end = chrono::high_resolution_clock::now();
            cout <<"Determinat of the matrix is: " << result << std::endl;
            cout << "Needed " << to_ms(end - start).count() << " ms to finish using single thread.\n";
            break;
        }
        case 2:
        case 3:{
            auto start = chrono::high_resolution_clock::now();
            double result = m1.threadsTwoDeterminant();
            auto end = chrono::high_resolution_clock::now();
            cout <<"Determinat of the matrix is: " << result << std::endl;
            cout << "Needed " << to_ms(end - start).count() << " ms to finish using two threads.\n";
            break;
        }
        case 4:
        case 5:
        case 6:
        case 7:{
            auto start = chrono::high_resolution_clock::now();
            double result = m1.threadsFourDeterminant();
            auto end = chrono::high_resolution_clock::now();
            cout <<"Determinat of the matrix is: " << result << std::endl;
            cout << "Needed " << to_ms(end - start).count() << " ms to finish using four threads.\n";
            break;
        }
        case 8:
        case 9:{
            auto start = chrono::high_resolution_clock::now();
            double result = m1.threadsEightDeterminant();
            auto end = chrono::high_resolution_clock::now();
            cout <<"Determinat of the matrix is: " << result << std::endl;
            cout << "Needed " << to_ms(end - start).count() << " ms to finish using eight threads.\n";
            break;
        }
        case 10: {
            auto start = chrono::high_resolution_clock::now();
            double result = m1.threadsTenDeterminant();
            auto end = chrono::high_resolution_clock::now();
            cout <<"Determinat of the matrix is: " << result << std::endl;
            cout << "Needed " << to_ms(end - start).count() << " ms to finish using ten threads.\n";
            break;
        }
        default:{
        }
    }
    return 0;
}
