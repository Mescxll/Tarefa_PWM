# Tarefa U4C7 - Controle de servomotor por PWM
Nesse projeto utilizamos o módulo PWM (Pulse Width Modulation), presente no RP2040, para simular o controle do ângulo de um servomotor. Tarefa desenvolvida para a Capacitação EmbarcaTech por Maria Eduarda Campos.

### Video de demonstração
//link

### Funcionalidades

1. Define a sua frequência de PWM para 50Hz – período de 20ms
   
2. Define o ciclo ativo do módulo PWM para:
  - 2.400µs (microssegundos) – Duty Cycle de 0,12% - 180° do braço do Servomotor e mantém por 5 segundos.
  - 1.470µs (microssegundos) – Duty Cycle de 0,0735% - 90° do braço do Servomotor e mantém por 5 segundos.
  - 500µs (microssegundos) – Duty Cycle de 0,025% - 0° do braço do Servomotor e mantém por 5 segundos.
    
3. Cria uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus(movimentação suave) - ciclo ativo de ±5µs com um atraso de ajuste de 10ms.
   
4. Cria testes com o emprego da Ferramenta Educacional BitDogLab substituindo o Servomotor simulado por um LED vermelho (GPIO 13), criando uma transição entre os níveis de iluminação congruentes com os intervalos da movimentação do servomotor.

### Instruções
1. Clone este repositório:
   ```sh
   git clone https://github.com/Mescxll/Tarefa_PWM.git
   ```
2. Compile e carregue o código no Raspberry Pi Pico W utilizando o VS Code e o Pico SDK.
3. Utilize a placa BitDogLab e o Simulador para testar o funcionamento do servomotor e do led.

