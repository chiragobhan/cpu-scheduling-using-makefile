# CPU Scheduling in C using Makefile
Compiling the source code files can be tiring, especially when you have to include several source files and type the compiling command every time you need to compile. Makefiles are the solution to simplify this task. Makefiles are special format files that help build and manage the projects automatically.
## Run and compile your programs more efficiently with this handy automation tool.  
  
If you want to run or update a task when certain files are updated, the `make` utility can come in handy. The `make` utility requires a file, `Makefile` (or `makefile`), which defines set of tasks to be executed. You may have used `make` to compile a program from source code. Most open source projects use `make` to compile a final executable binary, which can then be installed using `make install`.
  
## Install Make
### Linux
Simply run the following command on your terminal:  
`sudo apt-get install build-essential`  
### Windows  
`make` is a GNU command so the only way you can get it on Windows is installing a Windows version like the one provided by [GNUWin32](http://gnuwin32.sourceforge.net/packages/make.htm). Or you can install [MinGW](http://www.mingw.org/) and then do:  
`copy c:\MinGW\bin\mingw32-make.exe c:\MinGW\bin\make.exe`  
Other option is using [Chocolatey](https://chocolatey.org/install). First you need to install this package manager. Once installed you simply need to install `make`:  
`choco install make`  

## Explaination
To further understand `make`, I will be using my previous CPU Scheduling example with some modifications (mentioned below). Link - https://github.com/chiragobhan/cpu-scheduling  
Let us understand our source code files of this repo:  
1. init.h (This is the initailization header file which will open "input.txt" to scan the value of processes)  
2. fcfs.h (This header file includes the logical block of FCFS which is seperated from main program)  
3. sjf.h (This header file includes the logical block of SJF which is seperated from main program)  
4. program.c (All the header codes are included in this program and their respective functions are being called)  
  
Now the trivial way to compile the files and obtain an executable, is by running the command −  
`gcc  program.c -o program`  
The above command generates "program.exe" which can be executed directly. In this example we have only four files and we know the sequence of the function calls. Hence, it is feasible to type the above command and prepare a final binary.  
However, for a large project where we have thousands of source code files, it becomes difficult to maintain the binary builds.
  
The make command allows you to manage large programs or groups of programs. As you begin to write large programs, you notice that re-compiling large programs takes longer time than re-compiling short programs. Moreover, you notice that you usually only work on a small section of the program ( such as a single function ), and much of the remaining program is unchanged.

## Executing Make
Run the following command in your terminal:  
`make`  
If the command is successfull, you will get a similar output:
  
![make output](https://user-images.githubusercontent.com/32812640/81988304-d9960f00-9658-11ea-910b-ab9e45f3c6c1.PNG)  
Also observe, 2 new files are created in your directory.  
1. program.o (An object file which will be used to create the executable file)  
2. program.exe (Executable file which executes program.c)  
  
The further steps of executing program.exe is similar to the previous CPU Scheduling example which can be referred here - https://github.com/chiragobhan/cpu-scheduling

## References
1. https://opensource.com/article/18/8/what-how-makefile  
2. https://www.tutorialspoint.com/makefile/why_makefile.htm  
3. https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows
