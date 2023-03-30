map<int,int> d;
int fib(int n) {
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    if(d[n]==0)
    {
        d[n]=fib(n-1)+fib(n-2);
    }
    return d[n];
}
