#include	"mlx_int.h" // Incluir la librería X11

// Función para cambiar el título de la ventana

// Función para cambiar el título de la ventana en MiniLibX
void mlx_change_window_title(void *mlx_ptr, void *win_ptr, char *new_title)
{
    t_xvar *xvar = (t_xvar *)mlx_ptr;  // Cast de la estructura MiniLibX principal
    t_win_list *win = (t_win_list *)win_ptr;  // Cast de la ventana

    // Cambia el título de la ventana usando X11
    XStoreName(xvar->display, win->window, new_title);

    // Asegúrate de que el título sea actualizado inmediatamente
    XFlush(xvar->display);
}