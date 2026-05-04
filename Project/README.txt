Welcome to my final assignment

this project contains 4 implementations of data structures
    - persistant bst with node copying
    - persistant bst with shared pointers
    - persistant bst with fat nodes
    - and a persistant queue

what I did was implement deletion in the first 2 bst's, and I created my 
own implementation if persistant bst's with fat nodes. Lastly, the persistant
queues were implemented with lazy logic, so when the front is empty, that is 
when it reverses the rear. 

The makefile compiles all of the files and makes them executable.

Task 4:

different persistant strategies are good in their own fields. 

Partial persistance is good when you need to be able to see the history and 
making edits to previous history is not possible. It is faster than other forms
since it does not have to make a copy of the entire structure. Since it does not have to 
make a copy, it can share pointers to objects, and reusing these elements makes the 
program take less space. That is why partial persistance is good in a lot of cases.

Full persistance is good in a lot of things as well. If you make a lot of edits and 
need to go back to a previous state, full persistance is for you. Although that is a plus
about it, there are a lot of downsides. You need to make full copies in order to save every
state. This causes two things: the time complexity gets really slow and the space complexity
gets out of control. That is why although they do have some big pros, there are a lot of cons as well. 