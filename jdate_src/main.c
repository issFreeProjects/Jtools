#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "jalali.h"
#include "jtime.h"

#include "help.h"

#define isnumber(i) ((i)-'0'<=9 && (i)-'0'>=0)
#define isascii(c) ((c)>127 || (c)<0) // c is char
#define farsi_digit_option "-f"


static struct jtm j = {0};


static void jprintf_H(const char *format, const char flag, const bool farsi)
{
    char buf[MAX_BUF_SIZE];
    bool is_ascii = true;

    parse_jstr_flag(buf, MAX_BUF_SIZE, flag, &j, farsi);

    for(const char *p = buf; *p != '\0'; ++p)
        if(isascii(*p)){
            is_ascii = false;
            break;
        }

    if(is_ascii || !isnumber(format[1]))
        printf(format, buf);
    else{
        // handle non-ascii buf and %ns as format
        // suppose each non-ascii char is 2 bytes
        int padd, padd_end_idx;
        char new_format[MAX_BUF_SIZE];
        const char *p = format + 1;

        sscanf(p, "%d%n", &padd, &padd_end_idx);
        p += padd_end_idx;
        padd += strlen(buf)/2;

        if(format[1]=='0')
            sprintf(new_format, "%%0%d%s", padd, p);
        else sprintf(new_format, "%%%d%s", padd, p);

        printf(new_format, buf);
    }
}


void jprintf(const char *format, const char *flags, const bool farsi)
{
    int i=0, j=0, pi=0, valc=0;
    char tmp[64];

    while(format[i]!='\0' && format[i]!='%')
    {
        putchar(format[i]);
        i++;
    }

    while(format[i]!='\0')
    {
        pi =i;
        i++;
        while(format[i]!='\0' && format[i]!='%') i++;
        if(format[i+1]!='%' && format[i-1]=='%') i++;
        if(format[i]  =='%' && format[i+1]=='%' 
                            && format[i-1]=='%') i++;

        memcpy(tmp, format+pi, i-pi);
        tmp[i-pi]=0;

        jprintf_H(tmp, flags[valc], farsi);

        if(tmp[0]=='%' && tmp[1]!='%'){
            valc++;
        }
    }
    printf("\n");
}


void parse_jdate(const char *jdate_format, char *printf_format, char *flags)
{
    int i=0, pac=0;

    while(jdate_format[i]!='\0')
    {
        if(jdate_format[i]!='%'){
            printf_format[i] = jdate_format[i];
            i++;
        }
        else
        {
            printf_format[i] = jdate_format[i];

            if(jdate_format[i+1]=='%')
            {
                printf_format[i+1]='%';
                i+=2;
            }else
            {
                i++;
                if(jdate_format[i]=='\0')
                    break;
                printf_format[i] = jdate_format[i];

                while(isnumber(jdate_format[i]))
                {
                    printf_format[i] = jdate_format[i];
                    i++;
                }

                flags[pac] = jdate_format[i]; 
                printf_format[i] = 's';

                pac++;
                i++;
            }
        }
    }
    printf_format[i] = 0;
}


void farsi_printf_jdate(const char *jdate_format)
{
    char output[MAX_BUF_SIZE];
    char printf_format[MAX_BUF_SIZE];
    char flags[32];

    time_t t;
    time(&t);

    jlocaltime_r(&t, &j);
    jalali_update(&j);

    parse_jdate(jdate_format, printf_format, flags);

    jprintf(printf_format, flags, 1);
}


void printf_jdate(const char *jdate_format)
{
    char output[MAX_BUF_SIZE];
    char printf_format[MAX_BUF_SIZE];
    char flags[32];

    time_t t;
    time(&t);

    jlocaltime_r(&t, &j);
    jalali_update(&j);

    parse_jdate(jdate_format, printf_format, flags);

    jprintf(printf_format, flags, 0);
}


void default_print()
{
    printf_jdate("%E");
}


int main(int argc, char **argv)
{
    if(argc<2)
        default_print();
    else if(argc==2)
    {
        if( argv[1][0] == '+' )
            printf_jdate(argv[1]+1);
        else if(strcmp(argv[1], farsi_digit_option)==0)
            default_print();
        else print_help();
    }
    else if(argc==3)
    {
        if(     argv[1][0] == '+' &&
                strcmp(argv[2], farsi_digit_option)==0 )
            farsi_printf_jdate(argv[1]+1);
        else if(argv[2][0] == '+' &&
                strcmp(argv[1], farsi_digit_option)==0 )
            farsi_printf_jdate(argv[2]+1);
        else print_help();
    }

    return 0;
}
