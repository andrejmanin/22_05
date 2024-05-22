#include <iostream>
#include <ctime>

using namespace std;

void task_1() {
    srand(time(0));

    const int cols = 1000;
    const int rows = 1000;
    int matrix[cols][rows];
    int current_cols = 0, current_rows = 0;
    do {
        cout << "Enter a number of columns: ";
        cin >> current_cols;
        cout << "Enter a number of rows: ";
        cin >> current_rows;
        if (current_cols < 0 || current_cols > cols || current_rows < 0 || current_rows > rows) {
            cout << "Error: invalid number of columns or rows" << endl;
        }
    }while (current_cols < 0 || current_cols > cols || current_rows < 0 || current_rows > rows);

    int sum = 0, min = 0, max = 0;
    for(int i = 0; i < current_cols; i++) {
        for(int j = 0; j < current_rows; j++) {
            matrix[i][j] = rand() % 10;
            sum += matrix[i][j];
            if (i == 0 && j == 0) {
                min = matrix[i][j];
                max = matrix[i][j];
            }
            else {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }
    }



    for(int i = 0; i < current_cols; i++) {
        for(int j = 0; j < current_rows; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << sum / (current_cols * current_rows) << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

void task_2() {
    srand(time(0));
    const int size = 1000;
    int cols, rows;
    cout << "Enter a number of columns: ";
    cin >> cols;
    cout << "Enter a number of rows: ";
    cin >> rows;
    // rows += 1;
    // cols += 1;
    // int** matrix = new int* [cols + 1];
    // for (int i = 0; i < cols; i++) {
    //     matrix[i] = new int[rows + 1];
    // }
    int matrix[size][size];
    int sum_rows = 0, sum_cols = 0;
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            matrix[i][j] = rand() % 10;
            sum_rows += matrix[i][j];
            if(j == rows - 1) {
                matrix[i][j + 1] = sum_rows;
                sum_rows = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            sum_cols += matrix[j][i];
            if(j == cols - 1) {
                matrix[j + 1][i] = sum_cols;
                sum_cols = 0;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < cols; i++) {
        sum += matrix[i][rows];
    }
    for(int i = 0; i < rows; i++) {
        sum += matrix[cols][i];
    }
    matrix[cols][rows] = sum;

    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows + 1; j++) {
            if(j == rows) {
                cout << "| " << matrix[i][j];
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < rows + 2; i++) {
        cout << "- ";
    }
    cout << endl;
    for(int i = 0; i < rows + 1; i++) {
        if(i == rows) {
            cout << "| " << matrix[cols][i] << endl;
        }
        else {
            cout << matrix[cols][i] << " ";
        }
    }

}

void task_3() {
    srand(time(0));

    const int size_1 = 5;
    const int size_2 = 10;
    int matrix_1[size_1][size_2], matrix_2[size_1][size_1];

    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_2; j++) {
            matrix_1[i][j] = rand() % 50;
        }
    }
    for(int i = 0; i < size_1; i++) {
        int k = 0;
        for(int j = 0; j < size_1; j++) {
            matrix_2[i][j] = matrix_1[i][k] + matrix_1[i][k + 1];
            k += 2;
        }
    }

    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_2; j++) {
            cout << matrix_1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_1; j++) {
            cout << matrix_2[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    task_3();

    return 0;
}
