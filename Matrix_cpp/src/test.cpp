#include <gtest/gtest.h>

#include <iomanip>

#include "s21_matrix_oop.h"

using namespace std;

// ************************ Базовый конеструктор ************************
TEST(Create, test_1) { S21Matrix matr; }

// ************************ Конструткор копирвоания ************************
TEST(Copy, test_1) {
  S21Matrix matr(3, 3);
  S21Matrix matr2(matr);
  bool result = matr.EqMatrix(matr2);
  ASSERT_EQ(result, true);
}

// ******************** Параметризированный конструктор ********************
TEST(ConstructorParametr, test_1) {
  EXPECT_THROW(S21Matrix matr(-3, 3), invalid_argument);
}

// ************************ Конструткор переноса ************************
TEST(Transfer, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix matr(3, 3, data);
  S21Matrix matr_result(3, 3, data);
  S21Matrix matr2 = move(matr);
  bool result = matr2.EqMatrix(matr_result);
  ASSERT_EQ(result, true);
}

// ************** Перегрузка оператора сложения **************
TEST(OverloadPlus, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  double result[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  S21Matrix matr_plus = matr + matr2;
  bool res = matr_res.EqMatrix(matr_plus);
  ASSERT_EQ(res, false);
}

// ************** Перегрузка оператора вычитания **************
TEST(OverloadSub, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  S21Matrix matr_min = matr2 - matr;
  bool res = matr_res.EqMatrix(matr_min);
  ASSERT_EQ(res, false);
}

// ************** Перегрузка оператора умножения **************
TEST(OverloadMul, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {315.02, 224.6,  227.88, 213.82, 310.56, 276.98,
                     270.56, 370.96, 948,    733.2,  714.8,  768,
                     289.8,  368.2,  366,    659.8};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  S21Matrix matr_mul = matr2 * matr;
  bool res = matr_res.EqMatrix(matr_mul);
  ASSERT_EQ(res, true);
}

// ************** Перегрузка оператора умножения для числа **************
TEST(OverloadMulNum, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 4, data_2);
  S21Matrix matr_mul = matr * 2;
  bool res = matr_res.EqMatrix(matr_mul);
  ASSERT_EQ(res, true);
}

TEST(OverloadMulNum, test_2) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 4, data_2);
  S21Matrix matr_mul = 2 * matr;
  bool res = matr_res.EqMatrix(matr_mul);
  ASSERT_EQ(res, true);
}

// ************************ Перегрузка оператора == ************************
TEST(OverloadEqMatr, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  bool res = matr == matr2;
  ASSERT_EQ(res, false);
}

// ************************ Перегрузка оператора = ************************
TEST(OverloadEqual, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  S21Matrix matr2;
  matr2 = matr;
  bool res = matr.EqMatrix(matr2);
  ASSERT_EQ(res, true);
}

// ************************ Перегрузка оператора += ************************
TEST(OverloadSumEq, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  double result[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  matr += matr2;
  bool res = matr_res.EqMatrix(matr);
  ASSERT_EQ(res, false);
}

// ************************ Перегрузка оператора -= ************************
TEST(OverloadSubEq, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  matr2 -= matr;
  bool res = matr_res.EqMatrix(matr2);
  ASSERT_EQ(res, false);
}

// ************************ Перегрузка оператора *= ************************
TEST(OverloadMulEq, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  double result[] = {315.02, 224.6,  227.88, 213.82, 310.56, 276.98,
                     270.56, 370.96, 948,    733.2,  714.8,  768,
                     289.8,  368.2,  366,    659.8};
  S21Matrix matr_res(4, 4, result);
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  matr2 *= matr;
  bool res = matr_res.EqMatrix(matr2);
  ASSERT_EQ(res, true);
}

// ************** Перегрузка оператора *= для числа **************
TEST(OverloadMulEqNum, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 4, data_2);
  matr *= 2;
  bool res = matr_res.EqMatrix(matr);
  ASSERT_EQ(res, true);
}

