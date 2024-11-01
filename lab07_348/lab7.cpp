#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }

};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    ifstream file(file_name); //use fstream to access the file
    if (!file) { //error check the files access
        cout << "Bad file type: " << file_name << endl; //prints if the file is bad
        return;
    }

    int size;
    file >> size;
    matrix_1 = Matrix(size); //sets the class object data to matrix_1 and matrix_2 to for 
    matrix_2 = Matrix(size); 

    for (int i = 0; i < size; ++i) //loops rows
        for (int j = 0; j < size; ++j) //loops column nums
            file >> matrix_1.matrix_data[i][j]; // extracts data from file
    //repeats for matrix 2
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> matrix_2.matrix_data[i][j];
}

void print_matrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.matrix_size; ++i) { //loops rows
        for (int j = 0; j < matrix.matrix_size; ++j) { //loops for column num
            cout << matrix.matrix_data[i][j] << " "; //prints the number for the index 
        }
        cout << endl;
    }
    cout << endl;
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    for (int i = 0; i < matrix_1.matrix_size; ++i) { //loops through the first matrix rows
        for (int j = 0; j < matrix_1.matrix_size; ++j) { //loops through the columns
            cout << matrix_1.matrix_data[i][j] << " "; //prints every num in the row and so on...
        }
        cout << "\t"; //tab for space between the matrices and repeats for matrix 2
        for (int j = 0; j < matrix_2.matrix_size; ++j) { 
            cout << matrix_2.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix result(matrix_1.matrix_size); 
    for (int i = 0; i < matrix_1.matrix_size; ++i) { //loops through the first matrix row
        for (int j = 0; j < matrix_1.matrix_size; ++j) { // loops through that rows column
            result.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j]; // adds the index of matrix 1 and 2 together
        }
    }
    return result;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix result(matrix_1.matrix_size); 
    for (int i = 0; i < matrix_1.matrix_size; ++i) { //loops through the matrix rows
        for (int j = 0; j < matrix_1.matrix_size; ++j) { //again for columns
            result.matrix_data[i][j] = 0; //sets at 0 to for matrix multiplication
            for (int k = 0; k < matrix_1.matrix_size; ++k) { //loops through matrix 1
                result.matrix_data[i][j] += matrix_1.matrix_data[i][k] * matrix_2.matrix_data[k][j]; //multiplies the 2 matrixes and add/assigns
            }
        }
    }
    return result;
}

Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) {
    return add_matrices(matrix_1, matrix_2);
}

Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {
    return multiply_matrices(matrix_1, matrix_2);
}

void get_diagonal_sum(const Matrix& matrix) {
    int sum = 0; //initialize at 0
    for (int i = 0; i < matrix.matrix_size; ++i) { //loop through the matrix size
        sum += matrix.matrix_data[i][i]; //gets the diagonal value same row and col num and adds to sum
    }
    cout << sum << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    if (row1 >= matrix.matrix_size || row2 >= matrix.matrix_size || row1 < 0 || row2 < 0) { //error check
        cout << "Cannot compute swap" << endl;
        return;
    }
    for (int i = 0; i < matrix.matrix_size; ++i) { //loops through the matrix
        swap(matrix.matrix_data[row1][i], matrix.matrix_data[row2][i]);//uses swap function to switch the values 
    }
}

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "Matrices : " << endl;
    print_matrix(matrix_1, matrix_2);

    cout << "\nAdded matrix: " << endl;
    Matrix add_result = add_matrices(matrix_1, matrix_2);
    print_matrix(add_result);


    cout << "\nmultiplied matrix:" << endl;
    Matrix multiply_result = multiply_matrices(matrix_1, matrix_2);
    print_matrix(multiply_result);

    cout << "\nmatrix diagonal sum: " << endl;
    get_diagonal_sum(matrix_1);

    cout << "\nswap matrix rows: " << endl;
    swap_matrix_row(matrix_1, 0, 1);
    print_matrix(matrix_1);

    return 0;
}
