    map<int,int> d;
    int tribonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        else if(n==1 or n==2)
        {
            return 1;
        }
        else if(d[n]>0)
        {
            return d[n];
        }
        else{
            d[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
            return d[n];
        }
    }
