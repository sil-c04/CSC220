Solution to LeetCode Problem #416
This C++ code uses dynamic programming with the bottom-up approach to 
determine if a given integer array can be partitioned into two equal subsets.
This code has a time complexity of O(nW), where W represents the target sum
of one subset. This time complexity comes from the nested loop with the outer loop
looping until n and the inner loop looping until W, giving us O(nW).