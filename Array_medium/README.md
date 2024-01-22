### vector of STL

```C++
vector<int> function_name(vector<int> &v,int target){
vector<int> vec;
vec.push_back(1);
return vec;
//return {1,2};
}
```

### map of STL

it follows key-value pair, key can be anything (datatype) and value can be anything(anything)

```C++
map<int,int>;
map<string,int>;
map<string,string>;

map.find(key)!==map.end(); // it finds that either the key is present in the array or not.

map[value] = key;
cout<<map[key]<<"returns value";



```

### Pair of STL

```C++
pair<int,int> function_name(vector<int> &v,int target){
return make_pair(i,j);
```

##### The C++ Standard Template Library (STL) provides a rich set of data structures and algorithms that make it easier for developers to work with common data manipulation tasks. Here are some of the key data structures in the C++ STL:

```c++

Vector (std::vector):
Dynamic array that can grow or shrink in size.
Elements are stored in contiguous memory.
cpp
Copy code
#include <vector>
std::vector<int> myVector = {1, 2, 3, 4, 5};
```

```c++

Doubly-linked list.
Allows constant time insertions and removals.
cpp
Copy code
#include <list>
std::list<int> myList = {1, 2, 3, 4, 5};
```

```c++
Deque (std::deque):

Double-ended queue.
Supports fast insertion and deletion at both ends.
cpp
Copy code
#include <deque>
std::deque<int> myDeque = {1, 2, 3, 4, 5};
```

```c++

Queue (std::queue):

Queue container adapter.
Uses deque or list as the underlying container.
cpp
Copy code
#include <queue>
std::queue<int> myQueue;

```

```c++
Stack (std::stack):

Stack container adapter.
Uses deque or list as the underlying container.
cpp
Copy code
#include <stack>
std::stack<int> myStack;
```

```c++
Set (std::set):

Sorted, unique set of elements.
Implemented as a self-balancing binary search tree (usually Red-Black Tree).
cpp
Copy code
#include <set>
std::set<int> mySet = {1, 2, 3, 4, 5};
```

```c++
Map (std::map):

Associative container that stores key-value pairs.
Implemented as a self-balancing binary search tree (usually Red-Black Tree).
cpp
Copy code
#include <map>
std::map<std::string, int> myMap;

```

```c++

Unordered version of std::set.
Implemented as a hash table.
cpp
Copy code
#include <unordered_set>
std::unordered_set<int> myUnorderedSet = {1, 2, 3, 4, 5};
Unordered Set (std::unordered_set):

```

```c++

Unordered Map (std::unordered_map):

Unordered version of std::map.
Implemented as a hash table.
cpp
Copy code
#include <unordered_map>
std::unordered_map<std::string, int> myUnorderedMap;



```

```c++

Priority Queue (std::priority_queue):

Priority queue container adapter.
Uses a heap as the underlying container.
cpp
Copy code
#include <queue>
std::priority_queue<int> myPriorityQueue;


```

These are just some of the key data structures available in the C++ STL. Each of them comes with a variety of member functions and iterators, providing a convenient and efficient way to work with different types of data.
