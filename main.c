#include <stdio.h>
int main(){
    //declare
    char buffer[100];
    int digitCounter=0;
    int timeOfDay;
    int timeDuration;
    int isInvalidFlag=0;
    long value;
    char *check;
    int i,digit;
    int hour=0,minute=0;

    //Welcome message
    printf("\nThis is an small e-time program");
    do
    {
        //if error prompt error message and initialise value
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
            //Check numerical 
            if(!isspace(*check) && *check !=0 )
            {
                printf("%s is not a valid integer\n",buffer);
                isInvalidFlag=1;
            }
            else
            {
                //count digit
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
                    //printf("\nCurrent digit:%d",digit);
                }
                //fail when digit is not 3 or 4
                if(digitCounter!=4 && digitCounter!=3) {
                    printf("\nError: Digit of number %d is wrong.\n",digit);
                    isInvalidFlag=1;
                }
                else if(hour>23 || hour <0) {
                    printf("\nError: hour must between 0 to 23.\n");
                    isInvalidFlag=1;
                }
                else if(minute>59 || minute < 0) {
                    printf("\nError: minute must between 0 to 23.\n");
                    isInvalidFlag=1;
                }
                //All condition satisfied
                else{
                    printf("All good!");
                }
                printf("hour:%d , minute: %d",hour,minute);
            }
        }
    }while(isInvalidFlag==1);

    return 0;

}