// ************** Перегрузка оператора индексации **************
TEST(OverloadIndex, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  ASSERT_EQ(matr(0, 1), 2);
}

TEST(OverloadIndex, test_2) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  EXPECT_THROW(matr(5, 1), out_of_range);
}

TEST(OverloadIndex, test_3) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_res[] = {1.1, 777, 3.4, 8.1, 7.2, 6.3, 4, 5.2,
                       6,   12,  11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 4, data_res);
  matr(0, 1) = 777;
  bool result = matr.EqMatrix(matr_res);
  ASSERT_EQ(result, true);
}

TEST(OverloadIndex, test_4) {
  S21Matrix matr;
  EXPECT_THROW(matr(2, 1), invalid_argument);
}

TEST(OverloadIndex, test_5) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  EXPECT_THROW(matr(5, 1), out_of_range);
}

TEST(OverloadIndex, test_6) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix const matr(3, 3, data);
  ASSERT_EQ(matr(0, 1), 2);
}

TEST(OverloadIndex, test_7) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix const matr(3, 3, data);
  EXPECT_THROW(matr(5, 1), out_of_range);
}

// ************************ Get ************************
TEST(Getter, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  S21Matrix matr(4, 4, data);
  int cols = matr.GetCols();
  int rows = matr.GetRows();
  ASSERT_EQ(cols, 4);
  ASSERT_EQ(rows, 4);
}

// ************************ Set ************************
TEST(Setter, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1,  2,  3,  4,  5,  6,  7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 0, 0, 0, 0};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(5, 4, data_res);
  matr.SetRows(5);
  bool result = matr.EqMatrix(matr_res);
  ASSERT_EQ(result, true);
}

TEST(Setter, test_2) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  S21Matrix matr(4, 4, data);
  EXPECT_THROW(matr.SetRows(-1), invalid_argument);
}

TEST(Setter, test_3) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(3, 4, data_res);
  matr.SetRows(3);
  bool result = matr.EqMatrix(matr_res);
  ASSERT_EQ(result, true);
}

TEST(Setter, test_4) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2,  3,  4,  0, 5,  6,  7,  8,  0,
                       9, 10, 11, 12, 0, 13, 14, 15, 16, 0};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 5, data_res);
  matr.SetCols(5);
  bool result = matr.EqMatrix(matr_res);
  ASSERT_EQ(result, true);
}

TEST(Setter, test_5) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  S21Matrix matr(4, 4, data);
  EXPECT_THROW(matr.SetCols(-1), invalid_argument);
}

TEST(Setter, test_6) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double data_res[] = {1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 3, data_res);
  matr.SetCols(3);
  bool result = matr.EqMatrix(matr_res);
  ASSERT_EQ(result, true);
}

// ************************ Сравнение матриц ************************
TEST(EqMatrix, test_1) {
  S21Matrix matr(3, 3);
  S21Matrix matr2(3, 3);
  bool result = matr.EqMatrix(matr2);
  ASSERT_EQ(result, true);
}

TEST(EqMatrix, test_2) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data);
  bool result = matr.EqMatrix(matr2);
  ASSERT_EQ(result, true);
}

TEST(EqMatrix, test_3) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double data_2[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 3};
  S21Matrix matr(4, 4, data);
  S21Matrix matr2(4, 4, data_2);
  bool result = matr.EqMatrix(matr2);
  ASSERT_EQ(result, false);
}

TEST(EqMatrix, test_4) {
  S21Matrix matr(4, 4);
  S21Matrix matr2(4, 3);
  bool result = matr.EqMatrix(matr2);
  ASSERT_EQ(result, false);
}

