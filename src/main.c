#include <stdio.h>
#include <stdlib.h>

typedef enum ValidTokens {
  CHAR,
  POUND,
  NEW_LINE,
  SPACE,
} ValidTokens;

typedef struct Token {
  ValidTokens token;
  char default_value;
  char value;
} Token;

Token tokens[] = {
    {.token = CHAR},
    {.token = POUND, .default_value = '#'},
    {.token = NEW_LINE, .default_value = '\n'},
    {.token = SPACE, .default_value = ' '},
};

const size_t num_valid_tokens = sizeof(tokens) / sizeof(tokens[0]);

int find_token_by_default_value(char c) {
  int i;
  for (i = 0; i < num_valid_tokens; ++i) {
    if (c == (tokens[i]).default_value) {
      return i;
    }
  }
  return -1;
}

Token match_token(char c) {
  int i;
  Token t;

  t = tokens[0];
  i = find_token_by_default_value(c);

  if (i == -1) {
    t.value = c;
    return t;
  }

  return tokens[i];
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s <file.md>\n", argv[0]);
    exit(1);
  }

  char t = '#';
  Token match = match_token(t);

  printf("%d - '%c' - '%c'\n", match.token, match.default_value, match.value);

  // FILE *fptr;
  // int c, max_tokens;
  // long int pos;

  // max_tokens = 200;
  // struct Token tokens[max_tokens];

  // fptr = fopen(argv[1], "rt");
  // if (fptr == NULL) {
  //   fprintf(stderr, "Failed to open output file\n");
  //   exit(1);
  // }

  // while ((c = fgetc(fptr)) != EOF) {

  // }

  // fclose(fptr);
  return 0;
}