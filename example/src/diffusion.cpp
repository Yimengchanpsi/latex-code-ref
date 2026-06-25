#include <vector>
#include <cstddef>

/**
 * Solve the 1-D heat equation using an explicit finite-difference scheme.
 *
 *   du/dt = alpha * d²u/dx²
 *
 * Discretised as:
 *
 *   u[i]^{n+1} = u[i]^n + r * (u[i+1]^n - 2*u[i]^n + u[i-1]^n)
 *
 * where r = alpha * dt / dx^2  (must satisfy r <= 0.5 for stability).
 */

// \coderef{heat_diffusion_equation}
void heat_diffusion_step(std::vector<double>& u,
                         double alpha, double dt, double dx)
{
    const double r = alpha * dt / (dx * dx);
    const std::size_t N = u.size();

    std::vector<double> u_new(N);
    u_new[0]     = u[0];          // fixed boundary (left)
    u_new[N - 1] = u[N - 1];     // fixed boundary (right)

    for (std::size_t i = 1; i < N - 1; ++i) {
        u_new[i] = u[i] + r * (u[i + 1] - 2.0 * u[i] + u[i - 1]);
    }

    u = u_new;
}

// \coderef{stability_criterion}
bool is_stable(double alpha, double dt, double dx)
{
    return (alpha * dt / (dx * dx)) <= 0.5;
}
