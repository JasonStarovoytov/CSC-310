This project is the implementation of all of the hash tables we talked about in class.

The different types of hash tables this implementation includes are as follows:

Vector Chaining
List Chaining
AVL tree Chaining
Linear Probing
Quadratic Probing
Double Hashing

The first three and last three are pretty similar, so they share some of the same code,
but with different variable names.

they all have the same functions, so you are able to:

insert(key, value) ---> inserts a key/value pair into the hash table
search(key, value) ---> searches the hash table for a key, then stores it in the value variable
remove(key)        ---> looks for a key and deletes it from the hash table


I hope my hours of debugging paid off for you to enjoy this implementation!! :>


Below are the benchmark statistics:

Part 6:

After looking at this data, I can truly see the differences between each implementation
of hash tables. A hash table built with linked lists can get a really fast insert 
operation, but deletion can take a while since it is O(n). It is also cool to see that
we can take previous data structures that we have used to make a hash table. Since we 
used AVL trees in one of our implementations, it showed us that depending on the structure
we store our chains in, it can change performance. AVL trees may take up more memory, but
they make insert and search O(log n). 
On the other hand, open addressing can be useful in other situations where the data is
more known. Depending on the hash function, a certain type of probing can be more useful.
In this implementation, it is safe to say that double hashing is one of the slowest for 
any operation. This is because hashing takes a lot of time. My implementation could also 
be optimized to not run hash2() as often, so that could be looked at to help improve 
performance in the future. 
In the end, while this project did take a lot of thinking and problem solving, I really
enjoyed it. Seeing the difference in times helped me understand more about hash tables. 


Here are the benchmarks if you would like to take a look!

                        |
                        |
                        |
                        V

========================================
Benchmarking with data from: data/no_collision_data.txt
========================================

----------------------------------------
Running benchmark for method: 0
----------------------------------------
REHASH70003
Insertion time: 91350 microseconds
Search time: 25113 microseconds
Deletion time: 8 microseconds

Statistics for method: 0
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121431
Max chain length: 6

----------------------------------------
Running benchmark for method: 1
----------------------------------------
REHASH70003
Insertion time: 61483 microseconds
Search time: 21862 microseconds
Deletion time: 8 microseconds

Statistics for method: 1
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121433
Max chain length: 6

----------------------------------------
Running benchmark for method: 2
----------------------------------------
REHASH70003
Insertion time: 79926 microseconds
Search time: 19785 microseconds
Deletion time: 8 microseconds

Statistics for method: 2
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121436
Max chain length: 6

----------------------------------------
Running benchmark for method: 3
----------------------------------------
REHASH70003
Insertion time: 74064 microseconds
Search time: 23254 microseconds
Deletion time: 8 microseconds

Statistics for method: 3
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 4
----------------------------------------
REHASH70003
Insertion time: 77904 microseconds
Search time: 24276 microseconds
Deletion time: 5 microseconds

Statistics for method: 4
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 5
----------------------------------------
REHASH70003
Insertion time: 121092 microseconds
Search time: 33999 microseconds
Deletion time: 10 microseconds

Statistics for method: 5
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for std::unordered_map
----------------------------------------
std::unordered_map Benchmark Results:
Insertion time: 31949 microseconds
Search time: 34056 microseconds
Deletion time: 8 microseconds

========================================
Benchmarking with data from: data/low_collision_data.txt
========================================

----------------------------------------
Running benchmark for method: 0
----------------------------------------
REHASH70003
Insertion time: 81720 microseconds
Search time: 24054 microseconds
Deletion time: 10 microseconds

Statistics for method: 0
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121213
Max chain length: 6

----------------------------------------
Running benchmark for method: 1
----------------------------------------
REHASH70003
Insertion time: 73134 microseconds
Search time: 23519 microseconds
Deletion time: 9 microseconds

Statistics for method: 1
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121213
Max chain length: 6

----------------------------------------
Running benchmark for method: 2
----------------------------------------
REHASH70003
Insertion time: 85731 microseconds
Search time: 21505 microseconds
Deletion time: 8 microseconds

Statistics for method: 2
Total elements: 99990
Load factor: 0.499935
Empty buckets: 121210
Max chain length: 6

----------------------------------------
Running benchmark for method: 3
----------------------------------------
REHASH70003
Insertion time: 81050 microseconds
Search time: 22334 microseconds
Deletion time: 6 microseconds

Statistics for method: 3
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 4
----------------------------------------
REHASH70003
Insertion time: 78932 microseconds
Search time: 23232 microseconds
Deletion time: 4 microseconds

Statistics for method: 4
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 5
----------------------------------------
REHASH70003
Insertion time: 117486 microseconds
Search time: 31956 microseconds
Deletion time: 6 microseconds

Statistics for method: 5
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for std::unordered_map
----------------------------------------
std::unordered_map Benchmark Results:
Insertion time: 31713 microseconds
Search time: 31895 microseconds
Deletion time: 10 microseconds

========================================
Benchmarking with data from: data/high_collision_data.txt
========================================

----------------------------------------
Running benchmark for method: 0
----------------------------------------
REHASH70003
Insertion time: 58843 microseconds
Search time: 20869 microseconds
Deletion time: 8 microseconds

Statistics for method: 0
Total elements: 99990
Load factor: 0.499935
Empty buckets: 120816
Max chain length: 5

----------------------------------------
Running benchmark for method: 1
----------------------------------------
REHASH70003
Insertion time: 51846 microseconds
Search time: 24481 microseconds
Deletion time: 8 microseconds

Statistics for method: 1
Total elements: 99990
Load factor: 0.499935
Empty buckets: 120819
Max chain length: 5

----------------------------------------
Running benchmark for method: 2
----------------------------------------
REHASH70003
Insertion time: 57590 microseconds
Search time: 20766 microseconds
Deletion time: 7 microseconds

Statistics for method: 2
Total elements: 99990
Load factor: 0.499935
Empty buckets: 120820
Max chain length: 5

----------------------------------------
Running benchmark for method: 3
----------------------------------------
REHASH70003
Insertion time: 479935 microseconds
Search time: 76952 microseconds
Deletion time: 5 microseconds

Statistics for method: 3
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 4
----------------------------------------
REHASH70003
Insertion time: 92257 microseconds
Search time: 22693 microseconds
Deletion time: 8 microseconds

Statistics for method: 4
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for method: 5
----------------------------------------
REHASH70003
Insertion time: 102020 microseconds
Search time: 33463 microseconds
Deletion time: 9 microseconds

Statistics for method: 5
Total elements: 100000
Load factor: 0.499985
Empty buckets: 100006

----------------------------------------
Running benchmark for std::unordered_map



----------------------------------------
Running benchmark for std::unordered_map
----------------------------------------
std::unordered_map Benchmark Results:
Insertion time: 29465 microseconds
Search time: 36107 microseconds
Deletion time: 10 microseconds