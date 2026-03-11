class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        
        pair<int, int> fib={0, 1};
        for(int I=1; I<n; I++){
            fib.second+= fib.first;
            swap(fib.first, fib. second);
        }

        return(fib.first+fib.second);
    }
};