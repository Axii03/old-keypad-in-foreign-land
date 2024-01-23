#include <stdio.h>
int main()
{
    int fSize,i,keySize,totalKeys=0;
    printf("Input size of frequencies Array: ");
    scanf("%d",&fSize);
    int frequencyArr[fSize];
    printf("Input the values: ");
    for(i=0;i<fSize;i++)
    {
        scanf("%d",&frequencyArr[i]);
    }
    printf("Input size of Keysize Array: ");
    scanf("%d",&keySize);
    int maxKeys[keySize];
    printf("Maximum number of letters that maybe put on the keys respectively: ");
    for(i=0;i<keySize;i++)
    {
         scanf("%d",&maxKeys[i]);
    }
    //check if total keys size is enough to fit entire frequency array
    for(i=0;i<keySize;i++)
    {
        totalKeys=totalKeys+maxKeys[i];
    }
    if(totalKeys<fSize) //total keysize is not enough to handle the frequncy array so exit.
    {
        printf("Not enough space to handle frequency array.Exiting.");
        return -1;
    }
    for (int i = 1; i <fSize; i++) //insertion sort to order the frequencyArr
    {
        int key = frequencyArr[i];
        int j = i - 1;
        while (j >= 0 && frequencyArr[j] <key)
        {
            frequencyArr[j + 1] = frequencyArr[j];
            j--;
        }

        frequencyArr[j + 1] = key;
    }
    printf("Sorted array: ");
    for(i=0;i<fSize;i++) //print frequency array sorted one.
    {
        printf("%d",frequencyArr[i]);
    }

    int assigned[keySize]; //an array to keep track of how many characters has been assigned to a key
    for (int i = 0; i < keySize; i++)//initialize assigned array to all 0.
    {
        assigned[i] = 0;
    }
    int totalKeystrokes = 0; //variable to count the total number of minimum keystrokes
    for (int i = 0; i < fSize; i++) 
    {
        int minKey = 0;
        for (int j = 1; j < keySize; j++) 
        {
            if (assigned[j]<assigned[minKey] && assigned[j]<maxKeys[j]) 
            {
                minKey = j;
            }
        }
        assigned[minKey]=assigned[minKey]+1;
        totalKeystrokes =totalKeystrokes+(frequencyArr[i] * assigned[minKey]);
    }

    printf("\nTotal number of keystrokes : %d\n", totalKeystrokes);// Print the total number of keystrokes

    return 0;


}
