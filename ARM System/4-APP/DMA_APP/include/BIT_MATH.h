#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(x,y)    (x|=(1<<y))

#define CLR_BIT(x,y)    (x&=(~(1<<y)))

#define TOG_BIT(x,y)    (x^=(1<<y))

#define GET_BIT(x,y)    ((x>>y)&1)


#endif // BIT_MATH_H_

