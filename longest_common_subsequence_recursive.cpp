#include<iostream>

using namespace std;

int max(int a, int b)
{
    return a>b?a:b;
}

int lcs(char a[], char b[], int m, int n)
{
    if(m==0 || n==0)
    return 0;

    if(a[m-1]==b[n-1])
        return 1+lcs(a, b, m-1, n-1);
    else
        return max(lcs(a, b, m-1, n), lcs(a, b, m, n-1));
}

int main()
{
    char a[100], b[100];
    cout<<"\nEnter string 1 : ";
    cin>>a;
    cout<<"\nEnter string 2 : ";
    cin>>b;
    int m, n;
    for(m=0; a[m]; m++);
    for(n=0; b[n]; n++);

    cout<<"\nLCS of these two strings is : "<<lcs(a, b, m, n);
    return 0;
}
