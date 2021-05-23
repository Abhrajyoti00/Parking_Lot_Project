# Problem Statement (Parking Lot)

I own a multistorey parking lot that can hold up to 'n' cars at any given point in time. Each slot is given a number starting at 1 increasing with increasing distance from the entry point in steps of one. I want to create an automated ticketing system that allows my customers to use my parking lot without human intervention. 

When a car enters my parking lot, I want to have a ticket issued to the driver. The ticket issuing process includes us documenting the registration number (number plate) and the colour of the car and allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are nice enough to always park in the slots allocated to them). The customer should be allocated a parking slot which is nearest to the entry. At the exit the customer returns the ticket which then marks the slot they were using as being available.

Due to government regulation, the system should provide me with the ability to find out:

● Registration numbers of all cars of a particular colour.

● Slot number in which a car with a given registration number is parked.

● Slot numbers of all slots where a car of a particular colour is parked.


We interact with the system via a simple set of commands which produce a specific output. Please take a look at the example below, which includes all the commands you need to support - they're self explanatory. The system should allow input in two ways. Just to clarify, the same codebase should support both modes of input - we don't want two distinct submissions.

1) It should provide us with an interactive command prompt based shell where commands can be typed in
2) It should accept a filename as a parameter at the command prompt and read the commands from that file


# Output Format


### Example: File Input

To compile the program and convert the source code to an Object file (here proc_input):
```sh
$ g++ proc_input.cpp -o proc_input
```
To run the code so that it accepts input from file_inputs.txt file:

```sh
$ ./proc_input file_inputs.txt
```

Input (in file):

```sh

create_parking_lot 6

park KA-01-HH-1234 White

park KA-01-HH-9999 White

park KA-01-BB-0001 Black

park KA-01-HH-7777 Red

park KA-01-HH-2701 Blue

park KA-01-HH-3141 Black

leave 4

status

park KA-01-P-333 White

park DL-12-AA-9999 White

registration_numbers_for_cars_with_colour White

slot_numbers_for_cars_with_colour White

slot_number_for_registration_number KA-01-HH-3141

slot_number_for_registration_number MH-04-AY-1111
```

Output (to console, newline after every output):

```sh

Created a parking lot with 6 slots

Allocated slot number: 1

Allocated slot number: 2

Allocated slot number: 3

Allocated slot number: 4

Allocated slot number: 5

Allocated slot number: 6

Slot number 4 is free

Slot No.        Registration No         Colour

1              KA-01-HH-1234            White

2              KA-01-HH-9999            White

3              KA-01-BB-0001            Black

5              KA-01-HH-2701            Blue

6              KA-01-HH-3141            Black

Allocated slot number: 4

Sorry, parking lot is full

KA-01-HH-1234, KA-01-HH-9999, KA-01-P-333

1, 2, 4

6

Not found
```


### Example: Interactive

To run the program in the shell (interactively):

```sh
$ ./proc_input
```

Assuming a parking lot with 6 slots, the following commands should be run in sequence by typing them in at a prompt and should produce output as described below the command. 

Note that "exit" terminates the process and returns control to the shell.

Input:

```sh
$ create_parking_lot 6
```

Output:

```sh
Created a parking lot with 6 slots
```

Input:

```sh
$ park KA-01-HH-1234 White
```

Output:

```sh
Allocated slot number: 1
```

Input:

```sh
$ park KA-01-HH-9999 White
```

Output:

```sh
Allocated slot number: 2
```

Input:

```sh
$ park KA-01-BB-0001 Black
```

Output:

```sh
Allocated slot number: 3
```

Input:

```sh
$ park KA-01-HH-7777 Red
```

Output:

```sh
Allocated slot number: 4
```

Input:

```sh
$ park KA-01-HH-2701 Blue
```

Output:

```sh
Allocated slot number: 5
```

Input:

```sh
$ park KA-01-HH-3141 Black
```

Output:

```sh
Allocated slot number: 6
```

Input:

```sh
$ leave 4
```

Output:

```sh
Slot number 4 is free
```

Input:

```sh
$ status
```

Output:

```sh
Slot No.        Registration No         Colour

1              KA-01-HH-1234            White

2              KA-01-HH-9999            White

3              KA-01-BB-0001            Black

5              KA-01-HH-2701            Blue

6              KA-01-HH-3141            Black
```

Input:

```sh
$ park KA-01-P-333 White
```

Output:

```sh
Allocated slot number: 4
```

Input:

```sh
$ park DL-12-AA-9999 White
```

Output:

```sh
Sorry, parking lot is full
```

Input:

```sh
$ registration_numbers_for_cars_with_colour White
```

Output:

```sh
KA-01-HH-1234, KA-01-HH-9999, KA-01-P-333
```

Input:

```sh
$ slot_numbers_for_cars_with_colour White
```

Output:

```sh
1, 2, 4
```

Input:

```sh
$ slot_number_for_registration_number KA-01-HH-3141
```

Output:

```sh
6
```

Input:

```sh
$ slot_number_for_registration_number MH-04-AY-1111
```

Output:

```sh
Not found
```

Input:

```sh
$ exit
```

### Example: Menu - Driven

Compile the Program and convert it to object file:

```sh
$ g++ parking_lot_menudriven.cpp -o parking_lot_menudriven
```

To Run the Program:

```sh
$ ./parking_lot_menudriven
```

#### Output: 

```sh

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 1
 To create_parking_lot
Enter no of slots: 
3
Created a parking lot with 3 slots

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 2
 To park
Enter reg_no and color: 
KA-01-HH-1234 White
Allocated slot number is: 1

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 2
 To park
Enter reg_no and color: 
KA-01-HH-9999 White
Allocated slot number is: 2

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 2
 To park
Enter reg_no and color: 
KA-01-BB-0001 Black
Allocated slot number is: 3

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 4
To display status: 
Slot No.        Registration No         Colour 
  1             KA-01-HH-1234           White
  2             KA-01-HH-9999           White
  3             KA-01-BB-0001           Black


**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 3
 To leave
Enter slot: 
2
Slot number 2 is free

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 2
 To park
Enter reg_no and color: 
KA-01-HH-3141 Black
Allocated slot number is: 2

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 4
To display status: 
Slot No.        Registration No         Colour 
  1             KA-01-HH-1234           White
  2             KA-01-HH-3141           Black
  3             KA-01-BB-0001           Black


**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 5
To display registration_numbers_for_cars_with_colour
Enter car color: 
Black
Registration numbers matching the given color are: 
KA-01-BB-0001, KA-01-HH-3141

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 6
 To display slot_numbers_for_cars_with_colour 
Enter color: 
White
The slot numbers matching the given color are: 
1

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 7
 To display slot_number_for_registration_number 
Enter registration_number: 
KA-01-HH-3141
Slot numbers are: 
2

**************MENU**************
1. To create parking lot
2. To park cars
3. To leave
4. To display status
5. To display registration_numbers_for_cars_with_colour
6. To display slot_numbers_for_cars_with_colour 
7. To display slot_number_for_registration_number
8. To Clear Screen
9. To EXIT

Enter your choice: 8

// Clears Screen

Enter your choice: 9
Exiting!..

```

### Project Requirements

1. C++14 and above.
2. Linux

