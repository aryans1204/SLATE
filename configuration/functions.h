#include <string>
//current functions supported matmul, matrix_norm, dot, fft, svd, eig. List can be extended further
class FunctionDef {
    public:
        string type; //type is string name of specific function
        int max_domain, min_domain;
        double p_objective;

        FunctionDef(string type, int min_domain, int max_domain, double p_objective); //constructor

        void matmul(int **matrix1, int **matrix2, int **result);  //matrix multiplication

        double **fft(int **matrix);  //fast fourier transform

        double matrix_norm(int **mat);  //computes Frobenius norm of matrix
        
        void svd(int **matrix, int **U, int **singular, int **V);  //singular value decomposition

        void eig(int **matrix, int **V, int **diag, int **V_inv);  //performs eigendecomposition of matrix, if the matrix has real eigenvalues

}