#include <bits/stdc++.h>
#include "./include/Stack.hpp"

using namespace std;

int main()
{
    Stack st;

    

    st.push(194);
    st.push(103);
    st.push(1203);
    st.push(10);

    cout << st.pop() << '\n';

    cout << st.top() << '\n';

    cout << st.size() << '\n';

    cout << (st.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << '\n';
    
    return 0;
}