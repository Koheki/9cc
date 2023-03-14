#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token Token;
typedef struct Node Node;

typedef enum {
    TK_RESERVED,
    TK_IDENT,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_ASSIGN,
    ND_LVAR,
    ND_EQ,
    ND_NE,
    ND_LT,
    ND_LE,
    ND_NUM,
} NodeKind;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
    int offset;
};

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

extern char *user_input;
extern Token *token;
extern Node *code[100];

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
Token *tokenize();

void gen(Node *node);
