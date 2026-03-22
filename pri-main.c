#include <stdio.h>

/**
 * Matrix Solver Program
 * This program performs Addition, Subtraction, and Multiplication
 * of two matrices based on user input.
 */

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2, choice;

    printf("--- Matrix Operations Solver ---\n");
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    int a[r1][c1], b[r2][c2];

    // Input for Matrix A
    printf("\nEnter elements for Matrix A (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Input for Matrix B
    printf("\nEnter elements for Matrix B (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nChoose Operation:\n1. Addition\n2. Subtraction\n3. Multiplication\nSelection: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            if (r1 == r2 && c1 == c2) {
                int sum[r1][c1];
                printf("\nResult (A + B):\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        sum[i][j] = a[i][j] + b[i][j];
                        printf("%d\t", sum[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("\nError: Matrices must have the same dimensions for addition.\n");
            }
            break;

        case 2: // Subtraction
            if (r1 == r2 && c1 == c2) {
                int diff[r1][c1];
                printf("\nResult (A - B):\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c1; j++) {
                        diff[i][j] = a[i][j] - b[i][j];
                        printf("%d\t", diff[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("\nError: Matrices must have the same dimensions for subtraction.\n");
            }
            break;

        case 3: // Multiplication
            if (c1 == r2) {
                int prod[r1][c2];
                // Initialize result matrix with zeros
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        prod[i][j] = 0;
                    }
                }

                printf("\nResult (A * B):\n");
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        for (int k = 0; k < c1; k++) {
                            prod[i][j] += a[i][k] * b[k][j];
                        }
                        printf("%d\t", prod[i][j]);
                    }
                    printf("\n");
                }
            } else {
                printf("\nError: Columns of A must equal Rows of B for multiplication.\n");
            }
            break;

        default:
            printf("\nInvalid selection.\n");
    }

    return 0;
}
