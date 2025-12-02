#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"
#include "tokens.h"

static void advance(Lexer* l) {

}

static char peek(Lexer* l) {

}

static Token make_token(TokenType type, const char* text) {

}

static Token make_int_token(int value) {

}

// Constructor of Lexer
void lexer_init(Lexer* l, const char* input) {
    l->src = input;
    l->pos = 0;
    l->current = input[0];
}

Token lexer_next_token(Lexer* l) {
  // dummy
    return make_token(l->current, &l->src[l->pos]);
}
