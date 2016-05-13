//矩阵快速幂 +++ 

struct mat//矩阵结构体，a表示内容，size大小 
{
    int a[105][105],size;
    mat()
    {
        size=0;
        memset(a,0,sizeof(a));
    }
};
void print(mat m)//输出矩阵信息，debug用 
{
    int i,j;
    printf("%d\n",m.size);
    for(i=0;i<m.size;i++)
    {
        for(j=0;j<m.size;j++)printf("%d ",m.a[i][j]);
        printf("\n");
    }
}
int mult(int a,int b,int mod)//自己写大数乘法，利用位运算有效避免int64或者高精度，这里a,b,mod只要不超过2^30就不会出问题 
{
    int exp=a%mod,res=0;
    while(b)
    {
        if(b&1)
        {
            res+=exp;
            if(res>=mod)res-=mod;
        }
        exp<<=1;
        if(exp>=mod)exp-=mod;
        b>>=1;
    }
    return res;
}
mat multi(mat m1,mat m2,int mod)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化 
{
    mat ans=mat();
    int i,j,k;
    for(i=0;i<m1.size;i++)
        for(j=0;j<m2.size;j++)
            if(m1.a[i][j])//稀疏矩阵优化 
                for(k=0;k<m1.size;k++)
                {
                    ans.a[i][k]+=mult(m1.a[i][j],m2.a[j][k],mod);
                    ans.a[i][k]%=mod;
                }
    ans.size=m1.size;
    return ans;
}
mat quickmulti(mat m,int n,int mod)//二分快速幂 
{
    mat ans=mat();
    int i;
    for(i=0;i<m.size;i++)ans.a[i][i]=1;
    ans.size=m.size;
    while(n)
    {
        if(n&1)ans=multi(m,ans,mod);
        m=multi(m,m,mod);
        n>>=1;
    }
    return ans;
}
