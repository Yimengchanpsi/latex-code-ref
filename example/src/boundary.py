"""
boundary.py — Apply boundary conditions to the 1-D heat solver grid.
"""


# \coderef{dirichlet_boundary}
def apply_dirichlet(grid: list[float], left: float, right: float) -> None:
    """Enforce fixed-value (Dirichlet) boundary conditions in-place."""
    grid[0] = left
    grid[-1] = right


# \coderef{neumann_boundary}
def apply_neumann(grid: list[float], flux_left: float, flux_right: float,
                  dx: float) -> None:
    """
    Enforce zero-flux (Neumann) boundary conditions using a first-order
    one-sided finite difference:

        du/dx|_{x=0}  = flux_left   →  u[0]  = u[1]  - flux_left  * dx
        du/dx|_{x=L}  = flux_right  →  u[-1] = u[-2] + flux_right * dx
    """
    grid[0] = grid[1] - flux_left * dx
    grid[-1] = grid[-2] + flux_right * dx
