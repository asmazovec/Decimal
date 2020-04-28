#ifndef DECIMAL_2_H_
#define DECIMAL_2_H_


typedef struct {
    signed long long integ;  // integer - целая часть
    signed long long fract;  // fractional - дробная часть
    signed char;
} decimal_2;


decimal_2 summarize (decimal_2, decimal_2); // сумма
decimal_2 subtract (decimal_2, decimal_2);  // разность
decimal_2 multiply (decimal_2, decimal_2);  // произведение

#endif /*DECIMAL_2_H_*/
