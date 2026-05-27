# Projeto_Braco_Robotico_Espacial
Projeto Docking &amp; Retrieval utilizando Arduino, servos e OpenSCAD

# Braço Robótico Espacial – Docking & Retrieval

## Integrantes
Rm-99092 João Gabriel Dias

RM-98772 Julio César Zampieri

RM-95906 Ricardo Matos

---

# Descrição do Projeto

Este projeto consiste no desenvolvimento de um **Braço Robótico Espacial para coleta de amostras (Docking & Retrieval)**, projetado para simular operações de captura e manipulação de objetos em ambientes de **microgravidade**, como estações espaciais, satélites e missões de exploração espacial.

O sistema utiliza um **Arduino Uno**, dois **servomotores SG90**, um **LED indicador de status**, comandos enviados pelo **Monitor Serial** e um modelo mecânico desenvolvido em **OpenSCAD**.

O projeto foi desenvolvido considerando integração entre:

* Sistema eletrônico
* Controle por software
* Estrutura mecânica 3D

---

# Objetivo do Projeto

O objetivo é simular um sistema de coleta automatizada de amostras espaciais, permitindo:

* Movimentação do braço robótico;
* Abertura e fechamento da garra;
* Controle através de comandos seriais;
* Indicação visual do estado de captura da amostra;
* Integração entre o circuito eletrônico e o modelo mecânico.

---

# Simulador Utilizado

Projeto desenvolvido utilizando o simulador Tinkercad:

https://www.tinkercad.com/things/dItMZRTd1fm-gs

---

# Tecnologias Utilizadas

## Hardware

* Arduino Uno
* 2 Servomotores SG90 (9g)
* LED verde indicador
* Resistor 220 Ω
* Protoboard
* Fonte externa 5V
* Jumpers

## Software

* Arduino IDE
* OpenSCAD
* Tinkercad

---

# Funcionamento do Sistema

O sistema é controlado através do **Monitor Serial do Arduino**.

Ao iniciar a simulação, o programa apresenta os comandos disponíveis:

U = Up
D = Down
O = Open
C = Close

Os servomotores executam movimentos específicos para simular o funcionamento de um braço robótico de coleta espacial.

---

# Guia de Operação

## Passo 1

Abrir o projeto no Tinkercad.

## Passo 2

Iniciar a simulação.

## Passo 3

Abrir:

Código → Monitor Serial

Configurar:

Velocidade: 9600 baud

## Passo 4

Enviar comandos:

| Comando | Função                  |
| ------- | ----------------------- |
| U       | Move o braço para cima  |
| D       | Move o braço para baixo |
| O       | Abre a garra            |
| C       | Fecha a garra           |

---

# Resposta do Sistema

Ao receber um comando, o Monitor Serial informa a ação executada:

Exemplos:

Braco subindo

Braco descendo

Garra aberta

Amostra capturada

---

# Funcionamento dos Servos

## Servo Base

Responsável pela movimentação principal do braço.

Funções:

* Elevar o braço
* Diminuir o ângulo do braço
* Simular aproximação da amostra

Pino utilizado:

D9

---

## Servo Garra

Responsável pela captura do objeto.

Funções:

* Abrir a garra
* Fechar a garra
* Simular captura da amostra

Pino utilizado:

D10

---

# LED Indicador de Status

O LED foi implementado para indicar o estado da captura.

Funcionamento:

LED desligado:

* Garra aberta

LED ligado:

* Amostra capturada

Pino utilizado:

D3

---

# Especificações Técnicas

## Arduino

Modelo:

Arduino Uno

## Alimentação

Fonte utilizada:

5V

## Comunicação

Monitor Serial:

9600 baud

## Pinagem

| Componente  | Pino |
| ----------- | ---- |
| Servo Base  | D9   |
| Servo Garra | D10  |
| LED         | D3   |

---

# Modelagem 3D

A estrutura mecânica foi desenvolvida utilizando **OpenSCAD**.

O modelo foi criado de forma **paramétrica**, permitindo modificar facilmente dimensões através de variáveis.

Exemplo:

garra_comprimento

garra_largura

garra_altura

espaco_garra

base_raio

---

# Integração entre OpenSCAD e Tinkercad

O projeto mecânico foi desenvolvido para representar fisicamente os componentes utilizados no circuito eletrônico.

A integração ocorre da seguinte forma:

Circuito eletrônico:

Servo Base → controla movimentação do braço

Servo Garra → controla abertura e fechamento

Modelo 3D:

Base central → estrutura principal

Suporte do servo → encaixe do SG90

Acoplamento → transmissão de movimento

Garra → mecanismo de captura

Fluxo de funcionamento:

Arduino → Servo → Acoplamento → Garra → Captura da amostra

Dessa forma, o circuito desenvolvido no Tinkercad e a estrutura criada no OpenSCAD trabalham em conjunto como um único sistema robótico.

---

# Aplicação Espacial

O projeto foi inspirado em sistemas robóticos utilizados em missões espaciais para:

* Captura de satélites
* Coleta de amostras
* Operações de docking
* Manipulação remota em microgravidade

Para reduzir massa estrutural, foram adicionados furos ao modelo da garra, reduzindo peso sem comprometer significativamente a resistência da peça.

---

# Estrutura do Repositório

Projeto/

src/

braco_robotico.ino

model/

GS_V2.scad

GS_V2.stl

images/

circuito.png

modelo3D.png

README.md

---

# Conclusão

O projeto integra eletrônica, programação e modelagem tridimensional em uma única solução funcional de braço robótico espacial.

O sistema permite simular operações de captura e manipulação de amostras em ambiente de microgravidade, demonstrando a aplicação conjunta de automação, controle embarcado e modelagem mecânica.
