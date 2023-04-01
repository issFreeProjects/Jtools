cmake_minimum_required(VERSION 3.0.0)
project(Jdate VERSION 1.0)


add_subdirectory(libjalali)


add_executable(jdate jdate_src/help.c jdate_src/main.c)
target_link_libraries(jdate jalali)

add_executable(jcal jcal_src/jcal.c)
target_link_libraries(jcal jalali)
