//* Lexer turns int x = y + 9
// into tokens.

#ifndef LEXER_H
#define LEXER_H

#include "tokens.h"

typedef struct {
    const char* src;
    int pos;
    char current;
} Lexer;

void lexer_init(Lexer* l, const char* input);
Token lexer_next_token(Lexer* l);

#endif