// ************************ Сложение матриц ************************
TEST(SumMatrix, test_1) {
  double data[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                   6,   12, 11,  21,  15,  7,   8, 2};
  double result[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_2(4, 4, data);
  S21Matrix matr_res(4, 4, result);
  matr.SumMatrix(matr_2);
  ASSERT_EQ(matr_res.EqMatrix(matr), true);
}

TEST(SumMatrix, test_2) {
  S21Matrix matr(4, 3);
  S21Matrix matr_2(4, 4);
  EXPECT_THROW(matr.SumMatrix(matr_2), invalid_argument);
}

TEST(SumMatrix, test_3) {
  S21Matrix matr;
  S21Matrix matr_2;
  matr_2.SumMatrix(matr);
  ASSERT_EQ(matr_2.EqMatrix(matr), false);
}

// ************************ Вычитание матриц ************************
TEST(SubMatrix, test_1) {
  double data[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                   12,  24, 22,  42,   30,   14,   16, 4};
  double data_2[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 2};
  double result[] = {1.1, 2,  3.4, 8.1, 7.2, 6.3, 4, 5.2,
                     6,   12, 11,  21,  15,  7,   8, 2};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_2(4, 4, data_2);
  S21Matrix matr_res(4, 4, result);
  matr.SubMatrix(matr_2);
  ASSERT_EQ(matr_res.EqMatrix(matr), true);
}

TEST(SubMatrix, test_2) {
  S21Matrix matr(4, 3);
  S21Matrix matr_2(4, 4);
  EXPECT_THROW(matr.SubMatrix(matr_2), invalid_argument);
}

TEST(SubMatrix, test_3) {
  S21Matrix matr;
  S21Matrix matr_2;
  matr_2.SumMatrix(matr);
  ASSERT_EQ(matr_2.EqMatrix(matr), false);
}

// ************************ Умножение матрицы на число ************************
TEST(MulNumber, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double result[] = {2,  4,  6,  8,  10, 12, 14, 16,
                     18, 20, 22, 24, 26, 28, 30, 32};
  S21Matrix matr(4, 4, data);
  S21Matrix matr_res(4, 4, result);
  matr.MulNumber(2);
  ASSERT_EQ(matr_res.EqMatrix(matr), true);
}

TEST(MulNumber, test_2) {
  S21Matrix matr;
  EXPECT_THROW(matr.MulNumber(2), invalid_argument);
}

// ************************ Перемножение матриц ************************
TEST(MulMatrix, test_1) {
  double data[] = {1.1, 2, 3.4, 8.1, 7.2, 6.3, 4, 5.2, 6};
  double data_2[] = {2.2, 4,  6.8, 16.2, 14.4, 12.6, 8,  10.4,
                     12,  24, 22,  42,   30,   14,   16, 4};
  S21Matrix matr(3, 3, data);
  S21Matrix matr2(4, 4, data_2);
  EXPECT_THROW(matr2.MulMatrix(matr), invalid_argument);
}

// ************************ Транспортирование матрицы ************************
TEST(Transpose, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  S21Matrix matr(3, 3, data);
  S21Matrix matr_res(3, 3, result);
  S21Matrix matr2;
  matr2 = matr.Transpose();
  ASSERT_EQ(matr_res.EqMatrix(matr2), true);
}

TEST(Transpose, test_2) {
  S21Matrix matr;
  EXPECT_THROW(matr.Transpose(), invalid_argument);
}

// ************************ Определитель матрицы ************************
TEST(Determinant, test_1) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21Matrix matr(3, 3, data);
  double result = matr.Determinant();
  ASSERT_EQ(result, 0.0);
}

TEST(Determinant, test_2) {
  double data[] = {9.1, 8, 7, 6, 5, 4, 3, 2, 1};
  S21Matrix matr(3, 3, data);
  double result = matr.Determinant();
  ASSERT_DOUBLE_EQ(result, -0.29999999999999905);
}

TEST(Determinant, test_3) {
  double data[] = {1, 0, 0, 0, 0, 4, 0, 0, 0};
  S21Matrix matr(3, 3, data);
  double result = matr.Determinant();
  ASSERT_DOUBLE_EQ(result, 0.0);
}

