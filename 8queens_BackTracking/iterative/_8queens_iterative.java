/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reinas;

/**
 *
 * @author brayme
 */
public class Reinas {

    /**
     * @param args the command line arguments
     */
    static int a[][];
    static int N = 4;

    public static void main(String[] args) {

        a = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = 0;
            }
        }

        int n = 8, row, col, prev, flag = 0, count = 0, i, j;

        for (row = 0; row < N; row++) {
            for (prev = 0; prev < N; prev++) {
                flag = 0;
                if (a[row][prev] == 1) {
                    a[row][prev] = 0;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                prev = -1;
            }
            flag = 0;
            for (col = prev + 1; col < N; col++) {
                if (check(row, col)) {
                    a[row][col] = 1;
                    flag = 1;
                    break;
                }
            }
            if (row == 0 && flag == 0) {
                break;
            } else if (col == N) {
                row = row - 2;
            } else if (row == N - 1 && flag == 1) {
                count++;
//to print uncomment here.
                System.out.println("solution found: " + count);
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N; j++) {
                        if (a[i][j] == 1) {
                            System.out.print("Q ");
                        } else {
                            System.out.print("* ");
                        }
                    }
                    System.out.println("\n");
                }

                row = row - 1;

            }
        }

    }

    static boolean check(int row, int col) {
        int i;
        for (i = 0; i < row; i++) {
            if (a[row - 1 - i][col] == 1) {
                return false;
            }

            if ((col - i - 1) >= 0) {
                if (a[row - 1 - i][col - 1 - i] == 1) {
                    return false;
                }
            }

            if (col + 1 + i <= N - 1) {
                if (a[row - 1 - i][col + 1 + i] == 1) {
                    return false;
                }
            }

        }

        return true;
    }

}
