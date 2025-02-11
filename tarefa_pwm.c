// Tarefa U4C7 por Maria Eduarda Campos - PWM e servomotores

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERV_MOTOR 22 // Pino do servomotor 
#define LED 13 //Pino do LED vermelho

//Cálculo de frequência 
//f => 125M / (100*25001) =~ 0,005Khz 

const uint16_t WRAP = 25000;
const float DIVISER = 100;

// Variáveis para controle da angulação do braço do servomotor
uint16_t angulos[3];

//Porcetagens dadas pela atividade
float porcetagens[3] = {12, 7.35, 2.5}; 
//Duty Cycles (%) :
                                    //180º - 2.400µs 
                                    // 90º - 1.470µs 
                                    //0º - 500µs 

float INCREM_CICLO_ATIVO = 0.025; //Valor do incremento de ciclo ativo (%)

//Função para configurar o módulo PWM
void pwm_setup(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM); //Habilitar o pino como PWM
    uint slice = pwm_gpio_to_slice_num(pino); //Obtém um canal PWM 
    pwm_set_clkdiv(slice, DIVISER); //Define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP); // Define o valor de wrap
    pwm_set_enabled(slice, true); //Habilita o PWM no slice 
}

//Função principal
int main() {
    stdio_init_all();

    pwm_setup(SERV_MOTOR); //Configura o módulo PWM para o servomotor
    pwm_setup(LED); //Configura o módulo PWM para o led

    //Estruturas de repetição com o controle de angulação
    //Cálculo de nível Duty Circle 
    //WRAP * ângulo /100

    //Servemotor
    for(int i = 0; i < 3; i++) {
        angulos[i] = (uint16_t)(WRAP * porcetagens[i] / 100.0);       
        pwm_set_gpio_level(SERV_MOTOR, angulos[i]); 
        sleep_ms(5000); //Atrasa 5 segundos na posição
    }

    //LED vermelha
    for(int i = 0; i < 3; i++) {
        angulos[i] = (uint16_t)(WRAP * porcetagens[i] / 100.0); 
        pwm_set_gpio_level(LED, angulos[i]); 
        sleep_ms(5000); //Atrasa 5 segundos na posição
    }

    uint16_t nivel = angulos[2]; //Inicia o braço em 0°
    int controle = (WRAP * INCREM_CICLO_ATIVO / 100.0); //Declara e inicializa a variável de controle 
    pwm_set_gpio_level(SERV_MOTOR, nivel); //Define o ângulo
    pwm_set_gpio_level(LED, nivel); // Define o nível de luz
    nivel += controle; 
    if (nivel <= angulos[2] || nivel >= angulos[0]) { //Altera o controle
        controle = controle * -1;
    } 
    sleep_ms(10); //Atraso estratégico
}