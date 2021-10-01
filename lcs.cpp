#include<iostream>
#include<string>
using namespace std;

string check_lcs(string str1, string str2)
{
    int l1=str1.size();
    int l2=str2.size();
    str1=" "+str1;
    str2=" "+str2;
    int lcs[l1+1][l2+1];

    for(int i=0;i<=l1;i++)
    {
        lcs[i][0]=0;
    }

    for(int i=0;i<=l2;i++)
    {
        lcs[0][i]=0;
    }

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(str1[i]!=str2[j])
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
            else
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
        }
    }
    int res=lcs[l1][l2];
    int sm=min(l1,l2);
    if(res==sm)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}


int main()
{
    string str1,str2;
    int l1,l2;
    cin>>str1;
    cin>>str2;

    cout<<check_lcs(str1,str2);

    return 0;
}
