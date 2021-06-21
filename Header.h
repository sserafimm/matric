#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <exception>

using std::vector;

void printAbsoluteVector(std::vector<double> abs_vector)
{
    std::cout << "The absolute coefficients are: [";
    for (int i = 0; i < abs_vector.size(); ++i)
        std::cout << abs_vector[i] << " ";
    std::cout << "]" << std::endl;
}

void printScaleVector(std::vector<double> abs_vector)
{
    std::cout << "The scaling coefficients are: [";
    for (int i = 0; i < abs_vector.size(); ++i)
        std::cout << abs_vector[i] << " ";
    std::cout << "]" << std::endl;
}

std::vector<double> findMaximumRowNums(std::vector<std::vector<double>> augmented_matrix)
{
    std::vector<double> maximums;
    for (int i = 0; i < augmented_matrix.size(); ++i)
    {
        double maxel = augmented_matrix[i][0];
        for (size_t j = 1; j < augmented_matrix[i].size(); j++)
        {
            maxel = fmax(maxel, augmented_matrix[i][j]);
        }

        //std::max(augmented_matrix[i].begin(), augmented_matrix[i].end());


        maximums.push_back(maxel);
    }
    return maximums;
}

std::vector<double> makeScaleVector(std::vector<std::vector<double>>augmented_matrix, std::vector<double>abs_coefficients, int i)
{
    std::vector<double> scale_vector;


    for (int j = i; j < augmented_matrix.size(); ++j)
        scale_vector.push_back(abs(augmented_matrix[j][i] / abs_coefficients[j]));
    return scale_vector;
}

std::vector<double> ZeydelPivoting(std::vector<std::vector<double>> augmented_matrix)
{
    int equations_num = augmented_matrix.size();
    std::vector<double> abs_coefficients = findMaximumRowNums(augmented_matrix);
    printAbsoluteVector(abs_coefficients);

    std::vector<double> scale_vector;
    for (int i = 0; i < equations_num; ++i)
    {
        scale_vector = makeScaleVector(augmented_matrix, abs_coefficients, i);
        printScaleVector(scale_vector);
    }
    return scale_vector;
}

void show_matrix(std::vector<std::vector<double>> matr)
{
    std::cout << "Matrix \n";
    for (size_t i = 0; i < matr.size(); i++)
    {
        for (size_t j = 0; j < matr[i].size() - 1; j++)
        {
            std::cout << matr[i][j] << "\t";
        }
        std::cout << "|\t" << matr[i][matr[i].size() - 1] << "\n";
    }
    std::cout << "\n";
}


//void printAbsoluteVector(std::vector<double> abs_vector)
//{
//    std::cout << "The absolute coefficients are: [";
//    for (int i = 0; i < abs_vector.size(); ++i)
//        std::cout << abs_vector[i] << " ";
//    std::cout << "]" << std::endl;
//}
//
//void printScaleVector(std::vector<double> abs_vector)
//{
//    std::cout << "The scaling coefficients are: [";
//    for (int i = 0; i < abs_vector.size(); ++i)
//        std::cout << abs_vector[i] << " ";
//    std::cout << "]" << std::endl;
//}
//
//std::vector<double> findMaximumRowNums(std::vector<std::vector<double>> augmented_matrix)
//{
//    std::vector<double> maximums;
//    for (int i = 0; i < augmented_matrix.size(); ++i)
//    {
//        double max = *std::max_element(augmented_matrix[i].begin(), augmented_matrix[i].end() - 1);
//        maximums.push_back(max);
//    }
//    return maximums;
//}
//
//std::vector<double> makeScaleVector(std::vector<std::vector<double>>augmented_matrix, std::vector<double>abs_coefficients, int i)
//{
//    std::vector<double> scale_vector;
//
//
//    for (int j = i; j < augmented_matrix.size(); ++j)
//        scale_vector.push_back(abs(augmented_matrix[j][i] / abs_coefficients[j]));
//    return scale_vector;
//}
//
//
////solves given augmented matrix by Gaussian elimination with scaled partial pivoting
//
//std::vector<double> gaussPivoting(std::vector<std::vector<double>> augmented_matrix)
//{
//    int equations_num = augmented_matrix.size(); //number of equations
//    std::vector<double> abs_coefficients = findMaximumRowNums(augmented_matrix);
//    printAbsoluteVector(abs_coefficients);
//
//    //i is the iterator pointing a column
//    for (int i = 0; i < equations_num; ++i)
//    {
//        std::vector<double> scale_vector = makeScaleVector(augmented_matrix, abs_coefficients, i);
//        printScaleVector(scale_vector);
//
//        //find maximum absolute coefficients in each row
//        int max_rows_num = i;
//        for (int j = i + 1; j < equations_num; ++j)
//        {
//            if (abs(augmented_matrix[j][i]) > abs(augmented_matrix[max_rows_num][i]))
//            {
//                max_rows_num = j;
//            }
//        }
//
//        //swap current row with max absolute pivot column coeff row
//        swap(augmented_matrix[i], augmented_matrix[max_rows_num]);
//
//        for (int j = i + 1; j < equations_num; ++j)
//            for (int k = i; k <= equations_num; ++k)
//            {
//                augmented_matrix[j][k] -= augmented_matrix[j][i] * augmented_matrix[i][k] / augmented_matrix[i][i];
//                std::cout << augmented_matrix[j][k] << " + " << augmented_matrix[j][i] << " * " << augmented_matrix[i][k] << " / " << augmented_matrix[i][i] << "\n";
//            }
//
//        //printEquations(augmented_matrix);
//        printEquations(augmented_matrix);
//        scale_vector.clear();
//
//    }
//
//
//    //performing backward substitution
//    std::vector<double> solution(equations_num);
//
//    for (int i = equations_num - 1; i >= 0; --i)
//    {
//        solution[i] = augmented_matrix[i][equations_num] / augmented_matrix[i][i];
//        //substitute immediate solution backward and update RHS of each equation
//        for (int j = i - 1; j >= 0; --j)
//        {
//            augmented_matrix[j][equations_num] -= augmented_matrix[j][i] * solution[i];
//
//        }
//
//    }
//    printEquations(augmented_matrix);
//    return solution;
//}
