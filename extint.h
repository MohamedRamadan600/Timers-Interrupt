#ifndef EXT_INT_H_
#define EXT_INT_H_


/**
 * Description: Enable the external2 interrupt by:
 *set bit of interrupt2 in GCR register _INT2
 * @param 
 */
void EINT2_Enable(void);

/**
 * Description: Disable the external2 interrupt by:
 *clear bit of interrupt2 in GCR register _INT2
 * @param 
 */
void EINT2_Disable(void);

/**
 * Description: Setting the bit of external2 interrupt 
 *in MCUCSR register to rising edge mode 
 * @param 
 */
void EINT2_R_s_Edge(void);

/**
 * Description: Setting the bit of external2 interrupt 
 *in MCUCSR register to rising edge mode 
 * @param 
 */
void EINT2_Falling_Edge(void);


#endif