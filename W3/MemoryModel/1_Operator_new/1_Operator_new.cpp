#include <iostream>
#include <string>

using namespace std;

int main()
{
   /* string* s = new string;
    *s = "Hello";
    std::cout << *s << ' ' << s->size() << endl;
    string& s_ref = *s;
    s_ref += ", world!";
    cout << *s;*/

    int* pInt = new int(42);
    cout << *pInt << endl;
}