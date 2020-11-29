    ///int error;
    //res *test;
    vector<int> *v = new vector<int>;

    for(int i = 0; i < 10; i++)
    {
            (*v).push_back(i);
            //cout<<i<<" ";
    }
        //test->seq.push_back(i * 3 + 5);

    for(int i = 0; i < v->size() - 1; i++) /*test->seq.size() - 1*/
        //cout<<test->seq[i]<<" ";
      cout<<(*v)[i]<<" ";
    cout<<"\n";
    /*if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }*/

    void *response;
    for(int i = 0; i < THREAD_MAX; i++)
    {
        error = pthread_create(&(tid[i]), NULL, &applyToVector, (void *)v);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        pthread_join(tid[i], &response);
    }
    /*test->seq.size() - 1*/
    //test = (res*)response;
    vector<int> *result = (vector<int>*)response;
    for(int i = 0; i < result->size() - 1; i++)
        cout<<(*result)[i]<<" ";

        //cout<<test->seq[i]<<" ";
    //pthread_mutex_destroy(&lock);

    return 0;
