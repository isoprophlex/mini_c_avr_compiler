#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
    TOK_UINT8,
    TOK_UINT16,
    TOK_BOOL,
    TOK_IF,
    TOK_WHILE,
    TOK_RETURN,
    TOK_VOID,

    TOK_IDENT,
    TOK_INT_LITERAL,
    TOK_BOOL_LITERAL,

    TOK_PLUS,
    TOK_MINUS,
    TOK_MUL,
    TOK_DIV,
    TOK_ASSIGN,
    TOK_EQ,
    TOK_NEQ,
    TOK_LT,
    TOK_GT,
    TOK_LE,
    TOK_GE,

    // Símbolos
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_SEMICOLON,

    // Fin
    TOK_EOF,
    TOK_INVALID
} TokenType;

typedef struct {
    TokenType type;
    char* text;     // para identificadores y literales
    int int_value;  // valores numéricos
} Token;

#endif
