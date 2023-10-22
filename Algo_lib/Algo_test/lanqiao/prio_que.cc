//////////////////////////////////////////////////////////////////////
// Compile options needed: /GX
// <filename> : priority_queue.cpp
// Functions:
// priority_queue::push(), priority_queue::pop(),
// priority_queue::empty(), priority_queue::top(), queue::size()
// of Microsoft Product Support Services,
// Copyright (c) 1996 Microsoft Corporation. All rights reserved.
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <functional>
using namespace std;

#if _MSC_VER > 1020 // if VC++ version is > 4.2
    using namespace std; // std c++ libs implemented in std
#endif

// Using priority_queue with deque
// Use of function greater sorts the items in ascending order
typedef deque<int, allocator<int> > INTDQU;
typedef priority_queue<int,INTDQU, greater<int> > INTPRQUE;

// Using priority_queue with vector
// Use of function less sorts the items in descending order
typedef vector<char, allocator<char> > CHVECTOR;
typedef priority_queue<char,CHVECTOR,less<char> > CHPRQUE;

int main(void)
{
    int size_q;
    INTPRQUE q;
    CHPRQUE p;

    // Insert items in the priority_queue(uses deque)
    q.push(42);
    q.push(100);
    q.push(49);
    q.push(201);

    // Output the item at the top using top()
    cout << q.top() << endl;
    // Output the size of priority_queue
    size_q = q.size();
    cout << "size of q is:" << size_q << endl;
    // Output items in priority_queue using top()
    // and use pop() to get to next item until
    // priority_queue is empty
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    // Insert items in the priority_queue(uses vector)
    p.push('c');
    p.push('a');
    p.push('d');
    p.push('m');
    p.push('h');

    // Output the item at the top using top()
    cout << p.top() << endl;

    // Output the size of priority_queue
    size_q = p.size();
    cout << "size of p is:" << size_q << endl;

    // Output items in `priority_queue`using top()
    // and use pop() to get to next item until
    // `priority_queue`is empty
    while (!p.empty())
    {
        cout << p.top() << endl;
        p.pop();
    }
}