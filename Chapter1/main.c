#include <stdio.h>

int hello(void) {
  printf("hello, world\n");
  return 0;
}

int fahr_cels(void) {
  /* Print Farhenheit-Celcius table for fahr = 0, 20, ..., 300 */
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("fahr | celsius\n");
  printf("______________\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f  | %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

int cels_fahr(void) {
  /* Print Farhenheit-Celcius table for fahr = 0, 20, ..., 300 */
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("celsius | fahr\n");
  printf("______________\n");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0 * celsius) + 32;
    printf("%6.1f  | %3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;
}

int for_loop_temps(void) {
  int fahr;
  for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
  return 0;
}

int for_loop_temps_reversed(void) {
  int fahr;
  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
  return 0;
}

#define LOWER 0
#define UPPER 300
#define STEP 20

int for_loop_temps_define(void) {
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
  return 0;
}

int io_one() {
  int c;
  c = getchar();
  printf("%s", "from io_one\n");
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  return 0;
}

int io_two() {
  printf("%s", "from io_two\n");
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
  return 0;
}

int count_chars_one() {
  long nc;
  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("%ld\n", nc);
  return 0;
}

int count_chars_two() {
  double nc;
  for (nc = 0; getchar() != EOF; ++nc) {
    printf("%.0f\n", nc);
  }
  return 0;
}

int line_count() {
  int c, nl;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == 'n') {
      ++nl;
    }
    printf("%d\n", nl);
  }
  return 0;
}

#define IN 1
#define OUT 0
int word_counting(void) {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  return 0;
}

int array_counts(void) {
  int c, i, nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
    printf("digits =");
    for (i = 0; i < 10; ++i) {
      printf("%d,", ndigit[i]);
    }
    printf(" white spaces = %d, other = %d\n", nwhite, nother);
  }
  return 0;
}

int main(void) {
  // hello();
  // fahr_cels();
  // cels_fahr();
  // for_loop_temps();
  // for_loop_temps_reversed();
  // for_loop_temps_define();
  // io_one();
  // io_two();
  // count_chars_one();
  // count_chars_two();
  // line_count();
  // word_counting();
  array_counts();
  return 0;
}
