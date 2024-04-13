#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG,N)  (REG|=1<<N);
#define RESET_BIT(REG,N)    (REG&=~(1<<N))
#define TOGGLE_BIT(REG, N) (REG^=1<<N)
#define GET_BIT(REG,N)     ((REG>>N)&(0x01U))

#endif
