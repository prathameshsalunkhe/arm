extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *p);
extern void uart0_binary(int num);
extern void uart0_integer(int num);
extern void uart0_rx_string(unsigned char *p,int len);
extern void uart0_float(float f);

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
