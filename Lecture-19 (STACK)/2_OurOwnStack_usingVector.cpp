#include <iostream>
using namespace std;
#include <vector>
template <typename T>
class Stack
{

   vector<T> v; /* it is private because class ke bahar isey access nahi kar sakte*/
public:
   void push(T d)
   {
      v.push_back(d);
   }
   void pop()
   {
      v.pop_back();
   }
   bool empty()
   {
      return v.size() == 0;
   }

   int top()
   {
      return v[v.size() - 1]; // kyonki 0 based indexing hai stack ki and size se total size ayega and -1 karo for last index
   }
};
using namespace std;
int main()
{
   // template bana tha isilye ab ham stack normally <int> use kar sakte hain
   Stack<int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);

   while (!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
   return 0;
}