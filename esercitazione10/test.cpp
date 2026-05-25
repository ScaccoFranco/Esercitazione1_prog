#include "header.hpp"


int main()
{
    unsigned int N_TEST = 100;
    unsigned int N_MAX = 20;
    const double tol = 1.0e-15;
    const unsigned int it_max = 10000;

    for (unsigned int i = 0; i < N_TEST; i++)
    {
        unsigned int n = (rand() % N_MAX) + 1;

        Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

        if (abs(B.determinant()) < tol)
            continue;
        
        // genero matrice A definita positiva e simmetrica (sennò non garantisce convergenza)
        // Bt * B rende matrice simmetrica def pos
        Eigen::MatrixXd A = B.transpose() * B;
        Eigen::VectorXd x_ex = Eigen::VectorXd::Random(n);
        Eigen::VectorXd b = A * x_ex;
        Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

        unsigned int it = 0;
        Eigen::VectorXd x = gradiente_coniugato(A, b, x0, tol, it_max, it);

        double err_rel = (x - x_ex).norm() / x_ex.norm();
        if (err_rel > 1.0e-6)
        {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}