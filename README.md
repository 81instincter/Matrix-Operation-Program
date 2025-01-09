# Matrix-Operation-Program
My end of semester project in 2024 for my computer algorithms class where we created a Matrix calculator program to display our understanding of C++ classes, data types, and dynamic memory allocation.

How the program works is that a C++ object of the object class "Matrix", as defined in the matrix.h and matrix.cpp files, are created by the user via a user interface in the terminal. 
In the terminal, the user has 10 different options, the first half being how the Matrix-type object is to be created (default constructor, parameterized constructor), what matrix operations
can be peformed on the Matrix-type objects, . The resulting objects are then appended to a vector in the C++ program. Additionally, the matrices used in the matrix operations, and the resulting matrix, are then pasted in a .csv file named results.csv in the appropriate format which replicates the matrices' actual dimensions.


Note:
The program works extremely well,  making me very proud of it, it does have one tiny - but not program-breaking - bug in it. If a user attempts to do a matrix operation with the incorrect dimensions, no Matrix-type objects will be added to the vector containing the Matrix objects, but the name relating to the Matrix-type object will still be appended to the vector containing the names of the matrices, despite there being no matrix corresponding to it. When the user selections option
