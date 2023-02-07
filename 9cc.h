#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token Token;
typedef struct Node Node;

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_EQ,
    ND_NE,
    ND_LT,
    ND_LE,
    ND_NUM,
} NodeKind;

typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;


struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
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

bool consume(char *op);
void expect(char *op);
int expect_number();
Token *tokenize();

void gen(Node *node);