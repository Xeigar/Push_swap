# Push_swap

Magic meets coding!

The aim of this project was to create a program that took integers as arguments and using two stacks and a set of possible moves (see table below) and returns the step by step the moves made to organize the integers. According to the number of moves, the project would have different marks.




| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |


## How does it work?

The arguments passed in the program, if they passed the necessary parameters, are turned into integers and populate ``Stack A``.

The algorith then passes the lower half of the arguments to ``Stack B``, and this step is repeated with the remaining half until ``Stack A`` is sorted or only two numbers remain.

Aftwards the algorithm passes all the numbers in ``Stack B`` and counts the number of moves necessary to place the number at the top of ``Stack B`` and the correct placement for it at the top of ``Stack A``.

The algorithm finds the cheapest option and executes the necessary moves until all the numbers are in ``Stack A``. It then rotates or reverse rotates until the smallest number is in the first position.

## Key take aways 🔑

This project developed my algorithm creation capabilites, since it demanded the implementation of consistent rules that would deliver the best execution in the smallest number of moves everytime.