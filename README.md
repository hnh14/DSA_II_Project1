# Data Structures and Algorithms II
User's Manual - Project I

This project creates an externally chained hash table to efficiently store and lookup userids and passwords. The program starts by generating a randomized password for each last name listed in "lastNames.txt". It then writes two seperate files conataining the user ids and passwords. One is encrypted, the other is not. The passwords are encrypted using a Vigenere Cipher. The program then stores the encyrypted passwords in the hash table. Finally the program will check that the encrypted passwords can be searched using only the userids.

The Hash Table can insert and search in O(n) time

Setup and Compilation
1. Download and unzip the submission from eLearning on a Linux box in the multi-platform lab.
2. The submission includes:
user.hpp (Header file for User class)
user.cpp (CPP file for User class)
list.hpp (Header file for List class)
list.cpp (CPP file for List class)
vigenere.hpp (Header file for Vigenere class)
viginere.cpp (CPP file for Vigenere class)
passgen.hpp (Header file for PassGen class)
passgen.cpp (CPP file for PassGen class)
hashtable.hpp (Header file for HashTable class)
hashtable.cpp (CPP file for HashTable class)
UserManual.docx (this file)
UML.jpg (UML Class diagram)
lastNames.txt (Text File with list of last names)

3. Environment: This program has been tested in the multi-platform lab and will run there.

4. Compiling. This program includes a Makefile. At the command line in Linux, 
    type make main. The program produces an executable entitled main

Running the program. Be sure all included files are in the same directory as the executable. Issue the command ./main   No command line arguments are required or checked.

User input: no user interaction with the program is required.

Output: All output goes to the console. Output will be similar to this:

Userid      Password   Attempted  Result
SMITH       asdfvfrty  asdfvfrty  match 
JOHNSON     okmnjuygt  okmnjuygt  match 
WILLIAMS    yhnbgtrde  yhnbgtrde  match 
JONES       wsxzaqwer  wsxzaqwer  match 
BROWN       bhvfgtyui  bhvfgtyui  match


