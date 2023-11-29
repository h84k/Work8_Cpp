#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <locale>
#include <cstdlib>
#include <ctime>
#include "windows.h"
using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int menu()
{
    cout << "Choose one of the menu items:" << endl;
    cout << "1. Default values from the task" << endl;
    cout << "2. Enter your own values" << endl;
    cout << "3. Fill with random numbers" << endl;
    cout << "0. Exit!" << endl << endl;
    cout << "Your choice: ";
    char opt;
    cin >> opt;
    return opt;
}

void task(double* A_arr, unsigned int size, double c, double d)
{
    unsigned int zIndex = 0;
    int count = 0;
    double product = 1;
    double* Z_arr = nullptr;

    for (int i = 0; i < size; i++) {
        if (A_arr[i] >= c && A_arr[i] < d) {
            product *= A_arr[i];
            count++;
        }
    }
    if (count == 0)
    {
        product = 0;
    }
    Z_arr = new double[count];

    for (int i = 0; i < size; i++) {
        if (A_arr[i] >= c && A_arr[i] < d) {
            Z_arr[zIndex] = A_arr[i];
            zIndex++;
        }
    }

    if (count == 0)
    {
        cout << "\nNo element of the array satisfies the condition.\n";
    }
    else
    {
        cout << "\nThe product of the elements of the array A that satisfy the condition C(" << c << ") <= A[i] < D(" << d << "): " << product << endl;
        cout << "\nArray Z: ";

        for (int i = 0; i < count; i++) {
            cout << Z_arr[i] << " ";
        }
        cout << endl;
    }
    delete[] Z_arr;
}


int main()
{
#pragma region Ukranian
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");
#pragma endregion

    while (true)
        {
            cout << "Kachanov Artem 315A Var. 4" << endl << endl;

            switch (menu())
            {
            case '0':
                return EXIT_SUCCESS;
            case '1':
            {
                double default_A_arr[] = { 1, 3.5, 4, -0.8, 1.9, 5, 13 };
                task(default_A_arr, 7, 2, 10);
                break;
            }
            case '2':
            {
                int size;
                double c, d;

                cout << "\nEnter the size of the Z array: ";
                cin >> size;

                if (size <= 0)
                {
                    SetConsoleTextAttribute(handle, 4);
                    cerr << "\nError: Incorrect array size." << endl;
                    break;
                }

                double* A_arr = new double[size];

                cout << "\nEnter " << size << " values for the array A_arr." << endl;
                for (int i = 0; i < size; ++i)
                {
                    cout << "\nValue " << i + 1 << ": ";
                    cin >> A_arr[i];
                }

                cout << "\nEnter the value of C: ";
                cin >> c;
                cout << "\nEnter the value of D: ";
                cin >> d;

                task(A_arr, size, c, d);

                delete[] A_arr;
                break;
            }
            case '3':
            {
                srand(static_cast<unsigned int>(time(0)));
                int size, reg, j = 0;
                double c, d;

                size = rand() % 100 + 1;

                double* A_arr = new double[size];

                cout << "\nGenerating " << size << " random values for the array A_arr." << endl;
                cout << "\nDisplay all array elements?\n";
                cout << "\nYour choice (1 - yes): ";
                cin >> reg;

                for (int i = 0; i < size; ++i) {
                    A_arr[i] = 100 - rand() % 200;
                    if (reg == 1)
                    {
                        cout <<  "A_arr["<< i << "] = " << A_arr[i] << "\t";
                        j++;
                        if (j == 6)
                        {
                            cout << endl;
                            j = 0;
                        }
                    }

                }

                c = 100 - rand() % 200;
                cout << "\n\nC = " << c << endl;
                d = 100 - rand() % 200 + abs(c);
                cout << "\nD = " << d << endl;

                task(A_arr, size, c, d);

                delete[] A_arr;
                break;
            }
            default:
            {
                SetConsoleTextAttribute(handle, 4);
                cout << "\nWrong choice, try again!";
                break;
            }
            }
            cout << "\n\n";
            SetConsoleTextAttribute(handle, 2);
            cout << "<<<Press any key>>>\n";
            system("pause>nul");
            SetConsoleTextAttribute(handle, 7);
            system("cls");
        }
        return EXIT_SUCCESS;

    }