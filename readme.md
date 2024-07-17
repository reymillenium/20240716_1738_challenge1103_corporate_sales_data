# COP 1334 Assignment - Introduction to C++

## Chapter 11 Challenge 3

## Title: Corporate Sales Data

### Exercise Description:

Write a program that uses a structure to store the following data on a company division:

- Division Name (such as East, West, North, or South)
- First-Quarter Sales
- Second-Quarter Sales
- Third-Quarter Sales
- Fourth-Quarter Sales
- Total Annual Sales
- Average Quarterly Sales

The program should use four variables of this structure. Each variable should represent one of the following corporate divisions: East, West, North, and South. The user should be asked for the four quarters’ sales figures for each division. Each division’s total and average sales should be calculated and stored in the appropriate member of each structure variable. These figures should then be displayed on the screen.

_Input Validation: Do not accept negative numbers for any sales figures._

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

Type the 1st quarter sales amount, of the East division please: 3232
Type the 2nd quarter sales amount, of the East division please: 2342
Type the 3rd quarter sales amount, of the East division please: 5454
Type the 4th quarter sales amount, of the East division please: 5645
Type the 1st quarter sales amount, of the West division please: 5645
Type the 2nd quarter sales amount, of the West division please: 7667
Type the 3rd quarter sales amount, of the West division please: 5678
Type the 4th quarter sales amount, of the West division please: 8975
Type the 1st quarter sales amount, of the North division please: 5443
Type the 2nd quarter sales amount, of the North division please: 6665
Type the 3rd quarter sales amount, of the North division please: 9887
Type the 4th quarter sales amount, of the North division please: 2333
Type the 1st quarter sales amount, of the South division please: 5544
Type the 2nd quarter sales amount, of the South division please: 4555
Type the 3rd quarter sales amount, of the South division please: 5444
Type the 4th quarter sales amount, of the South division please: 6676

The East division had an Annual Total Sales of $ 16,673.00 and an Average Quarterly Sales of $ 4,168.25
The West division had an Annual Total Sales of $ 27,965.00 and an Average Quarterly Sales of $ 6,991.25
The North division had an Annual Total Sales of $ 24,328.00 and an Average Quarterly Sales of $ 6,082.00
The South division had an Annual Total Sales of $ 22,219.00 and an Average Quarterly Sales of $ 5,554.75

Process finished with exit code 0
  
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


