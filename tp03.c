#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <math.h>

int main () {

    adc_init();
    adc_gpio_init(27);
    adc_select_input(1);

    while (1){
        float Vntc = 0;
        float result = adc_read();
        float t = result * (3.3 / 4095);
        float r2 = 10000/((3.3/t)-1);
        float aaa = (3950*298)/(298 * log(r2/10000)+3950);
        printf("La resistencia es %.2f\n", r2);
        printf("La tensión es %.2f\n", t);
        sleep_ms(1000);
    }
}
