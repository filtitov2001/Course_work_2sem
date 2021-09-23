<h1 align="center"> Console application of OOP's course work </h1>

<div align="center">

[![Build Status](https://img.shields.io/badge/C%2B%2B-17-blue)](https://isocpp.org)

</div>

## Table of Contents
- [Formulation of the task](#formulation-of-the-task)
- [Technology stack](#technology-stack)
- [Configuration](#configuration)

## Formulation of the task


The essence of the assignment was to create a console application using only OOP principles, signals and handlers. 

Develop a program that accepts an integer arithmetic expression without parentheses as input.  All operations have the same priority.  The expression uses the following operators: +, -, *, and % (integer remainder).  After the execution of each operation, an intermediate result is returned as part of the expression.  The job ends after the last operation is completed.
 
 Create objects: 
  1. To enter the original integer arithmetic expression.  
  2. To practice the operation.  
  3. To display the next intermediate result.
 
Write a program that implements the following algorithm: 

1. Input an arithmetic expression.  
2. Definition of the first operand.  
3. Issuing "signal_1" and transferring the first operand.  
4. Loop until the end of an arithmetic expression.
4.1. Determining the next operation.  
4.2. Issuing "siqnal_2" and transmitting the operation symbol.  
4.3. Determination of the next operand.  
4.4. Issuing "signal_3" and transmitting the next operand.    
5. End of the cycle.  

In the handlers of the processing object, implement the operation: 

Upon receipt of "signal_1": store the value of the first operand.  
Upon receipt of "signal_2": save the operation symbol.  
Upon receipt of "signal_3": perform the operation, issue "signal_4" and send a string for output.

## Technology stack

- C++

## Configuration

To run the application, you need to use an IDE that supports the specified language version.

## Copyright

Copyright © 2020 by [Felix Titov](https://github.com/filtitov2001)
