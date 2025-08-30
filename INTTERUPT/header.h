extern void eint0_handler(void)__irq;
extern void config_vic_for_eint0(void);
extern void config_eint0(void);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *p);
extern void uart0_binary(int num);
extern void uart0_integer(int num);
extern void uart0_rx_string(unsigned char *p,int len);
extern void uart0_float(float f);
