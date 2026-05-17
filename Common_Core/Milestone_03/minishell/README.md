*This project has been created as part of the 42 curriculum by dfrincu, dmtur.*

# Minishell

## Description

Minishell is a simplified UNIX shell implemented in C as part of the 42 school curriculum. The goal of this project is to deepen understanding of process management, pipes, signals, environment variables, and command parsing by recreating a functional shell. Minishell supports executing built-in and external commands, handling redirections and pipelines, managing environment variables, and basic signal handling, providing a hands-on introduction to shell internals and UNIX programming.

## Instructions

### Compilation

Clone the repository and compile the project using `make`:

```sh
git clone <your-repo-url>
cd minishell
make
```

### Running Minishell

After compilation, run the shell with:

```sh
./minishell
```

### Features
- Built-in commands: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, `unset`
- Execution of external commands found in `$PATH`
- Input/output redirections (`>`, `>>`, `<`, `<<`)
- Pipelining with `|`
- Environment variable expansion
- Signal handling (Ctrl+C, Ctrl+\, etc.)
- Error handling and informative messages

### Controls
- Type commands as in a standard shell and press Enter to execute.
- Use Ctrl+D to exit the shell.

## Resources

- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [UNIX Shell Programming](https://www.gnu.org/software/bash/manual/bash.html#Shell-Commands)
- [Process Management in UNIX](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Redirections in Shells](https://tldp.org/LDP/abs/html/io-redirection.html)
- [Signals in UNIX](https://man7.org/linux/man-pages/man7/signal.7.html)
- [42 School Subject PDF]

### AI Usage Disclosure

AI tools (ChatGPT/GitHub Copilot) were used during this project for:
- Debugging and code review suggestions
- Assistance with Makefile and compilation issues
- Help with structuring and writing this README

All code was written, tested, and understood by the authors. AI was used strictly as a learning and assistance tool, similar to documentation or peer discussion.

## Authors

- **dfrincu** (42 Barcelona)
- **dmtur** (42 Barcelona)

## License

This project is part of the 42 school curriculum and is intended for educational purposes only.
