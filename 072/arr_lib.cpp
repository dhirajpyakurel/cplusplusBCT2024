#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Array
{
private:
    vector<T> data;
    int rows;
    int cols;
    bool is_1d;

public:
    Array(int size)
    {
        rows = 1;
        cols = size;
        is_1d = true;
        data.resize(size);
    }

    Array(int r, int c)
    {
        rows = r;
        cols = c;
        is_1d = false;
        data.resize(rows * cols);
    }

    T &operator()(int i)
    {
        return data[i];
    }

    T &operator()(int i, int j)
    {
        return data[i * cols + j];
    }

    void print() const
    {
        if (is_1d)
        {
            for (int i = 0; i < cols; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << data[i * cols + j] << " ";
                }
                cout << endl;
            }
        }
    }

    Array<T> operator+(const Array<T> &x)
    {
        if (rows != x.rows || cols != x.cols)
            throw invalid_argument("dimensions must match!");

        Array<T> result(rows, cols);
        for (int i = 0; i < data.size(); ++i)
        {
            result.data[i] = data[i] + x.data[i];
        }
        return result;
    }

    Array<T> matmul(const Array<T> &x)
    {
        if (cols != x.rows)
            throw invalid_argument("Incompatible dimensions for matrix multiplication!");

        Array<T> result(rows, x.cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < x.cols; ++j)
            {
                for (int k = 0; k < cols; ++k)
                {
                    result(i, j) += data[i * cols + k] * x.data[k * x.cols + j];
                }
            }
        }
        return result;
    }

    Array<T> arrmul(const Array<T> &x)
    {
        if (rows != x.rows || cols != x.cols)
            throw invalid_argument("dimensions must match!");

        Array<T> result(rows, cols);
        for (int i = 0; i < data.size(); ++i)
        {
            result.data[i] = data[i] * x.data[i];
        }
        return result;
    }

    Array<T> operator*(const T &scalar)
    {
        Array<T> result(rows, cols);
        for (int i = 0; i < data.size(); ++i)
        {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }
};

int main()
{

    int choice;
    do
    {
        cout << "\n\narray library\n\n"
             << "1. Array addition\n"
             << "2. Array scalar multiplication\n"
             << "3. Array multiplication\n"
             << "4. Matrix addition\n"
             << "5. Matrix scalar multiplication\n"
             << "6. Matrix multiplication\n"
             << "7. Exit\n\n"
             << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            int size;
            cout << "Enter size of array: ";
            cin >> size;
            Array<int> arr_a(size);
            Array<int> arr_b(size);
            Array<int> arr_c(size);

            cout << "\nEnter array 1:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr_a(i);
            }

            cout << "\nEnter array 2:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr_b(i);
            }
            arr_c = arr_a + arr_b;

            cout << "\nResult = ";
            arr_c.print();

            cout << endl;
            break;
        }
        case 2:
        {
            int size, mul;
            cout << "Enter size of array: ";
            cin >> size;

            Array<int> arr_a(size);
            Array<int> arr_b(size);

            cout << "\nEnter array:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr_a(i);
            }

            cout << "Enter multiplier: ";
            cin >> mul;

            arr_b = arr_a * mul;
            cout << "\nResult = ";
            arr_b.print();

            cout << endl;
            break;
        }
        case 3:
        {
            int size;
            cout << "Enter size of array: ";
            cin >> size;
            Array<int> arr_a(size);
            Array<int> arr_b(size);
            Array<int> arr_c(size);

            cout << "\nEnter array 1:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr_a(i);
            }

            cout << "\nEnter array 2:\n";
            for (int i = 0; i < size; i++)
            {
                cin >> arr_b(i);
            }
            arr_c = arr_a.arrmul(arr_b);

            cout << "\nResult = ";
            arr_c.print();

            cout << endl;
            break;
        }
        case 4:
        {
            int rows, cols;
            cout << "Enter no of rows: ";
            cin >> rows;
            cout << "Enter no of cols: ";
            cin >> cols;

            Array<int> arr_a(rows, cols);
            Array<int> arr_b(rows, cols);
            Array<int> arr_c(rows, cols);

            cout << "Enter matrix 1:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> arr_a(i, j);
                }
            }

            cout << "Enter matrix 2:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> arr_b(i, j);
                }
            }

            arr_c = arr_a + arr_b;

            cout << "\nResult = ";
            arr_c.print();

            cout << endl;
            break;
        }
        case 5:
        {
            int rows, cols, mul;
            cout << "Enter no of rows: ";
            cin >> rows;
            cout << "Enter no of cols: ";
            cin >> cols;

            Array<int> arr_a(rows, cols);
            Array<int> arr_b(rows, cols);

            cout << "\nEnter matrix:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> arr_a(i, j);
                }
            }

            cout << "\nEnter multiplier: ";
            cin >> mul;

            arr_b = arr_a * mul;

            cout << "\nResult = ";
            arr_b.print();

            cout << endl;
            break;
        }
        case 6:
        {
            int rows, cols;
            cout << "Enter no of rows: ";
            cin >> rows;
            cout << "Enter no of cols: ";
            cin >> cols;

            Array<int> arr_a(rows, cols);
            Array<int> arr_b(rows, cols);
            Array<int> arr_c(rows, cols);

            cout << "\nEnter matrix 1:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> arr_a(i, j);
                }
            }

            cout << "\nEnter matrix 2:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> arr_b(i, j);
                }
            }

            arr_c = arr_a.matmul(arr_b);

            cout << "\nResult = ";
            arr_c.print();

            cout << endl;
            break;
        }
        default:
            break;
        }
    } while (choice != 7);

    return 0;
}