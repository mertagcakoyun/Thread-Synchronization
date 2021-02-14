# Thread-Synchronization
## Project topic:
The project, it is aimed to create and collect a matrix using thread synchronization.
## Project Research

### What is Thread?
Threads are units of an application (process) that do work. An application must have at least one thread. This obligatory thread is usually called the "main thread" and when this thread ends, the application is normally expected to terminate. There may be one or more than one thread that can run on a program simultaneously.

### Thread Creation and Properties
To create a new thread, the pthread_create function is used.
For the use of thread functions, the header file pthread.h must be included.
Threads use the same addressing space as the main program.
The pthread library also includes support for mutex and conditional operations required for synchronization.
When the pthread library functions are used, the application must also be linked with the pthread library.
Returns 0 on success. In case of an error, an error code will be returned.
The thread parameter is of type pthread_t and must be defined beforehand. The generated thread will always be accessible with this reference.

## Project Description
A global matrix variable is randomly populated inside the matrix generation method. Then it is printed by calling the function that performs the print operation of the matrix. After printing, the addition method starts to be run by using inter-thread lock unlock functions. These operations continue for the number of times received from the user. The user must enter a number greater than zero. Otherwise, it will get a warning. The ctrl + z signal is normally used to terminate applications at terminals. In the project, a control structure has been created that gives a warning when the ctrl + z key combination is entered and terminates the program.
