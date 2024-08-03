 #include <stdio.h>
 #define MAX 100
 void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
 printf("Enter the elements of the matrix:\n");
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 printf("Element [%d][%d]: ", i, j);
 scanf("%d", &matrix[i][j]);
 }
 }
 }
 void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
 printf("Matrix:\n");
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 printf("%d ", matrix[i][j]);
 }
 printf("\n");
 }
 }
 void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 transposed[j][i] = matrix[i][j];
 }
 }
 }
 int main() {
 int matrix[MAX][MAX], transposed[MAX][MAX];
 int rows, cols;
 printf("Enter the number of rows and columns: ");
 scanf("%d %d", &rows, &cols);
 readMatrix(matrix, rows, cols);
 transposeMatrix(matrix, transposed, rows, cols);
 printf("Original matrix:\n");
 printMatrix(matrix, rows, cols);
 printf("Transposed matrix:\n");
 printMatrix(transposed, cols, rows);
 return 0;
 }
