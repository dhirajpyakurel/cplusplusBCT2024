#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // For system()

using namespace std;

#ifdef _WIN32
#define CLEAR_SCREEN() system("cls") // For Windows
#else
#define CLEAR_SCREEN() system("clear") // For Linux/Unix
#endif

const int MAX_SIZE = 6;

class SquareMatrix
{
public:
    int size;
    double data[MAX_SIZE][MAX_SIZE];

    SquareMatrix(int s) : size(s) {}

    void input()
    {
        cout << "Enter elements for the " << size << "x" << size << " matrix:" << endl;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void print()
    {
        cout << "+--------------------------+" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "| ";
            for (int j = 0; j < size; ++j)
            {
                cout << setw(6) << data[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "+--------------------------+" << endl;
    }

    SquareMatrix add(const SquareMatrix &other)
    {
        SquareMatrix result(size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    SquareMatrix subtract(const SquareMatrix &other)
    {
        SquareMatrix result(size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    SquareMatrix multiply(const SquareMatrix &other)
    {
        SquareMatrix result(size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    double determinant()
    {
        if (size == 1)
            return data[0][0];

        if (size == 2)
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];

        double det = 0;
        for (int p = 0; p < size; p++)
        {
            SquareMatrix subMatrix(size - 1);
            for (int i = 1; i < size; i++)
            {
                int subCol = 0;
                for (int j = 0; j < size; j++)
                {
                    if (j == p)
                        continue;
                    subMatrix.data[i - 1][subCol++] = data[i][j];
                }
            }
            det += (p % 2 == 0 ? 1 : -1) * data[0][p] * subMatrix.determinant();
        }
        return det;
    }
    SquareMatrix transpose()
    {
        SquareMatrix result(size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

class RectangularMatrix
{
public:
    int rows, cols;
    double data[MAX_SIZE][MAX_SIZE];

    RectangularMatrix(int r, int c) : rows(r), cols(c) {}

    void input()
    {
        cout << "Enter elements for the " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void print()
    {
        cout << "+--------------------------+" << endl;
        for (int i = 0; i < rows; ++i)
        {
            cout << "| ";
            for (int j = 0; j < cols; ++j)
            {
                cout << setw(6) << data[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "+--------------------------+" << endl;
    }

    RectangularMatrix add(const RectangularMatrix &other)
    {
        RectangularMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    RectangularMatrix subtract(const RectangularMatrix &other)
    {
        RectangularMatrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    RectangularMatrix multiply(const RectangularMatrix &other)
    {
        RectangularMatrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    RectangularMatrix transpose()
    {
        RectangularMatrix result(cols, rows); // Note the swapped dimensions
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

void displayMenu()
{
    CLEAR_SCREEN();
    cout << "+------------------------------+" << endl;
    cout << "|       Matrix Calculator       |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1. Create Square Matrix      |" << endl;
    cout << "| 2. Create Rectangular Matrix  |" << endl;
    cout << "| 3. Exit                      |" << endl;
    cout << "+------------------------------+" << endl;
}

void waitForEnter()
{
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

int main()
{
    int choice;
    SquareMatrix *currentSquareMatrix = nullptr;
    RectangularMatrix *currentRectangularMatrix = nullptr;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            CLEAR_SCREEN();
            int size;
            cout << "Enter the size of the square matrix: ";
            cin >> size;
            currentSquareMatrix = new SquareMatrix(size);
            currentSquareMatrix->input();
            cout << "Square Matrix created." << endl;

            int operation;
            do
            {
                CLEAR_SCREEN();
                cout << "+------------------------------+" << endl;
                cout << "| Options for Square Matrix    |" << endl;
                cout << "+------------------------------+" << endl;
                cout << "| 1. Display Matrix            |" << endl;
                cout << "| 2. Add another matrix        |" << endl;
                cout << "| 3. Subtract another matrix   |" << endl;
                cout << "| 4. Multiply by another matrix |" << endl;
                cout << "| 5. Transpose                 |" << endl;
                cout << "| 6. Determinant              |" << endl;
                cout << "| 7. Return to main menu      |" << endl;
                cout << "+------------------------------+" << endl;
                cout << "Enter your choice: ";
                cin >> operation;

                switch (operation)
                {
                case 1:
                    CLEAR_SCREEN();
                    cout << "Current Matrix:" << endl;
                    currentSquareMatrix->print();
                    waitForEnter();
                    break;
                case 2:
                {
                    CLEAR_SCREEN();
                    SquareMatrix matrix2(size);
                    matrix2.input();
                    SquareMatrix result = currentSquareMatrix->add(matrix2);
                    cout << "Result of Addition:" << endl;
                    result.print();
                    waitForEnter();
                    break;
                }
                case 3:
                {
                    CLEAR_SCREEN();
                    SquareMatrix matrix2(size);
                    matrix2.input();
                    SquareMatrix result = currentSquareMatrix->subtract(matrix2);
                    cout << "Result of Substraction:" << endl;
                    result.print();
                    waitForEnter();
                    break;
                }
                case 4:
                {
                    CLEAR_SCREEN();
                    SquareMatrix matrix2(size);
                    matrix2.input();
                    SquareMatrix result = currentSquareMatrix->multiply(matrix2);
                    cout << "Result of Multiplication" << endl;
                    result.print();
                    waitForEnter();
                    break;
                }
                case 5:
                {
                    CLEAR_SCREEN();
                    SquareMatrix transposedMatrix = currentSquareMatrix->transpose();
                    cout << "Transposed Matrix:" << endl;
                    transposedMatrix.print();
                    waitForEnter();
                    break;
                }
                case 6:
                {
                    CLEAR_SCREEN();
                    double det = currentSquareMatrix->determinant();
                    cout << "Determinant: " << det << endl;
                    waitForEnter();
                    break;
                }
                case 7:
                    break;
                default:
                    cout << "Invalid choice." << endl;
                }
            } while (operation != 7);
            delete currentSquareMatrix;
            break;
        }
        case 2:
        {
            CLEAR_SCREEN();
            int rows, cols;
            cout << "Enter rows: ";
            cin >> rows;
            cout << "Enter columns: ";
            cin >> cols;
            currentRectangularMatrix = new RectangularMatrix(rows, cols);
            currentRectangularMatrix->input();
            cout << "Rectangular Matrix created." << endl;

            int operation;
            do
            {
                CLEAR_SCREEN();
                cout << "+------------------------------+" << endl;
                cout << "| Options for Rectangular Matrix|" << endl;
                cout << "+------------------------------+" << endl;
                cout << "| 1. Display Matrix            |" << endl;
                cout << "| 2. Add another matrix        |" << endl;
                cout << "| 3. Subtract another matrix   |" << endl;
                cout << "| 4. Multiply by another matrix |" << endl;
                cout << "| 5. Transpose                 |" << endl;
                cout << "| 6. Return to main menu      |" << endl;
                cout << "+------------------------------+" << endl;
                cout << "Enter your choice: ";
                cin >> operation;

                switch (operation)
                {
                case 1:
                    CLEAR_SCREEN();
                    cout << "Current Matrix:" << endl;
                    currentRectangularMatrix->print();
                    waitForEnter();
                    break;
                case 2:
                {
                    CLEAR_SCREEN();
                    RectangularMatrix matrix2(rows, cols);
                    matrix2.input();
                    RectangularMatrix result = currentRectangularMatrix->add(matrix2);
                    cout << "Result of Addition:" << endl;
                    result.print();
                    waitForEnter();
                    break;
                }
                case 3:
                {
                    CLEAR_SCREEN();
                    RectangularMatrix matrix2(rows, cols);
                    matrix2.input();
                    RectangularMatrix result = currentRectangularMatrix->subtract(matrix2);
                    cout << "Result of subtract:" << endl;
                    result.print();
                    waitForEnter();
                    break;
                }

                case 4:
                {
                    CLEAR_SCREEN();
                    int rows, cols;
                    cout << "+---------------------------------+" << endl;
                    cout << "|      Enter dimensions for       |" << endl;
                    cout << "|    the second matrix (rows x columns): |" << endl;
                    cout << "+---------------------------------+" << endl;
                    cout << "Enter rows: ";
                    cin >> rows;
                    cout << "Enter columns: ";
                    cin >> cols;

                    if (currentRectangularMatrix->cols != rows)
                    {
                        cout << "Matrix sizes are incompatible for multiplication." << endl;
                    }
                    else
                    {
                        RectangularMatrix matrix2(rows, cols);
                        matrix2.input();
                        RectangularMatrix result = currentRectangularMatrix->multiply(matrix2);
                        cout << "Result of Multiplication:" << endl;
                        result.print();
                    }
                    waitForEnter();
                    break;
                }
                case 5:
                {
                    CLEAR_SCREEN();
                    RectangularMatrix transposedMatrix = currentRectangularMatrix->transpose();
                    cout << "Transposed Matrix:" << endl;
                    transposedMatrix.print();
                    waitForEnter();
                    break;
                }
                case 6:
                    break;
                default:
                    cout << "Invalid choice." << endl;
                }
            } while (operation != 6);
            delete currentRectangularMatrix;
            break;
        }
        case 3:
            CLEAR_SCREEN();
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
