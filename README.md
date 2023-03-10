# Philosophers

This project is a simulation of a dining philosophers problem using threads and mutexes.

- One or more philosophers sit at a round table.
  There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
  While they are eating, they are not thinking nor sleeping;
  while thinking, they are not eating nor sleeping;
  and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
  philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
  start sleeping. Once awake, they start thinking again. The simulation stops when
  a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

## Table of Contents
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Support](#support)
- [Acknowledgments](#acknowledgments)
- [Example Output](#example-output)

## Getting Started

Installing the `philosophers` can be done in a few simple steps:

1. Download the project from the project's GitHub repo.

2. Open a terminal and navigate to the directory where the files were cloned.

3. Run the following command to compile the program:


````
make
````
This will create a `./philo` file in the directory, which is the compiled program that you can test.

## Usage

The program takes the following arguments:

- The number of philosophers at the table (minimum 2, maximum 200).
- The time to die in milliseconds. If a philosopher doesn't start eating before this time is up, it dies.
- The time to eat in milliseconds.
- The time to sleep in milliseconds.
- The program will simulate the dining philosophers problem with the given number of philosophers and time constraints. 
  The output will show the actions taken by each philosopher (thinking, eating, sleeping) and any deaths that occur.

````
./philo 2 410 200 200 
````

## Example Output

3<img width="849" alt="Screenshot 2023-03-10 at 7 17 02 PM" src="https://user-images.githubusercontent.com/59938530/224353546-d915e505-f308-4d21-91fc-9c4a1d1c68ae.png">


## Support

Feel free to contact me on slack or via email

email - `tehuanmelo@gmail.com`

twitter - `@tehuanmelo`

slack - `tde-melo`

## Acknowledgments
I would like to express my sincere gratitude to @42AbuDhabi , and all of the staff members and who have supported me throughout my journey here.
