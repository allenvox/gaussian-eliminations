#include <iostream>

void printMatrix(float **matrix, int n)
{
    std::cout << "Your matrix now looks like this:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            std::cout << matrix[i][j] << "\t";
            if (j == n - 1)
            {
                std::cout << "\t|\t";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

int main()
{
    int n;
    std::cout << "Enter the number of unknowns: ";
    std::cin >> n;
    float **matrix = (float **)malloc(n * sizeof(float *));
    float result[n];

    // matrix initialization
    std::cout << "Enter the elements of the matrix: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (float *)malloc((n + 1) * sizeof(float));
        for (int j = 0; j < n + 1; j++)
        {
            std::cout << "m[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "\n";

    printMatrix(matrix, n);

    // making the upper triangular matrix
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            float temp = matrix[i][j] / matrix[j][j];
            for (int k = 0; k < n + 1; k++)
            {
                matrix[i][k] -= matrix[j][k] * temp;
            }
        }
    }

    printMatrix(matrix, n);

    // backwards substitution
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            if (i != j)
            {
                result[i] -= matrix[i][j] * result[j];
            }
        }
        result[i] = result[i] / matrix[i][i];
    }

    // printing out the unknowns
    std::cout << "The values of unknowns: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i];
        if (i != n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    exit(0);
}