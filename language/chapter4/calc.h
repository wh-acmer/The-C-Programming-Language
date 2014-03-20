/* header file of calculator */

#define NUMBER '0'
#define SIN '1'
#define COS '2'
#define POW '3'
#define NONECMD '4'
#define VAR '5'
#define LAST '6'

#define CMD_LEN 20

void push(double val);

double pop();

double gettop();

void duptop();

void swaptop();

void clear();

int parse_cmd(int cstart);

int parse_var(int cstart);

int getop(char str[]);

int getch();

void ungetch(int cval);

void ungets(char s[]);

void setvar(double dval);

double getvar(int last);

void mgetline(char line[]);
