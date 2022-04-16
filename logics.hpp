#pragma once
#include <random>
#include<iostream>
#include <ctime>
#include<cstdlib>
#include <chrono>
#include <fstream>


class Matrix {
public:
    Matrix(int dims);

    Matrix(std::vector<std::vector<double>> rows);

    double determinant();
    double threadsTwoDeterminant();
    double threadsFourDeterminant();
    double threadsEightDeterminant();
    double threadsTenDeterminant();
    void calcRows(int i, int j,int k);
    void calcRow(int i, int j);

    int getDimensions() const;

    void setDimensions(int dimensions);

    const std::vector<std::vector<double>> &getRows() const;

    void setRows(const std::vector<std::vector<double>> &rows);


private:
    int dimensions;

    std::vector<std::vector<double>> rows;

    double get_random_double() {
        static std::mt19937 mt{std::random_device{}()};
        static std::uniform_real_distribution<> dist(-10, 10);
        return dist(mt);
    }

};
namespace utils {
    Matrix getMatrixFromFile(std::string fileName);
    void printHelp();

    bool isNumber(std::string number);

    void measure(int dim);
}
template<typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}