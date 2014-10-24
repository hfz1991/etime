etime
=====

A small simulated e-time program

Develop a C program that ask the user to enter two integers. The first integer value 
represents a time of day on a 24-hour clock, e.g., 1345 represents quarter to two mid-day. The second integer 
represents time duration in a similar way, e.g., 345 represents 3 hours and 45 minutes. Note that, 2520 and 2372 
are not valid time of day. Note also that 2372 is not valid time duration, but 2520 is valid time duration. The 
time duration can be positive or negative. Your program should loop until getting a valid time of day and a time 
duration. 
The program will add the time duration to the time of day, and the result is printed out in the same notation 
(always as a valid 4 digit time). For example, in the above case, the answer should be 1730, which is the time at 
3 hours and 45 minutes after 1345. You should consider cases like: starting time is 2300 and duration is 200. In 
this case, the end time will be 0100, not 2500. 
Add as many inline comments in your program as you can to make it well documented and easy to be 
understood by anyone who reads it. 
