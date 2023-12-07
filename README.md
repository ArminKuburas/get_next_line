# get_next_line


## Description
This repository will hold all my work in regards to the get next line project. This is a project where we have to make a function that is able to read a file descriptor (a text file) and returns the next line within it that it has not returned yet. There is also the bonus one which can handle multiple file descriptors. 


## Table of Contents

- [get_next_line](#get_next_line)
- [Description](#Description)
- [Knowledge Gained](#Knowledge-Gained)
- [Installation](#Installation)
- [Usage](#usage)
- [Inspirations And Thank Yous](#inspirations-and-thank-you)

### Knowledge-Gained
1.  One of the first things I learnt about from this project has to be what static variables are.  A static variable is a variable that retains its value between function calls and has a scope limited to the file in which it is declared.
      - for example in my case I used one to store everything that read would read. I would use read within a loop  , save the data inside of a buffer and later combine the buffer and the static variable through strjoin.
      - This has also some combination to do with static functions. Although what I know about those is that they are limited to the source file they are in.
      - So why static? The term "static" is used because these variables and functions are associated with the static storage class, which means that their memory allocation and deallocation occur at compile time, and their values persist between function calls.
      - Basically they allow you to limit the scope and usage of certain functions and variables and they retain information that you can use again and again in later calls.
2.   Continuing from the things I learnt from the printf project I made sure to think about what I have to do before working on it. I spent a day or two just considering my options, thinking about solutions, how to do it, etc. because I knew that I would not know if it works until I finished it.
3.   I learnt more about file descriptors and how they function.
