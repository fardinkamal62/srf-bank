cmake_minimum_required(VERSION 3.25)
project(srf_bank C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(srf_bank
        account.h
        db_operation.c
        db_operation.h
        main.c
        transaction.c
        transaction.h)
