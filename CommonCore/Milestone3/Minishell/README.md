# Minishell Tests

## Tests
### Compilation
```sh
Check -Wall -Wextra -Werror
make -n
gcc -Wall -Wextra -Werror -c src/main.c -o obj/main.o
```

## Simple Command
```sh
/bin/ls
include libft Makefile minishell minishell_tester src

date
Wed 7 Jul 2021 11:00:00 AM -03

ifconfig
network information

who
wcorrea- tty2 2023-06-20 10:46 (tty2)
```

### Special Cases
```sh
[empty]
print a new line

[space]
print a new line

[tab]
do nothing
```

## Command with Arguments
```sh
touch 1 2 3
create 3 files

/bin/ls -l
list files with details

rm 1 2 3
remove 3 files

cat Makefile
print the content of the Makefile

cat -e Makefile
print the content of the Makefile with $ at the end of each line

wc -l Makefile
55 Makefile

echo
echo
print a new line

echo This is a test
This is a test

echo -n Hello World
Hello World/home/wcorrea-$
```

## Exit Commands
```sh
exit
exit
exit the minishell

exit 1
exit the minishell with return code 1

exit 42
exit the minishell with return code 42

exit -42
exit the minishell with return code 214

exit 42 10
minishell: exit: too many arguments

exit 42scholl
minishell: exit: numeric argument required; then exit with error code 2
```

## Return Value of a Process
```sh
echo $?
0

/bin/ls
echo $? # return code is 0

ls notexist
echo $? # return code is 2

/bin/notexist
echo $? # return code is 127

expr $? + $?
echo $? # return code is 2
```

## Signals
```sh
ctrl-C on empty prompt
display a new line with a new prompt
echo $? must display 130

ctrl-\ on empty prompt
do nothing

ctrl-D on empty prompt
quit minishell
echo $? must display 0
```

## Double Quotes
```sh
"/bin/ls"
execute ls

""ls""
execute ls

""ls -l""
execute ls with details

"""ls -l"""
minishell: ls -l: command not found

"echo Hello World"
minishell: echo Hello World: command not found

echo "Hello World"
Hello World
```

## Single Quotes
```sh
echo '$USER'
$USER

echo 'Hello World'
Hello World

echo 'with spaces'
Hello World
```

## Environment Variables
```sh
env
print the environment variables

env PATH
minishell: env: Arguments and options aren't supported
```

## Export and Unset
```sh
export NEW_VAR=42
add NEW_VAR with content 42

unset NEW_VAR
remove the environment variable
```

## Change Directory
```sh
cd ..
go to the parent directory

cd /
go to root directory
```

## Relative and Absolute Paths
```sh
./minishell
execute the minishell inside minishell

../../bin/ls
list files
```

## Redirection and Pipes
```sh
ls -l > test
create a file with the files list inside

cat Makefile >> test
append the content of the Makefile to the file

wc -l < test
63

cat Makefile | grep NAME | wc -l
5
```

## Special Cases and Errors
```sh
export =
minishell: export: `=': not a valid identifier

export 1TEST=test
minishell: export: `1TEST=test': not a valid identifier

;
minishell: no support for operator `;'

*
minishell: no support for operator `*'
```

## Not Required but Implemented
```sh
cd -
go to the previous directory

<< EOF
start the here document

> file
create a file

>> file
append to a file
```

- **TESTS CREDITS:** [Walter](https://github.com/waltergcc/42-minishell)

- **MinishellTests.xlsx CREDITS:** [	Daniel Junho](https://github.com/djunho)
