extern void adc_init(void);
extern unsigned int adc_read(unsigned char ch_num);

extern void uart1_init(unsigned int baud);
extern void uart1_tx(unsigned char data);
extern unsigned char uart1_rx(void);
extern void uart1_tx_string(char *p);
extern void uart1_integer(int num);
extern void uart1_float(float f);

extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
