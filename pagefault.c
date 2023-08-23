#include<stdio.h>
#include<conio.h>
int n,m,a[20],p[10];
void fifo()
{
    int i,j,flag,cnt=0,k=0;
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=0;j<m;j++)
        {
            if(a[i]==p[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cnt++;
            p[k]=a[i];
            k=(k+1)%m;
        }
    }
    printf("\nFIFO-Page faults=%d",cnt);
}
void optimal()
{
    int i,j,flag,cnt=0,k=0,t,temp,f,help[10],ct;
    for(i=0;i<n;i++)
    {
        flag=1,f=1,ct=0;
        for(j=0;j<m;j++)
        {
            help[j]=0;
            if(a[i]==p[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cnt++;
            for(j=0;j<m;j++)
            {
                if(p[j]==-1)
                {
                    p[j]=a[i];
                    f=0;
                    break;
                }
            }
            if(f==1)
            {
                for(k=i+1;k<n;k++)
                {
                    for(j=0;j<m;j++)
                    {
                        if(p[j]==a[k]&&help[j]==0)
                        {
                            temp=j;
                            help[j]=1;
                        }
                    }
                }
                for(j=0;j<m;j++)
                {
                    if(help[j]==0)
                    temp=j;
                }
                p[temp]=a[i];
            }
        }
    }
    printf("\nOPTIMAL-Page faults=%d",cnt);
}
void lru()
{
    int flag,f,k,cnt=0,i,j,temp,ct,help[10];
    for(i=0;i<n;i++)
    {
        flag=1,f=1,ct=0;
        for(j=0;j<m;j++)
        {
            help[j]=0;
            if(p[j]==a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cnt++;
            for(j=0;j<m;j++)
            {
                if(p[j]==-1)
                {
                    p[j]=a[i];
                    {
                        f=0;
                        break;
                    }
                }
            }
            if(f==1)
            {
                for(k=i-1;k>=0;k--)
                {
                    for(j=0;j<m;j++)
                    {
                        if(p[j]==a[k]&& help[j]==0)
                        {
                            temp=j;
                            help[j]=1;
                        }
                    }
                }
                p[temp]=a[i];
            }

        }

    }
    printf("\nLRU-Page faults=%d",cnt);
}
void main()
{
    int i;
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("\nEnter the page numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the number of frames:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
        p[i]=-1;
    fifo();
    for(i=0;i<m;i++)
        p[i]=-1;
    optimal();
    for(i=0;i<m;i++)
        p[i]=-1;
    lru();
}
