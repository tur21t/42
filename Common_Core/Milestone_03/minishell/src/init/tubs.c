#include "minishell.h"

void init_shell(t_shell *shell, char **envp)
{
    shell->env = envp;
    // Luego inicializar mas cosas
}

void free_shell(t_shell *shell)
{
    (void)shell;
}