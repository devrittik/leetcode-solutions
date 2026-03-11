class Solution {
public:
    int clumsy(int n) {
        int ans=0;
        int chunk;
        int j=1;
        for(int i=n; i>=1; i--){
            switch(j){
                case 1:
                    if(i==n){
                        chunk=-i;
                    }else{
                        chunk=i;
                    }
                    break;
                case 2:
                    chunk*=i;
                    break;
                case 3:
                    chunk/=i;
                    break;
                case 4:
                    chunk-=i;
                    ans-=chunk;
                    chunk=0;
                    j=0;
                    break;
            }
            j++;
        }

        ans-=chunk;

        return ans;
    }
};