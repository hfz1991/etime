#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    /*declare*/
    char buffer[100],buffer2[100];
    int digitCounter=0,digitCounter2=0;
    int isInvalidFlag=0,isInvalidFlag2=0;
    long value,value2;
    char *check,*check2;
    int i,digit,i2,digit2;
    int hour=0,minute=0,hour2=0,minute2=0;

    /*Welcome message*/
    printf("\nThis is an small e-time program");
    
    /*Ask input for valid time of day*/
    do
    {
        /*if error prompt error message and initialise value*/
        if(isInvalidFlag==1){
            printf("\nPlease check the input\n");
            hour=0;
            minute=0;
            digitCounter=0;
            isInvalidFlag=0;
        }

        printf("\nPlease enter integer value represents a time of day on 24-hour clock.eg:1345:\n");
        fflush(stdout);
        if(fgets(buffer,sizeof buffer, stdin)){
            value=strtol(buffer,&check,0);
            /*Check numerical*/ 
            if(!isspace(*check) && *check !=0 )
            {
                printf("%s is not a valid integer\n",buffer);
                isInvalidFlag=1;
            }
            else
            {
                /*count digit*/
                for(i=0;value!=0;i++){
                    digit = value % 10;
                    switch(i){
                        case 0:minute+=digit;
                               break;
                        case 1:minute+=10*digit;
                               break;
                        case 2:hour+=digit;
                               break;
                        case 3:hour+=10*digit;
                               break;
                    }
                    value/=10;
                    ++digitCounter;
                    /*printf("\nCurrent digit:%d",digit);*/
                }
                /*fail when digit is not 3 or 4*/
                if(digitCounter!=4 && digitCounter!=3) {
                    printf("\nError: Digit of number %d is wrong.\n",digit);
                    isInvalidFlag=1;
                }
                else if(hour>23 || hour <0) {
                    printf("\nError: hour must between 0 to 23.\n");
                    isInvalidFlag=1;
                }
                else if(minute>59 || minute < 0) {
                    printf("\nError: minute must between 0 to 59.\n");
                    isInvalidFlag=1;
                }
                /*All condition satisfied*/
                else{
                    printf("The time of day you entered is %d:%d",hour,minute);
                }
            }
        }
    }while(isInvalidFlag==1);

    /*Ask input for valid time duration*/
    do
    {
        /*if error prompt error message and initialise value*/
        if(isInvalidFlag2==1){
            printf("\nPlease check the input\n");
            hour2=0;
            minute2=0;
            digitCounter2=0;
            isInvalidFlag2=0;
        }

        printf("\nPlease enter integer value represents a time duration on 24-hour clock.eg:1345:\n");
        fflush(stdout);
        if(fgets(buffer2,sizeof buffer2, stdin)){
            value2=strtol(buffer2,&check2,0);
            /*Check numerical */
            if(!isspace(*check2) && *check2 !=0 )
            {
                printf("%s is not a valid integer\n",buffer2);
                isInvalidFlag2=1;
            }
            else
            {
                /*count digit*/
                for(i2=0;value2!=0;i2++){
                    digit2 = value2 % 10;
                    switch(i2){
                        case 0:minute2+=digit2;
                               break;
                        case 1:minute2+=10*digit2;
                               break;
                        case 2:hour2+=digit2;
                               break;
                        case 3:hour2+=10*digit2;
                               break;
                    }
                    value2/=10;
                    ++digitCounter2;
                    /*printf("\nCurrent digit:%d",digit2);*/
                }
                /*fail when digit is not 3 or 4*/
                if(digitCounter2!=4 && digitCounter2!=3) {
                    printf("\nError: Digit of number %d is wrong.\n",digit2);
                    isInvalidFlag2=1;
                }
                else if(minute2>59 || minute2 < -59) {
                    printf("\nError: \"%d\" minute must between 0 to 59. %d \n",minute2,hour2);
                    isInvalidFlag2=1;
                }
                /*All condition satisfied*/
                else{
                    printf("The time duration you entered is %d hours, %d minutes",hour2,minute2);
                }
            }
        }
    }while(isInvalidFlag2==1);
    /*Load data finish*/

    /*Start time logic*/
    /*Check positive or negative for the time duration*/ 
    if(hour2>0)
    {
        minute+=minute2;
        hour+=hour2;
        while(minute>59)
        {
            minute-=60;
            hour++;
        }
        while(hour>23)
        {
            hour-=24;
        }
    }
    else
    {

    }

    printf("\nResult time is ");
    if(hour==0) printf("00");
    else printf("%d",hour);
    if(minute==0) printf("00");
    else printf("%d",minute);
    printf("\n");
    return 0;

}
