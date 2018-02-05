/***********************************
本程序用于树莓派通过GPIO连接1602的效
果演示，使用wiringPi库和其附带的LCD
库进行GPIO和1602的操作。

                 created by @qtsharp
************************************
示例1：
    $sudo ./l602
    屏幕显示：
        ------------------
        |  Raspberry Pi! |
        |51.9C 215/477MB |
        ------------------
        
示例2：
    $sudo ./1602 QtSharp
    屏幕显示：
        ------------------
        |QtSharp         |
        |51.9C 215/477MB |
        ------------------

示例3：
    $sudo ./1602 \ \ Hello\ World
    屏幕显示：
        ------------------
        |  hello world   |
        |51.9C 215/477MB |
        ------------------

************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <wiringPi.h>
#include <lcd.h>

int main (int args, char *argv[])
{
    if (wiringPiSetup () == -1)
        exit (1) ;
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
        fgets(Body,33,fp);
        fclose(fp);

        lcdClear (fd);
        lcdPosition (fd, 0, 0) ;
        lcdPuts(fd , Body);
        
        sleep(2);
    }

    return 0;
    
}

