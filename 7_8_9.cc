//8 9 10这三题都是递推了，p.s.动态规划


/*
题目描述:跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution {
public:
    int jumpFloor(int n) {
        int *dp=new int[n+10]();
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i-1>=0) dp[i]+=dp[i-1];
            if(i-2>=0) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};


/*
题目描述:变态跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

//推公式，then快速幂
class Solution {
public:
    int jumpFloorII(int n) {
        return qPow(2,n-1);
    }
    int qPow(int a,int b){
        int ret=1;
        while(b){
            if(b&1) ret*=a;
            a*=a;
            b>>=1;
        }
        return ret;
    }
};

/*
题目描述:矩形覆盖
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int n) {
        int *dp=new int[n+10]();
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i==1) dp[i]+=dp[i-1];
            else dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

