#include <thread>
#include "logics.hpp"


double Matrix::determinant() {
    std::vector<std::vector<double>> origin = rows;
    double determinant = 1;
    for (int i=0; i<rows.size();i++){
        auto currRow = rows[i];
        determinant*=currRow.at(i);
        int j=i+1;
        for (j;j<rows.size();j++){
            double multiplier = rows.at(j).at(i)/currRow.at(i);
            multiplier*=-1;
            for (int k=0; k<rows.at(j).size(); k++){
                rows.at(j).at(k)+=currRow.at(k)*multiplier;
            }
        }
    }
    return determinant;
}

double Matrix::threadsTwoDeterminant() {
    std::vector<std::vector<double>> origin = rows;
    double determinant = 1;
    for (int i=0; i<rows.size();i++) {
        auto currRow = rows[i];
        determinant *= currRow.at(i);
        if (i==rows.size()) break;
        int j = i + 1;
        int k = (dimensions-i)/2;
        if ((rows.size() - i-1) > 1) {
            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, j+k-1);
            std::thread t2 = std::thread(&Matrix::calcRows, this, i, j+k, dimensions - 1);
            t1.join();
            t2.join();
        }
        else if (j!=rows.size()) calcRow(i,j);
    }
    return determinant;
}

double Matrix::threadsFourDeterminant() {
    std::vector<std::vector<double>> origin = rows;
    double determinant = 1;
//    std::cout << "\n";
//    std::cout << "\n";
    for (int i=0; i<rows.size();i++) {
//        std::cout << i << "\n";
        auto currRow = rows[i];
        determinant *= currRow.at(i);
        if (i==rows.size()) break;
        int j = i + 1;
        int k = (dimensions-i)/4;
        if ((rows.size() - i-1) > 16) {
            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, j+k-1);
            std::thread t2 = std::thread(&Matrix::calcRows, this, i, j+k, j+2*k-1);
            std::thread t3 = std::thread(&Matrix::calcRows, this, i, j+2*k, j+3*k-1);
            std::thread t4 = std::thread(&Matrix::calcRows, this, i, j+3*k, dimensions - 1);
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        }
        else if (j!=rows.size()) {
            for (j;j<rows.size();j++)
            calcRow(i,j);
        }
//        for (j;j<rows.size();j++) {
//            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, dimensions-1);
//            t1.join();
//        }
//        for (std::vector<double> v : rows){
//            for (double d : v) std::cout << d << " ";
//            std::cout << "\n";
//        }
//        std::cout << "\n";
    }
    return determinant;
}

double Matrix::threadsEightDeterminant() {
    std::vector<std::vector<double>> origin = rows;
    double determinant = 1;
//    std::cout << "\n";
//    std::cout << "\n";
    for (int i=0; i<rows.size();i++) {
//        std::cout << i << "\n";
        auto currRow = rows[i];
        determinant *= currRow.at(i);
        if (i==rows.size()) break;
        int j = i + 1;
        int k = (dimensions-i)/8;
        if ((rows.size() - i-1) > 24) {
            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, j+k-1);
            std::thread t2 = std::thread(&Matrix::calcRows, this, i, j+k, j+2*k-1);
            std::thread t3 = std::thread(&Matrix::calcRows, this, i, j+2*k, j+3*k-1);
            std::thread t4 = std::thread(&Matrix::calcRows, this, i, j+3*k, j+4*k-1);
            std::thread t5 = std::thread(&Matrix::calcRows, this, i, j+4*k, j+5*k-1);
            std::thread t6 = std::thread(&Matrix::calcRows, this, i, j+5*k, j+6*k-1);
            std::thread t7 = std::thread(&Matrix::calcRows, this, i, j+6*k, j+7*k-1);
            std::thread t8 = std::thread(&Matrix::calcRows, this, i, j+7*k, dimensions-1);
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
            t6.join();
            t7.join();
            t8.join();
        }
        else if (j!=rows.size()) {
            for (j;j<rows.size();j++)
                calcRow(i,j);
        }
//        for (j;j<rows.size();j++) {
//            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, dimensions-1);
//            t1.join();
//        }
//        for (std::vector<double> v : rows){
//            for (double d : v) std::cout << d << " ";
//            std::cout << "\n";
//        }
//        std::cout << "\n";
    }
    return determinant;
}

double Matrix::threadsTenDeterminant() {
    std::vector<std::vector<double>> origin = rows;
    double determinant = 1;
//    std::cout << "\n";
//    std::cout << "\n";
    for (int i=0; i<rows.size();i++) {
//        std::cout << i << "\n";
        auto currRow = rows[i];
        determinant *= currRow.at(i);
        if (i==rows.size()) break;
        int j = i + 1;
        int k = (dimensions-i)/10;
        if ((rows.size() - i-1) > 40) {
            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, j+k-1);
            std::thread t2 = std::thread(&Matrix::calcRows, this, i, j+k, j+2*k-1);
            std::thread t3 = std::thread(&Matrix::calcRows, this, i, j+2*k, j+3*k-1);
            std::thread t4 = std::thread(&Matrix::calcRows, this, i, j+3*k, j+4*k-1);
            std::thread t5 = std::thread(&Matrix::calcRows, this, i, j+4*k, j+5*k-1);
            std::thread t6 = std::thread(&Matrix::calcRows, this, i, j+5*k, j+6*k-1);
            std::thread t7 = std::thread(&Matrix::calcRows, this, i, j+6*k, j+7*k-1);
            std::thread t8 = std::thread(&Matrix::calcRows, this, i, j+7*k, j+8*k-1);
            std::thread t9 = std::thread(&Matrix::calcRows, this, i, j+8*k, j+9*k-1);
            std::thread t10 = std::thread(&Matrix::calcRows, this, i, j+9*k, dimensions-1);
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
            t6.join();
            t7.join();
            t8.join();
            t9.join();
            t10.join();
        }
        else if (j!=rows.size()) {
            for (j;j<rows.size();j++)
                calcRow(i,j);
        }
//        for (j;j<rows.size();j++) {
//            std::thread t1 = std::thread(&Matrix::calcRows, this, i, j, dimensions-1);
//            t1.join();
//        }
//        for (std::vector<double> v : rows){
//            for (double d : v) std::cout << d << " ";
//            std::cout << "\n";
//        }
//        std::cout << "\n";
    }
    return determinant;
}

