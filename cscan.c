#include<stdio.h>
#include<stdlib.h>
int main()
{
        int RQ[100],i,j,n,THM=0,intial,size,move;
        printf("Enter the number of requests : \n");
        scanf("%d",&n);
        printf("\nEnter the requests sequence : ");

        for(i=0;i<n;i++)
        {
                scanf("%d",&RQ[i]);
        }

        printf("Enetr the Intial Head position : ");
        scanf("%d",&intial);
        printf("Enter the total disk size : ");
        scanf("%d",&size);
        printf("Enter the  head movement direction for high 1 & for low 0  : ");
        scanf("%d",&move);

        for(i=0;i<n;i++)
        {
           for(j=0;j<n-i-1;j++)
              {
               if(RQ[j]>RQ[j+1])
                  {

                        int temp;
                        temp=RQ[j];
                        RQ[j]=RQ[j+1];
                        RQ[j+1]=temp;
                }

          }

        }

        int index;
        for(i=0;i<n;i++)
        {
                if(intial<RQ[i])
                {
                        index=i;
                        break;
                }
        }

        if(move==1)
        {
                for(i=index;i<n;i++)
                {
                        THM=THM+abs(RQ[i]-intial);
                        intial=RQ[i];
                }
                THM=THM+abs(size-RQ[i-1]-1);
                THM=THM+abs(size-1-0);
                intial=0;

                for(i=0;i<index;i++)
                {
                         THM=THM+abs(RQ[i]-intial);
                         intial=RQ[i];
                }
        }


         else

        {

                for(i=index-1;i>=0;i--)
                {
                         THM=THM+abs(RQ[i]-intial);
                         intial=RQ[i];
                }

                THM=THM+abs(RQ[i+1]-0);
                intial=0;
                for(i=index;i<n;i++)
                {

                         THM=THM+abs(RQ[i]-intial);
                         intial=RQ[i];
                }

        }
        printf("Total HEad MOvement : %d\n",THM);
      return 0;
}

