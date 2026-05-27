// =====================================================
// BRAÇO ROBÓTICO ESPACIAL
// Docking & Retrieval
// Versão FINAL AJUSTADA
// Compatível com Servo SG90 9g
// =====================================================


// =====================================================
// PARÂMETROS
// =====================================================

garra_comprimento = 70;
garra_largura = 18;
garra_altura = 8;

espaco_garra = 28;

base_raio = 28;
base_altura = 8;

furo_parafuso = 3;

quantidade_furos = 5;

dente_largura = 3;
dente_altura = 4;


// =====================================================
// DIMENSÕES DO SERVO SG90
// =====================================================

servo_largura = 23;
servo_profundidade = 12;
servo_altura = 24;

folga = 1;


// =====================================================
// BASE CENTRAL
// =====================================================

module base_central(){

    difference(){

        cylinder(
            h = base_altura,
            r = base_raio,
            $fn = 80
        );

        // Furo central do eixo
        translate([0,0,-1])

        cylinder(
            h = 20,
            r = 3,
            $fn = 40
        );

        // Furos de fixação
        for(a = [0:90:270]){

            rotate([0,0,a])

            translate([18,0,-1])

            cylinder(
                h = 20,
                r = furo_parafuso/2,
                $fn = 30
            );
        }
    }
}


// =====================================================
// ACOPLAMENTO DO SERVO (HORN)
// =====================================================

module acoplamento_servo(){

    difference(){

        cylinder(
            h = 5,
            r = 8,
            $fn = 40
        );

        // Furo do eixo
        translate([0,0,-1])

        cylinder(
            h = 7,
            r = 2.5,
            $fn = 30
        );
    }
}


// =====================================================
// GARRA ESQUERDA
// =====================================================

module garra_esquerda(){

    difference(){

        union(){

            // Corpo principal
            cube([
                garra_comprimento,
                garra_largura,
                garra_altura
            ]);

            // Ponta da garra
            translate([
                garra_comprimento - 10,
                0,
                0
            ])

            cube([
                10,
                garra_largura + 5,
                garra_altura
            ]);

            // Dentes
            for(i = [0:2]){

                translate([
                    garra_comprimento - 8,
                    3 + (i * 5),
                    garra_altura
                ])

                cube([
                    dente_largura,
                    2,
                    dente_altura
                ]);
            }

            // Pivô lateral visual
            translate([
                5,
                garra_largura/2,
                garra_altura/2
            ])

            rotate([90,0,0])

            cylinder(
                h = 4,
                r = 2.5,
                $fn = 30
            );
        }

        // Furos de redução de massa
        for(i = [1:quantidade_furos]){

            translate([
                10 + (i * 10),
                garra_largura / 2,
                -1
            ])

            cylinder(
                h = 20,
                r = 2,
                $fn = 20
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
// SUPORTE DO SERVO SG90
// =====================================================

module suporte_servo(){

    difference(){

        // Corpo externo
        cube([
            servo_largura + 6,
            servo_profundidade + 6,
            servo_altura
        ]);

        // Espaço interno do servo
        translate([
            3,
            3,
            2
        ])

        cube([
            servo_largura + folga,
            servo_profundidade + folga,
            servo_altura
        ]);

        // Furos dos parafusos
        translate([4,4,-1])

        cylinder(
            h = 10,
            r = 1.2,
            $fn = 20
        );

        translate([
            servo_largura + 2,
            4,
            -1
        ])

        cylinder(
            h = 10,
            r = 1.2,
            $fn = 20
        );

        translate([
            4,
            servo_profundidade + 2,
            -1
        ])

        cylinder(
            h = 10,
            r = 1.2,
            $fn = 20
        );

        translate([
            servo_largura + 2,
            servo_profundidade + 2,
            -1
        ])

        cylinder(
            h = 10,
            r = 1.2,
            $fn = 20
        );
    }
}


// =====================================================
// MONTAGEM FINAL
// =====================================================

module braco_robotico(){

    // Base
    base_central();

    // Suporte do servo
    translate([
        -15,
        -10,
        8
    ])

    suporte_servo();

    // Acoplamento do servo
    translate([
        0,
        0,
        base_altura
    ])

    acoplamento_servo();

    // Garra esquerda
    translate([
        8,
        espaco_garra/2,
        10
    ])

    garra_esquerda();

    // Garra direita
    translate([
        8,
        -espaco_garra/2,
        10
    ])

    garra_direita();
}


// =====================================================
// EXECUÇÃO
// =====================================================

braco_robotico();