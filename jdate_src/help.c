#include <stdio.h>
#include "help.h"


void print_help()
{
    printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
        "Using: jdate +FORMAT [-f option]\n",
        "Jdate - print the system date and time (in Jalali calendar)\n",
        "Display  the current time/jalali date in the given FORMAT\n",
        "use -f option to print digits using farsi characters.\n\n"
        "FORMAT controls the output.  Interpreted sequences are:\n",
        // special characters
        "%%     a literal %\n",
        "%t     A tab character.\n",
        "%n     A newline character.\n\n",

        // preferred
        "%E     The preferred date and time representation in Farsi.\n",
        "%W     The preferred date representation without the time in Farsi.\n",
        "%X     The preferred time representation in Farsi.\n"
        "%c     The preferred date and time representation (Finglish).\n",
        "%x     The preferred date representation without the time (English).\n\n",

        // day of month/week/year 
        "%d     The day of the month as a decimal number.\n",
        "%e     Like %d, but zero is replaced by a space.\n",
        "%w     The day of the week as a decimal, range 0 to 6.\n",
        "%u     The day of the week as a decimal, range 1 to 7.\n",
        "%j     The day of the year as a decimal number.\n\n",

        // weekday week number
        "%a     The abbreviated weekday name. (English)\n",
        "%h     The abbreviated weekday name. (Finglish)\n",
        "%g     The abbreviated weekday name. (Farsi)\n",
        "%A     The full weekday name. (English)\n",
        "%q     The full weekday name. (Finglish)\n",
        "%G     The full weekday name. (Farsi)\n",
        "%U     The week number of the current year as a number.\n\n",
        
        // month
        "%b     The abbreviated month name. (Finglish)\n",
        "%v     The abbreviated month name. (Farsi)\n",
        "%B     The full month name. (Finglish)\n",
        "%V     The full month name. (Farsi)\n",
        "%m     The month as a decimal number.\n\n",
        
        // year
        "%y     The year as a decimal number without a century.\n",
        "%Y     The year as a decimal number including the century.\n",
        "%C     The century number (year/100) as a 2-digit integer.\n",

        // Hour
        "%H     The hour as a decimal number using a 24-hour clock.\n",
        "%I     The hour as a decimal number using a 12-hour clock\n",
        "%k     24-hour clock, single digits are preceded by a blank.\n",
        "%l     12-hour clock, single digits are preceded by a blank.\n",
        // Minute
        "%M     The minute as a decimal number.\n",
        // Second
        "%S     The second as a decimal number.\n",
        "%s     The number of seconds since 1970-01-01 00:00:00 UTC.\n\n",
        // Others time patterns
        "%R     The time in 24-hour notation (%H:%M).\n",
        "%T     The time in 24-hour notation (%H:%M:%S).\n",
        "%z     The +hhmm or -hhmm numeric timezone (offset from UTC).\n",
        "%Z     The timezone or name or abbreviation.\n",
        "%0     Either ﻕ.ﻅ or ﺏ.ﻅ according to the given time value.\n",
        "%p     Either AM or PM according to the given time value.\n",
        "%P     Like %p but in lowercase: am or pm.\n\n",

        // Equivalents
        "%D     Equivalent to %Y/%m/%d.\n",
        "%F     Equivalent to %Y-%m-%d.\n",
        "%r     equivalent to %I:%M:%S %p (time in am or pm notation).\n\n",

        "%10x    prints at least 10 characters including the value of %x\n",
        "%010x   like %10x but space is replaced by a zero character.\n\n",

        "Note that each farsi character is equal to 2 ascii characters,\n"
        "for more information, see the UTF-8 standard.\n");
}
