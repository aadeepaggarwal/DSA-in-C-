#include <iostream>
#include <queue>// FIFO

using namespace std;
int main() {
    queue <int> q;
    q.push(1);
    q.push(2);
q.push(3);
q.push(4);
q.push(5);

while (!q.empty())
{
    cout<<q.front();
    q.pop();
}
    return 0;
}