void Matrix::calcRows(int i, int j,int k) {
    for (int a=j;a<=k;a++){
        calcRow(i,a);
    }
}
void Matrix::calcRow(int i, int j) {
    auto currRow = rows.at(i);
    double multiplier = rows.at(j).at(i)/currRow.at(i);
    multiplier*=-1;
    for (int k=0; k<rows.at(j).size(); k++){
        rows.at(j).at(k)+=currRow.at(k)*multiplier;
    }
}
int Matrix::getDimensions() const {
    return dimensions;
}

void Matrix::setDimensions(int dimensions) {
    Matrix::dimensions = dimensions;
}

const std::vector<std::vector<double>> &Matrix::getRows() const{
    return rows;
}

void Matrix::setRows(const std::vector<std::vector<double>> &rows) {
    Matrix::rows = rows;
}

Matrix::Matrix(int dims){
    dimensions = dims;
    for (int i = 0; i<dims; i++){
        std::vector<double> row;
        for (int j = 0; j<dims; j++){
            row.push_back(get_random_double());
        }
        rows.push_back(row);
    }
}
Matrix::Matrix(std::vector<std::vector<double>> rows) {
    dimensions= rows.size();
    this->rows = rows;
}


Matrix utils::getMatrixFromFile(std::string fileName) {
    std::ifstream file;
    file.open("../"+fileName);
    std::vector<std::vector<double>> rows;
    std::string line;
    bool error = false;
    while (std::getline(file,line)){
        std::vector<double> row;
        while (!line.empty()) {
            int spaceIndex = line.find(' ');
            if (spaceIndex==-1) spaceIndex = line.size()-1;
            std::string number = line.substr(0, spaceIndex);
            if (utils::isNumber(number)) {
                row.push_back(std::stod(number));
                line.erase(0, spaceIndex + 1);
            } else {
                error= true;
                break;
            }
        }
        rows.push_back(row);
    }
    if (error||rows.size()!=rows.at(0).size()){
        return Matrix(0);
    }
    return Matrix(rows);
}

void utils::printHelp() {
    std::cout << "Usage: " << std::endl;
    std::cout << "--help  - to print this help" << std::endl;
    std::cout << "-random [number of rows]  - to create random matrix" << std::endl;
    std::cout << "-input [name of file]  - to create matrix from file, file must be in folder with source code" << std::endl;
    std::cout << "-measure [number of rows]  - to start measuring speed of all versions" << std::endl;
    std::cout << "!!WARNING!! MAKE SURE YOUR COMPUTER CAN HANDLE UP TO 10 THREADS WHEN USING '-measure'!!" << std::endl;
    std::cout << "-singlethread  - to calculate matrix determinant using single thread" << std::endl;
    std::cout << "-twothreads  - to calculate matrix determinant using two threads" << std::endl;
    std::cout << "-fourthreads  - to calculate matrix determinant using four threads" << std::endl;
    std::cout << "-eightthreads  - to calculate matrix determinant using eight threads" << std::endl;
    std::cout << "-tenthreads  - to calculate matrix determinant using ten threads" << std::endl;
    std::cout << "example: '-random 1000 -fourthreads'  - creates random matrix with 1000 rows and uses four threads for determinant" << std::endl;
}

bool utils::isNumber(std::string number) {
    int dots=0;
    for(char c : number){
        if (!std::isdigit(c)){
            if (c==46&&number.find(46)!=0&&number.find(46)!=number.size()-1){
                dots++;
            }
            else return false;
        }
    }
    return dots==0||dots==1;
}
void utils::measure(int dim){
    Matrix m1 = Matrix(dim);
    Matrix m2 = m1;
    Matrix m3 = m1;
    Matrix m4 = m1;
    Matrix m5 = m1;
    std::cout << dim << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto result = m1.determinant();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish with one thread.\n";
    start = std::chrono::high_resolution_clock::now();
    result = m5.threadsTwoDeterminant();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish with two threads.\n";
    start = std::chrono::high_resolution_clock::now();
    result = m2.threadsFourDeterminant();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish with four threads.\n";
    start = std::chrono::high_resolution_clock::now();
    result = m3.threadsEightDeterminant();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish with eight threads.\n";
    start = std::chrono::high_resolution_clock::now();
    result = m4.threadsTenDeterminant();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Needed " << to_ms(end - start).count() << " ms to finish with ten threads.\n";
}


