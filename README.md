# Test linked lists

These are the tests I use to unit test my implementation for [LinkedLists](https://github.com/hecerinc/data-structures/blob/master/LinkedList.cpp).

It uses [Catch](https://github.com/philsquared/Catch) as a testing framework.


## How to run the tests

1. Clone this repository
2. Put your implementation of linked lists in the same directory. Call it `LinkedList.h` or rename the `#include` in `test.cpp`
	- Remember to include your implementation of `Node<T>` (e.g. `Node.h`) in the same directory or inside `LinkedList.h` (not best practice) 
3. Run

```
$ g++ test.cpp -o test
$ ./test
```

That's it!


## Current tests

- `insertAtIndex(int, T)`
- `isEmpty(void)`
- `[] operator` (get version)
- `push_back(T)`
- `push(T)`: adds value T to the beginning of the list
- `first(void)`: returns the first element of the list
- `size(void)`: returns the length of the list
- `makeEmpty(void)`: empties the list (deleting everything)
- `frontBackSplit(Node<T>** a, Node<T>** b)`: places the first half of the list in a, and the second half in b.
- `pop(void)`: returns and removes the first element on the list

## Assumptions

- The tests assume your linked list class is called `LinkedList` and your linked list node is called `Node`.
- The tests assume you're using templates `<T>`
- You're exposing your linked list head in a `public` `head` attribute in your class


