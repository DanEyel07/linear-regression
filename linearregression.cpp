#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

double **getRandMatrix(int, int);
double **createEmpty2DArray(int, int);
double **matrixMult(double **, double **, int, int, int);
void printArray(double **, int, int);
void deleteArray(double **, int, int);

int main()
{
    int iRows = 10;
    int iCols = 10;
    double **arrIn = getRandMatrix(iRows, iCols);

    printArray(arrIn, iRows, iCols);

    arrIn = matrixMult(arrIn, arrIn, iRows, iRows, iCols);

    printArray(arrIn, iRows, iCols);

    deleteArray(arrIn, iRows, iCols);

    return 0;
}

//---> MATRIX MULTIPLICATION ********************************************
//Where m x n denotes rows x columns and matrices are denoted by matrix 1 and matrix 2, dot product of 1 & 2.
//Results in an m1 x n2 matrix
//**************************************************************

double **matrixMult(double **arrOne, double **arrTwo, int n1m2, int m1, int n2)
{
    double **arrOut = createEmpty2DArray(m1, n2);

    for (int i = 0; i < m1; i++) //iterate rows of matrix 1
    {
        for (int j = 0; j < n2; j++) //iterate cols of matrix 2
        {
            for (int k = 0; k < n1m2; k++) //iterate each value to be multiplied and summed
            {
                arrOut[i][j] += arrOne[i][k] * arrTwo[k][j];
            }
        }
    }

    deleteArray(arrOne, m1, n1m2);
    deleteArray(arrTwo, n1m2, n2);

    return arrOut;
}

//---> GET RANDOM MATRIX ***************************************
//Gets a 2d matrix of size iRows x iCols, filling the matrix with random integers between 0 and
//the modulus value indicated in the rand() assignment formula, below.
//**************************************************************

double **getRandMatrix(int iRows, int iCols)
{
    double **arrIn = 0;

    arrIn = new double *[iRows];

    srand(time(NULL));

    for (int i = 0; i < iRows; i++)
    {
        arrIn[i] = new double[iCols];

        for (int j = 0; j < iCols; j++)
        {
            arrIn[i][j] = rand() % 10;
        }
    }

    return arrIn;
}

//---> PRINT ARRAY *********************************************
//
//
//**************************************************************

double **createEmpty2DArray(int iRows, int iCols)
{
    double **arrEmpty = 0;
    arrEmpty = new double *[iRows];

    for (int i = 0; i < iRows; i++)
    {
        arrEmpty[i] = new double[iCols];
    }

    return arrEmpty;
}

//---> PRINT ARRAY *********************************************
//
//
//**************************************************************

void printArray(double **arrPrint, int iRows, int iCols)
{
    cout << "Array:" << endl;

    for (int i = 0; i < iRows; i++)
    {
        for (int j = 0; j < iCols; j++)
        {
            cout << arrPrint[i][j] << " ";
        }

        cout << endl;
    }
}

//---> DELETE ARRAY ********************************************
//
//
//**************************************************************

void deleteArray(double **arrDelete, int iRows, int iCols)
{
    for (int i = 0; i < iRows; i++)
    {
        delete[] arrDelete[i];
    }
    delete[] arrDelete;
    arrDelete = 0;
}