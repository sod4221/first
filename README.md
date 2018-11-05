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

## Flow
- Borrow
	1. resource existance check-> error number : 1
		- function : check_name(declared in resource class)
	2. member check (whether exceed or not by function named check_name) -> error number : 2
		- function : check_name(declared in member class)
		- this function is for all members, but error(Exceed error) check is for only undergraduate
	3. member check (already borrow this resource or not by function named "check_borrow") -> error number : 4
		- function : check_borrow(declared in member class)
	3. resource borrowed check (whether borrowed already or not) -> error number : 5
		- function : check_borrow(declared in resourec)
	4. restrict check(by check_delay) -> error number : 6
		- function :check_delay(declared in only undergraduate class)

- Return
	1. resource existance check -> error number : 1
		- function : check_name(declared in resource class)
	2. borrowed check and delay check -> error number is 3 and 7
		- function : return_resource(declared in member and redeclared in undergraduate)
		- Error 7 is only for undergraduate

----------------------------------------------------------------

## How to compile

- It is simple. Just type this command `make`

## How to use

	1. When you type "make" you get compile result named "main"
	2. Before you run "main" file,  you need files named "input.dat" and "resource.dat"
	3. After running "main", you get output file named "output.dat" 

## How to remove

- If you want to remove compile byproduct and product(named "main"), you just type `% make clean`

--------------------------------------------------------------
- This project is made in Ubuntu 18.04.1 LTS
---------------------------------------------------------------
