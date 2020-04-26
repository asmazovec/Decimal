#ifndef DECIMAL_H_
#define DECIMAL_H_


typedef signed long long int sll_int;
typedef signed char sss_int;

typedef struct {
    sll_int num;  // Мантисса 
    sss_int n;    // Порядок 
} decimal;

sll_int power10 (int);


decimal normalize (decimal);

decimal summarize (decimal, decimal);
decimal subtract (decimal, decimal);
decimal multiply (decimal, decimal);

#endif /*DECIMAL_H_*/
