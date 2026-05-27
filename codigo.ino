// =====================================================
// BRAÇO ROBÓTICO ESPACIAL
// Docking & Retrieval
// VERSÃO FINAL - PINÇA REAL
// Compatível com Servo SG90
// =====================================================


// =====================================================
// PARÂMETROS
// =====================================================

garra_comprimento=70;
garra_largura=18;
garra_altura=8;

espaco_garra=30;

base_raio=28;
base_altura=8;

furo_parafuso=3;

quantidade_furos=5;


// =====================================================
// DIMENSÕES SG90
// =====================================================

servo_largura=23;
servo_profundidade=12;
servo_altura=24;

folga=1;


// =====================================================
// BASE
// =====================================================

module base_central(){

difference(){

cylinder(
h=base_altura,
r=base_raio,
$fn=80
);

translate([0,0,-1])

cylinder(
h=20,
r=3,
$fn=40
);

for(a=[0:90:270]){

rotate([0,0,a])

translate([18,0,-1])

cylinder(
h=20,
r=furo_parafuso/2,
$fn=30
);

}

}

}


// =====================================================
// ACOPLAMENTO SERVO
// =====================================================

module acoplamento_servo(){

difference(){

cylinder(
h=5,
r=8,
$fn=50
);

translate([0,0,-1])

cylinder(
h=10,
r=2.5,
$fn=30
);

}

}


// =====================================================
// PINÇA
// =====================================================

module garra_esquerda(){

difference(){

union(){

// Corpo principal

cube([
garra_comprimento-18,
garra_largura,
garra_altura
]);


// Parte afunilada

translate([
garra_comprimento-18,
garra_largura/2,
0
])

linear_extrude(height=garra_altura)

polygon([

[0,-7],
[6,-7],
[14,-5],
[20,-2],
[20,2],
[14,5],
[6,7],
[0,7]

]);


// Dedo superior

translate([
garra_comprimento-4,
11,
0
])

cube([
4,
3,
garra_altura
]);


// Dedo inferior

translate([
garra_comprimento-4,
4,
0
])

cube([
4,
3,
garra_altura
]);




// Eixo visual

translate([
5,
garra_largura/2,
garra_altura/2
])

rotate([90,0,0])

cylinder(
h=4,
r=2.5,
$fn=30
);

}



// Abertura central da pinça

translate([
garra_comprimento-3,
garra_largura/2,
-1
])

cube([
14,
5,
20
],center=true);


// Furos redução de massa

for(i=[1:quantidade_furos]){

translate([
10+(i*10),
garra_largura/2,
-1
])

cylinder(
h=20,
r=2,
$fn=20
);

}

}

}


// =====================================================
// GARRA DIREITA
// =====================================================

module garra_direita(){

mirror([0,1,0])

garra_esquerda();

}


// =====================================================
// SUPORTE SG90
// =====================================================

module suporte_servo(){

difference(){

cube([

servo_largura+6,
servo_profundidade+6,
servo_altura

]);

translate([

3,
3,
2

])

cube([

servo_largura+folga,
servo_profundidade+folga,
servo_altura

]);


// Furos

translate([4,4,-1])

cylinder(
h=10,
r=1.2,
$fn=20
);

translate([
servo_largura+2,
4,
-1
])

cylinder(
h=10,
r=1.2,
$fn=20
);

translate([
4,
servo_profundidade+2,
-1
])

cylinder(
h=10,
r=1.2,
$fn=20
);

translate([
servo_largura+2,
servo_profundidade+2,
-1
])

cylinder(
h=10,
r=1.2,
$fn=20
);

}

}


// =====================================================
// MONTAGEM
// =====================================================

module braco_robotico(){

base_central();

translate([
-15,
-10,
4
])

suporte_servo();

translate([
0,
0,
6
])

acoplamento_servo();

translate([
8,
espaco_garra/2,
10
])

garra_esquerda();

translate([
8,
-espaco_garra/2,
10
])

garra_direita();

}


// =====================================================
// EXECUTAR
// =====================================================

braco_robotico();