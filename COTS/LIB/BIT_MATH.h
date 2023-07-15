
/***************************************************/
/*          Authar : Ahmed Magdy                   */
/*          Version: 1.0						   */
/*          bit math                               */
/*          Date:28/2/2023						   */
/***************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define    set_bit(x , n)      x = x|(1<<n)

#define    clr_bit(x , n)      x = x&(~(1<<n))

#define    toggle_bit(x , n)   x = x^(1<<n )

#define    get_bit(x , n)        (1&(x>>n))
#define low_nibb(x , data)       (x & 0X0F) | (data << 4 ) 
#define upp_nibb(x , data )      (x & 0x0F) | (data & 0xF0)  

#define LOW_NN(x,data)           (x & 0x0f) | (data & 0x0f)
#define HIGH_NN(x,data)          (x & 0xf0) | (data>>4)
#endif /* BIT_MATH_H_ */
