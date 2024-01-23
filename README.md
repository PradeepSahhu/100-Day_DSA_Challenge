# 100-Day_DSA_Challenge

This is promise to myself that from today 19-jan onwards,i will daily solve DSA Problem and try my best to achieve my dreams.

## Day Log

|                                                                                                                          Date                                                                                                                          |   Day    |  Topics  |                                                                       Discription                                                                       |                                                                                                                                                                                                                                                                                    Learning outcome                                                                                                                                                                                                                                                                                     |
| :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :------: | :------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|                                                                                                                    date:2024-01-20                                                                                                                     | Saturday | `Arrays` |                                                  How to find the longest length of subarray equal to k                                                  | Learned three approaches <br>`1. Brute force` - using three for loops inside each other <br> `2. Better approach` - Used the hashmap (map) to find the sum and checking if sum-k is present int the map if it is then recalculating the length of the subarray. used the ` mpp[sum] = i` that is setting the sum as key and index as value <br>`3. Optimum approach` - used the two pointer approach, continue to move the right pointer and add its value to sum. if the sum == k then move the left pointer from the left-- and sub the value from the sum and recalculate the length |
|                                                                                                                    date:2024-01-21                                                                                                                     |  Sunday  | `Arrays` |                                                       Solved the medium level quesiton on arrays                                                        |                                                                                                                                                                                                                                                      Learned to solve question using the c++ STLs and practice some more concepts.                                                                                                                                                                                                                                                      |
|                                                                                                                    date:2024-01-22                                                                                                                     |  Monday  | `Arrays` |                                                solved sorting 0,1,2s using dutch national flag algorithm                                                |                                                                                                                                    There are three approaches to sort this 0,1,and 2s 1. using normal sortign algorithm like merge sort. with O(n log n) 2. using counting like count all zeroes, ones, and twos then in antother loop assign that number of zeroes , ones and twos. O(2n) 3. approach was using this dutch national flag algorithm                                                                                                                                     |
|                                                                                                                   date : 2024-01-23                                                                                                                    | Tuesday  | `Arrays` | Maximum sum of Subarray consisting of negative as well as positive numbers by using kadene's Algorithm <br> Stocks buy and sell for the maximum profit. |                                                                                                                    kadene's Algorithm checking if the current maximum is smaller than the local maximum sum if yes then assign it to the current maximum sum. global maximum check if the global maximum is smaller than the current maximum sum if yes then assign it. in the end just print or return the global maximum sum for the maximum sum of the subarray.                                                                                                                     |
| we can also return the positions of the sub array by taking three variables `start, ansStart, ansEnd` , assign the start = i if the sum = 0 and if the global max is being updated assign the ansStart = start and ansEnd = i ( that is current index) |

Last Updated: 2024-01-23
