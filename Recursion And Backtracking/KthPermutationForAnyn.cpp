int fact(int n)
{
    if(n>12)
        return INT_MAX;
    return (n==1 || n==0) ? 1: n * fact(n - 1);
}
// for n>12 , it will overflow the INT_MAX value so take factorial as INT_MAX;
// so we will take after that fac as INT_MAX
string Solution::getPermutation(int n, int k) {
    // elements containg from 1 , 2 , 3 .. n
    // suppose n=6 , 1 , 2 , 3 , 4 , 5 , 6
    // 1 [ 5! permutation]
    // 2 [ 5! permutation]
     // 3 [ 5! permutation]
      // 4 [ 5! permutation]
       // 5 [ 5! permutation]
        // 6 [ 5! permutation]
        // k=400 , we have to first element is 4 , i.e nums[400/5!];
        //k=400%k
        // we will findout the 1st value by nums[k/fac]
        // then for finding the next value , we will erase this current value
        // fac=fac/p , p=5 here , p--;
        // then similarly we will find out the 2nd digit and so on
        // keep on deleting the value from nums , till nums become empty      
        vector<int> nums;
        for(int i=1;i<n;i++)
        {
             nums.push_back(i);            
        }
        nums.push_back(n);
        string ans="";
        int p=n-1;
        int idx;
        k--; // we are finding 0 -based value i.e (0 to 119) for 1 as first , (120 to 239) ->
        // 2 as first number
        // this will make easy to calculate the things
        int fac;
        while(1)
        {         
            fac=fact(p);
            ans = ans + to_string(nums[k/fac]);
            // in nums.erase(it) pass the iterator
            nums.erase(nums.begin() +  (k/fac));
            if(nums.size()==0)
            {
                break;
            }
            k=k%fac;        
           // fac=fac/p;
            p--;
        }
    return ans;
}
