Solution to LeetCode Problem #200
This C++ code returns the number of islands, represented by '1', given a
2D binary grid (m x n). This code uses BFS to do so by using a queue. The
time complexity is O(r x c) since a nested for loop is used to loop through
all the rows (r) and columns (c) of the 2D grid. The space complexity is the
size of the queue, which is O({r, c}), since the queue takes a pair of integers
(r, c).