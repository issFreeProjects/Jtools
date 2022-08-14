add_library(libjalali SHARED
    src/jalali.c
    src/jtime.c)

set_target_properties(libjalali PROPERTIES VERSION 1.1)

target_include_directories(libjalali PUBLIC include)
