// NAME: Daniil
// Belousov
// ID 2491827
#include <stdio.h>
#include <math.h>

int main()
{
    int selection1, selection2, numinput, checkpoint1=0, checkpoint2=0, checkpoint3=0,checkpoint4=0, y0, y1, y2, numcount,n , k ;  // n-digitposition
    char d;
    printf("Welcome to Octal to Binary Encoder!\n\n");
    printf("   (1) Compute and Display the outputs\n");
    printf("   (2) Quit\n");
    printf("You choose: ");
    while(checkpoint1!=1){
        scanf("%d",&selection1);
        if(selection1<1 || selection1>2){
            printf("Incorrect value of the menu, please try again!\n");
            printf("You choose: ");
        }
        else
            checkpoint1=1;
    }

    // starting the loop for the program to run till the person chooses to stop
    while(selection1!=2){
        //creating a loop that will stop if we select 2 for the menu
        while(checkpoint1!=1){
            if(selection1<1 || selection1>2){
                printf("Incorrect value of the menu, please try again!\n");
                printf("You choose: ");
                scanf("%d",&selection1);
            }
            else
                checkpoint1=1;
        }
        printf("You have chosen option %d\n\n", selection1);
        y0=0, y1=0, y2=0;

        while (checkpoint4!=1){
            printf("Which base will you use to enter input (base 2 or base 10)? ");
            scanf("%d",&selection2);
            if ((selection2==2)||(selection2==10))
                checkpoint4=1;
            else
                printf("Invalid number in base 2/10\n");
        }

        //initializing a loop if the person wants to enter a binary number
        if (selection2==2){
            n=7;
            fflush(stdin);
            printf("Please enter your input: ");
            while(checkpoint2!=1){
                while((d!='\n')){
                    /* I ask the person to enter his value in line 32, after
                    i only take the value from the buffer till the character is a new line
                    */
                    scanf("%c",&d);
                    // all the if statements check for the value the person entered to be exactly 8 bits and are of 1 and 0 values
                    // changed the table to the equivalent one but in the reverse order
                    if ((d=='1')&&(n!=-1)){
                        if ((n==4) || (n==5) || (n==6) || (n==7)){
                            y2=1;
                        }
                        if ((n==2) || (n==3) || (n==6) || (n==7)){
                            y1=1;
                        }
                        if ((n==1)|| (n==3) || (n==5) || (n==7)){
                            y0=1;
                        }
                    }
                    else if ((n>=1) && (d=='\n')){
                        printf("You entered less than 8 bits! Please try again!\n");
                        printf("Please enter your input: ");
                        fflush(stdin);
                        n=7;
                        scanf("%c",&d);
                    }
                    else if ((n<-1) && (d=='\n')){
                        printf("You entered more than 8 bits! Please try again!:\n");
                        printf("Please enter your input: ");
                        fflush(stdin);
                        n=7;
                        scanf("%c",&d);
                        }
                    else if ((n==-1)&&(d=='\n'))
                        checkpoint2=1;
                    else if ((d!='0')&&(d!='1')){
                        printf("%c is not a valid number in base 2! Please try again!\n",d);
                        fflush(stdin);
                        n=7;
                        printf("Please enter your input: ");
                        scanf("%c",&d);
                    }
                    n--;
                }
                    }
            printf("Y2 is %d Y1 is %d Y0 is %d\n\n", y2, y1, y0);
            }

        //initializing a loop if the person wants to enter a decimal number
        else if (selection2==10){
                numcount=0;
                printf("Please enter your input: ");
                scanf("%d", &numinput);
                //the loop to check the correctness of the decimal value the person entered
                while(checkpoint3!=1){
                    if (numinput>255){
                    printf("Decimal %d cannot be represented with 8 bits. Please try again!\n", numinput);
                    printf("Please enter your input: ");
                    scanf("%d", &numinput);
                    }
                    else
                        checkpoint3=1;

                }
                while ((numcount!=8)){  // as we do not display the value the person entered in the end, i do not assign it value to another temporary memory space
                    numinput!=0;
                    k =(numinput%2);
                    numinput/=2;
                    if (k==1){    //checking if the remainder of the number is 1 and its position in 8 bit representation and setting the correct value for y0 or y1 or y2
                        if ((numcount==4) || (numcount==5) || (numcount==6) || (numcount==7)){
                            y2=1;
                        }
                        if ((numcount==2) || (numcount==3) || (numcount==6) || (numcount==7)){
                            y1=1;
                        }
                        if ((numcount==1)|| (numcount==3) || (numcount==5) || (numcount==7)){
                            y0=1;
                        }
                    }
                    numcount++;
                }
                printf("Y2 is %d Y1 is %d Y0 is %d\n\n", y2, y1, y0);
                    }



        printf("Welcome to Octal to Binary Encoder!\n\n");
        checkpoint1=0;
        checkpoint2=0;
        checkpoint3=0;
        checkpoint4=0;
        d='4';            //setting d to be equal any '4' so it will let enter the loop of binary again
        printf("   (1) Compute and Display the outputs\n");
        printf("   (2) Quit\n");
        printf("You choose: ");
        scanf("%d",&selection1);
    }
    printf("BYEE!");

    return 0;

}
