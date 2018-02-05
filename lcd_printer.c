#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <wiringPi.h>
#include <lcd.h>

int main (int args, char *argv[])
{
    if (wiringPiSetup () == -1)
    {
       printf("some thing wrong!");
       exit (1) ;
    }
    int fd = lcdInit (2, 16, 4,  11,10 , 0,1,2,3,0,0,0,0) ;
    if (fd == -1)
    {
        printf ("lcdInit 1 failed\n") ;
        return 1 ;
    }
    sleep (1) ; //显示屏初始化

    FILE *fp;
    char Body[32]; 
    
    while(1)
    {
        fp=fopen("./bid.txt","r");
        fgets(Body,32,fp);
        fclose(fp);

        lcdClear (fd);
        lcdPosition (fd, 0, 0) ;
        lcdPuts(fd , Body);
        
        sleep(1);
    }

    return 0;
    
}

