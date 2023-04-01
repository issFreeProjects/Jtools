add_library(jalali SHARED
    src/jalali.c
    src/jtime.c)

set_target_properties(jalali PROPERTIES VERSION 1.1)

target_include_directories(jalali PUBLIC include)
