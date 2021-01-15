#include "log.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void SYS_log(char* message,...){
    va_list args;
    va_start(args, message);
    
    vprintf(message, args);

    va_end(args);
}

void SYS_warn(char* message,...){
    va_list args;
    va_start(args,message);
    if(strlen(message) > 400){
        SYS_err("Cannot warn 400 characters long messages\n");
    }
    else{
        char buffer[512];
        char buf[512];
        vsprintf(buffer,message,args);
        snprintf(buf,512,"\033[33mWarning: \033[0m%s",buffer); 
        printf(buf);
    }
}

void SYS_err(char* message,...){
    va_list args;
    va_start(args,message);
    if(strlen(message) > 400){
        SYS_err("Cannot warn 400 characters long messages\n");
    }
    else{
        char buffer[512];
        char buf[512];
        vsprintf(buffer,message,args);
        snprintf(buf,512,"\033[31mERROR: \033[0m%s",buffer); 
        printf(buf);
    }

}
