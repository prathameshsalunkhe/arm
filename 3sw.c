#include <lpc21xx.h>
#include "header.h"

#define sw1 ((IOPIN0 >> 14) & 1)
#define sw2 ((IOPIN0 >> 15) & 1)
#define sw3 ((IOPIN0 >> 16) & 1)

main() {
    int c = 0;
    lcd_init();
    lcd_cmd(0x0C);

    while (1) {
        if (sw1 == 0) {
            while (sw1 == 0);
            if (c < 59) {
                c++;
                lcd_cmd(0x01);
                lcd_data((c / 10) + 48);
                lcd_data((c % 10) + 48);
            }
        }

        if (sw2 == 0) {
            while (sw2 == 0);
            if (c > 0) {
                c--;
                lcd_cmd(0x01);
                lcd_data((c / 10) + 48);
                lcd_data((c % 10) + 48);
            }
        }

        if (sw3 == 0) {
            while (sw3 == 0);
            for (c = 49; c >= 0; c--) {
                lcd_cmd(0x01);
                lcd_data((c / 10) + 48);
                lcd_data((c % 10) + 48);
                delay_ms(200);
            }
        }
    }
}
