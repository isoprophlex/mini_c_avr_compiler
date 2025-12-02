# NanoC Language Specification

## 1. Tipos
- uint8
- uint16
- bool

## 2. Operadores
/, + -, *, 

### Comparación

==, !=, <, >, <=, >=

### Lógicos

&&, ||, !

### Asignación

=

## 3. Gramática (BNF aproximada)
program -> decl_list
decl_list -> decl decl_list | ε
decl -> func_decl | var_decl
func_decl -> type IDENT "(" ")" block
block -> "{" stmt_list "}"
stmt_list -> stmt stmt_list | ε
stmt -> var_decl ";" | assign ";" | if_stmt | while_stmt
(… completar luego …)

## 4. Reglas semánticas
- variables deben declararse
- tipos deben coincidir
- etc.

## 5. Ejemplos de programas válidos

```
uint8 led = 13;

void main() {
    uint8 x = 1;
    while (x < 10) {
        x = x + 1;
    }
}
```