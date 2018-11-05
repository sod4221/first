# library management

## class hierarchy

- library
	- member
		- undergraduate
		- graduate
		- faculty

	- resource
		- book
		- magazine
		- e_book

- Flow
	- Borrow
		1.resource existance check (function named check_name)
		2.undergraduate check (whether exceed or not by function named check_name)
		3.undergraduate check (already borrow this resource or not)
		3.resource borrowed check (whether borrowed already or not by function named check_borrow)
		4.restrict check(by check_delay)

	- Return
		1.resource existance check(function named check_name)
		2.borrowed check and delay check(borrowed or not by function named return_resource)

----------------------------------------------------------------

# how to compile

- It is simple. Just type this command
```
'make'
```
	- When you type "make" you get compile result named "main"
	- Before you run "main" file,  you need files named "input.dat" and "resource.dat"
	- After running "main", you get output file named "output.dat" 

- If you want to remove compile byproduct and product(output.dat and main), you just type
```
% make clean
```
--------------------------------------------------------------
- This project is made in Ubuntu 18.04.1 LTS
---------------------------------------------------------------
