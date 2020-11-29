#include<iostream>

using namespace std;

double doubleNumber(double elem)
{
    return elem / 2;
}

double value(double (*functocall)(double), double wsum)
{
    double g;
    g = functocall(wsum);
    return g;
}

int main()
{
    cout<<value(doubleNumber, 23.2);
}
/**||=== Build file: "no target" in "no project" (compiler: unknown) ===|
C:\Users\40747\Desktop\Project\Threading Module\Threading module\main.cpp||In function 'int main()':|
C:\Users\40747\Desktop\Project\Threading Module\Threading module\main.cpp|102|error: cannot convert 'baseThreadParameterClass<myData, funcType>::processData<std::vector<int>, int>' from type 'void* (baseThreadParameterClass<std::vector<int>, int>::)(void*)' to type 'void* (*)(void*)'|
||=== Build failed: 1 error(s), 0 warning(s) (0 minute(s), 0 second(s)) ===|
**/
