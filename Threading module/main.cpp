#include <pthread.h>
#include <stdio.h>
#include <string.h>

#include<iostream>
#include <vector>

#define THREAD_MAX 5
#define MAX_RESOURCES 5

pthread_t tid[MAX_RESOURCES];
//pthread_mutex_t lock;

using namespace std;

int functionName(int number)
{
    return number * 2;
}

template <class myData, class funcType>
class baseThreadParameterClass
{
private:
    myData *information;
    int threadCount;
    funcType(*process)(funcType); ///process function added

public:
    baseThreadParameterClass(myData* inf, int tcnt) : information(inf), threadCount(tcnt){}

    void setInformation(myData *inf)
    {
        information = inf;
    }

    void setThreadCount(int tcnt)
    {
        threadCount = tcnt;
    }

    void setProcessFunction(funcType(*f)(funcType))
    {
        process = f;
    }

    void printValue()
    {
        for(int i = 0; i < information->size(); i++)
            cout<<(*information)[i]<<" ";
        cout<<"\n";
        cout<<threadCount<<" ";
    }

    void* processData(void*);
};

///for vector structures
template <class dataType, class infoType>
void* baseThreadParameterClass<dataType, infoType> :: processData(void *args)
{
    int threadId = (int)(args);
    for(int i = 0; i < information->size(); i++)
    {
        if(i % threadCount == threadId)
        {
            (*information)[i] = process((*information)[i]);
        }
    }
    return (void*)information;
}

baseThreadParameterClass<vector<int>, int> *base;

void* intern(void *args)
{
    return base->processData(args);
}

int main()
{
    vector<int> *info = new vector<int>;
    int alfa = 1;
    for(int i = 0; i < 10; i++)
        info->push_back(i);

    base = new baseThreadParameterClass<vector<int>, int>(info, THREAD_MAX);
    base->setProcessFunction(functionName);

    for(int i = 0; i < THREAD_MAX; i++)
    {
        void *response;
        int error = pthread_create(&(tid[i]), NULL, &intern, (void *)i);

        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));

        pthread_join(tid[i], &response);
        base->setInformation((vector<int>*)response);
    }
    base->printValue();
}
