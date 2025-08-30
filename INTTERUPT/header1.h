//extern void eint0_handler(void)__irq;
extern void config_vic_for_eint0(void);
extern void config_eint0(void);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *p);
extern void uart0_binary(int num);

extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_string(char *p);
extern void lcd_integer(int num);

