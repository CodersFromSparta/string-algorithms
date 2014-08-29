#include<iostream>

using namespace std;
long long int max(long long int a, long long int b)
{
    return a>b?a:b;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int p, q, i , j;
        cin>>p;
        long long int a[p];
        for(i=0; i<p; i++)
        cin>>a[i];

        long long int b[p];
        for(i=0; i<p; i++)
        cin>>b[i];

        int lcs[2][p+1];

        for(i=0; i<=p; i++)
        lcs[0][i]=0;

        for(i=0; i<3; i++)
        lcs[i][0]=0;
        int k, e;
        k=1;

        for(i=1; k<=p;)
        {

            for(j=1; j<=p; j++)
            {
                if(a[k-1]==b[j-1])
                {
                    lcs[1][j]=1+lcs[0][j-1];
                }
                else
                {
                    lcs[1][j]=max(lcs[1][j-1], lcs[0][j]);
                }
            }

            k++;

            for(e=0; e<=p; e++)
            lcs[0][e]=lcs[1][e];

        }

        cout<<lcs[0][p]<<endl;

    }
}
