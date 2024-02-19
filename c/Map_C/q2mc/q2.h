#define STK_SIZE 20
static int stk_ptr = 0;
static char stack[STK_SIZE]; 

void insert(char *arg);
void calculate(char op);
void print_result();