TEST(Determinant, test_4) {
  double data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  S21Matrix matr(3, 3, data);
  double result = matr.Determinant();
  ASSERT_DOUBLE_EQ(result, 0.0);
}

TEST(Determinant, test_5) {
  double data[] = {51, 2, 2, 1, 0, 0, 3, 43, 0, 0, 0, 3, 51, 0, 0, 1};
  S21Matrix matr(4, 4, data);
  double result = matr.Determinant();
  ASSERT_DOUBLE_EQ(result, -918.0);
}

TEST(Determinant, test_6) {
  double data[] = {51, 2, 2, 1, 0, 0, 3, 43, 0, 0, 0, 3};
  S21Matrix matr(3, 4, data);
  EXPECT_THROW(matr.Determinant(), invalid_argument);
}

// ************************ CalcComplements матрицы ************************
TEST(CalcComplements, test_1) {
  double data[] = {6.7, 5, -4, 99};
  double result[] = {99, 4, -5, 6.7};
  S21Matrix matr(2, 2, data);
  S21Matrix matr2;
  S21Matrix matr_res(2, 2, result);
  matr2 = matr.CalcComplements();
  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(CalcComplements, test_2) {
  double data[] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
  double result[] = {4, 0, 0, 0, 4, 0, 0, 0, 4};
  S21Matrix matr(3, 3, data);
  S21Matrix matr2;
  S21Matrix matr_res(3, 3, result);
  matr2 = matr.CalcComplements();
  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(CalcComplements, test_3) {
  double data[] = {2, 0, 0, 0, 2, 0};
  double result[] = {4, 0, 0, 0, 4, 0, 0, 0, 4};
  S21Matrix matr(2, 3, data);
  S21Matrix matr2;
  S21Matrix matr_res(3, 3, result);
  EXPECT_THROW(matr2 = matr.CalcComplements(), invalid_argument);
}

TEST(CalcComplements, test_4) {
  double data[] = {1, 2, 3, 4};
  double result[] = {4, -3, -2, 1};
  S21Matrix matr(2, 2, data);
  S21Matrix matr2;
  S21Matrix matr_res(2, 2, result);
  matr2 = matr.CalcComplements();
  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(CalcComplements, test_5) {
  double data[] = {1};
  double result[] = {1};
  S21Matrix matr(1, 1, data);
  S21Matrix matr_res(1, 1, result);
  S21Matrix matr2;
  matr2 = matr.CalcComplements();
  bool res = matr2.EqMatrix(matr_res);
  ASSERT_EQ(res, true);
}

// ************************ InverseMtrix ************************
TEST(InverseMtrix, test_1) {
  double data[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double result[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  S21Matrix matr(3, 3, data);
  S21Matrix matr2;
  S21Matrix matr_res(3, 3, result);
  matr2 = matr.InverseMtrix();
  ASSERT_EQ(matr2.EqMatrix(matr_res), true);
}

TEST(InverseMtrix, test_2) {
  double data[] = {2, 5, 7, 6, 3, 4};
  double result[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  S21Matrix matr(2, 3, data);
  S21Matrix matr2;
  S21Matrix matr_res(3, 3, result);
  EXPECT_THROW(matr2 = matr.InverseMtrix(), invalid_argument);
}

TEST(InverseMtrix, test_3) {
  double data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  S21Matrix matr(3, 3, data);
  S21Matrix matr2;
  S21Matrix matr_res(3, 3, result);
  EXPECT_THROW(matr2 = matr.InverseMtrix(), invalid_argument);
}

TEST(InverseMtrix, test_4) {
  double data[] = {1};
  S21Matrix matr(1, 1, data);
  S21Matrix matr2;
  EXPECT_THROW(matr2 = matr.InverseMtrix(), invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}