# 🚀 Roadmap del Proyecto: Compilador C → AVR (ATmega328P)
Proyecto: **NanoC-AVR**  
Objetivo: Crear un compilador para un subconjunto de C que genere código máquina AVR para el ATmega328P, incluyendo ensamblador propio y simulación.  
Plataforma de desarrollo: **Mac M3**

---

# 🟦 Sprint 1 — Definición del lenguaje + setup

### 🎯 Objetivo
Definir el subconjunto de C y preparar el entorno del proyecto.

### ✔ Tareas
- Definir el subconjunto de C:
    - Tipos: `uint8`, `uint16`, `bool`
    - Control de flujo: `if`, `while`
    - Funciones simples sin stack complejo
    - Variables globales y locales estáticas
- Crear documento: **Especificación del Lenguaje NanoC**.
- Estructura inicial del proyecto:
    - /compiler
    - /assembler
    - /docs
    - /tests 

- Instalar herramientas:
    
  - `clang` o `gcc`
  - `make`
  - `simulavr`
  - `avr-gdb`
---

# 🟦 Semana 2 — Implementación del LEXER

### 🎯 Objetivo
Transformar texto en tokens.

### ✔ Tareas
- Implementar:
- identificadores
- números
- palabras reservadas
- operadores `+ - * / = == != < >`
- símbolos `{ } ( ) ;`
- Manejo de errores léxicos.
- Tests del lexer.

### 🧪 Entregable
Archivo `tokens.txt` generado desde código C simple.

---

# 🟦 Semana 3 — Implementación del PARSER

### 🎯 Objetivo
Construir el AST desde tokens.

### ✔ Tareas
- Parser recursivo descendente.
- Reglas:
- `expression`
- `term`
- `factor`
- `statement`
- `block`
- `if_stmt`
- `while_stmt`
- `func_decl`
- Validar estructura correcta.

### 🧪 Entregable
Visualización del AST en formato JSON-like.

---

# 🟦 Semana 4 — Análisis Semántico

### 🎯 Objetivo
Agregar verificación lógica.

### ✔ Tareas
- Tabla de símbolos:
- variables globales
- variables locales
- funciones
- Tipos:
- inferencia simple
- validación de operaciones
- Detectar variables no declaradas.

### 🧪 Entregable
Reporte de errores semánticos.

---

# 🟦 Semana 5 — IR (Intermediate Representation)

### 🎯 Objetivo
Crear representación intermedia tipo “tres direcciones”.

### ✔ Tareas
- Diseñar IR 3AC:
    - t1 = x + y
        if t1 < 10 goto L1

- Traducir AST a IR.
- Optimizaciones básicas:
- constant folding
- dead code elimination simple

### 🧪 Entregable
Código IR generado desde un programa NanoC.

---

# 🟦 Semana 6 — Generación de AVR Assembly

### 🎯 Objetivo
Traducir IR a instrucciones AVR reales.

### ✔ Tareas
- Mapear registros virtuales → `R16–R31`
- Generar:
- `LDI`, `LDS`, `STS`
- `ADD`, `SUB`, `AND`, `OR`, `CPI`
- `RJMP`, `BREQ`, `BRNE`
- Optimizaciones de registros.

### 🧪 Entregable
Archivo `.s` compilado desde programa NanoC.

---

# 🟦 Semana 7 — Ensamblador propio (AVR → HEX)

### 🎯 Objetivo
Convertir assembly a opcodes para el ATmega328P.

### ✔ Tareas
- Parser de instrucciones AVR.
- Tablas de opcodes para tu subconjunto.
- Resolver labels.
- Generar binario `.hex` o `.bin`.

### 🧪 Entregable
Archivo `.hex` generado por tu ensamblador.

---

# 🟦 Semana 8 — Simulación

### 🎯 Objetivo
Probar el binario sin hardware.

### ✔ Tareas
- Usar simulavr:
    - simulavr -d atmega328p -f program.hex

- Scripts automáticos (Makefile).
- Simulación básica de GPIO.
- Opcional: integración con **Wokwi**.

### 🧪 Entregable
Programa NanoC corriendo en simulador.

---

# 🟦 Semana 9 — Mini estándar (stdlib minimal)

### 🎯 Objetivo
Crear una librería mínima para interacción con hardware.

### ✔ Tareas
- Biblioteca en Assembly:
- `delay_ms()`
- `pin_write(pin, value)`
- `pin_mode(pin, mode)`
- Compilar con tu ensamblador.

### 🧪 Entregable
Programas NanoC usando GPIO simulado.

---

# 🟦 Semana 10 — Pruebas en hardware real

### 🎯 Objetivo
Ejecutar código en un Arduino UNO o ATmega328P real.

### ✔ Tareas
- Comprar Arduino UNO (o usar uno que tengas).
- Flashear usando avrdude:
  - avrdude -p m328p -c arduino -P /dev/tty.usbmodemXXXX -U flash:w:program.hex

- Probar:
- Blink
- Botón
- PWM

### 🧪 Entregable
Primer programa NanoC funcionando en hardware real.

---

# 🟪 Extensiones opcionales
- Heap + `malloc`
- Soporte para recursión
- Mejor optimizador
- Debugger propio
- Backend basado en LLVM
- Multitarea cooperativa

---

