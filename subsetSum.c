#include<stdlib.h>
#include<stdio.h>

int subSetSum(int set[], int length, int sum)
{
    int positiveSum = 0;
    int negativeSum = 0;
    int i,j;
    for(i=0;i<length;i++)
    {
        if(set[i]>0)
        {
            positiveSum += set[i];
        }
        else
        {
            negativeSum += set[i];
        }
    }
    if(sum > positiveSum || sum < negativeSum) return 0;

    int tempLength = positiveSum + (negativeSum*-1) +1;
    int setTable[length][tempLength];
    int posY = 0;
	
	int kiek = 0;
    for(j=0; j<length; j++)
    {
        int posX = 0;
        for(i=negativeSum; i <= positiveSum; i++)
        {
            if(set[j] == i)
            {
                setTable[posY][posX] = 1;
            }
            else if (posY - 1 >= 0)
            {
                int tempIndex =(negativeSum*-1) + (i - set[j]);
                if(setTable[posY-1][posX])
                {
                    setTable[posY][posX] = 1;
                }
                else if(tempIndex >= 0 && tempIndex < tempLength && setTable[posY-1][tempIndex] == 1)
                {
                    setTable[posY][posX] = 1;
                }
                else setTable[posY][posX] = 0;
            }
            else setTable[posY][posX] = 0;
			if(posX == (negativeSum*-1) + sum && setTable[posY][posX] == 1)
			{
				j=length;
			}
            posX += 1;
			kiek++;
        }
        posY += 1;
    }
	printf("prasisuko: %d \n",kiek);
    //print
    if(setTable[posY][(negativeSum*-1) + sum])
    {
        printf("[");
        for(j = 0; j<length; j++)
        {
            printf("%d, ",set[j]);
        }
        printf("] => example subset ");
        //posY = length -1;
        int posX = (negativeSum*-1) + sum;
        printf("[");
        while(setTable[posY][posX]!=0 && posY >= 0)
        {
            while(setTable[posY-1][posX]!=0 && posY != 0)
            {
                posY--;
            }
            int tempSum = posX - (negativeSum*-1);
            printf("%d, ", set[posY]);
            posX=(negativeSum*-1) + (tempSum - set[posY]);
            posY--;
        }
        printf("] \n");
		return 1;
    }
	else return 0;
    /*
    for(j = 0; j<length; j++)
    {
        for(i = 0; i<tempLength; i++)
        {
            printf("| %d | ",setTable[j][i]);  //setTable values list
        }
        printf("\n");
    }
    */
}

int main()
{

    int set[] = {-7,-3,-2,5,8,9};
    int length = sizeof(set)/sizeof(set[0]);

    int sum;
    printf("Enter the subset sum: ");
    scanf("%d", &sum);

    if(subSetSum(set, length, sum)) printf("Subset with sum = %d exists\n", sum);
    else printf("Subset with sum = %d doesn't exist\n", sum);

    return 0;
}

