# File Processing and Lists

## Assignment Instructions

Design a system to keep track of employee data. The system should keep track of an
employee’s name, ID number and hourly pay rate in a class called Employee. You may
also store any additional data you may need, hint, you need something extra. This data is
stored in a file (user selectable) with the id number, hourly pay rate, and the employee’s
full name (example):

```
17 5.25 Daniel Katz
18 6.75 John F. Jones
```

Additionally we would like to be able to print payroll information from data in a different
file. The data is the employee’s id number and a number of hours that they worked
(example):

```
17 40
18 20
18 20
```

As you see we can have the same number listed twice in which case that person should be
paid the sum of the numbers (John Jones did 40 hours work, but it’s listed as 20+20).

You should start by reading in the first file and storing the data as objects in a linked list.
You will need to create the linked list class and the Employee data class. You may
choose to use the Linked List class we created, or you may opt to create your own doubly
linked list class. (Note: if you cannot get either working, you can use the STL list class
but 20% will be deducted). The Linked list could be templated or not, it’s up to you,
however templating it would allow it to be used for other projects, so it might be a good
idea.

Once you have read in the information from the first file, read in the second file.
Ultimately we would like to print payroll information based on the hourly wage from the
first file multiplied by the number of times an employee worked in the second file. How
you do this is entirely up to you.

The output must be in sorted (descending; so the person who gets paid most prints first)
order in the form of:

```
*********Payroll Information********
Daniel Katz, $270
John F. Jones, $210
*********End payroll**************
```
