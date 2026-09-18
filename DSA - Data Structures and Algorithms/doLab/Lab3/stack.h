#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
   double* values; // 真正的数值存在 values 数组中
   int top; // 当前栈顶位置
   int maxTop; // 最大的栈顶位置
} Stack;

bool CreateStack(Stack* stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Top(Stack* stack, double* x);
bool Push(Stack* stack, double x);
bool Pop(Stack* stack, double* x);
void DisplayStack(Stack* stack);
void DestroyStack(Stack** stack);
