#ifndef EXCEPTION_H
#define EXCEPTION_H
typedef enum {
    TESTING,//0
    OK,//1
    INVALID_RANGE,//2
    NULL_POINTER,//3
    DIVISION_BY_ZERO,//4
    INDEX_OUT_OF_BOUNDS,//5
    CANNOT_OPEN_FILE //6
} ERROR_INFO;

/**
 * A variable for storing the error information. If a function succeeds, errorInfo should be set to OK.
 */
extern ERROR_INFO errorInfo;

#endif //EXCEPTION_H

