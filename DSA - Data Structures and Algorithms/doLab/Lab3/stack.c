#include <stdio.h>
#include "stack.h"

bool CreateStack(Stack* stack, int size)
{
    // TODO:
    /* 用这种方式创建栈, 分为 3 步骤:  1. 先我要给 valudes 数组开辟空间 2. 设置 top 的位置 3. 设置 max_top 的值
    */
    if (size <= 0) return false;

    stack->values = (double*)malloc(sizeof(double) * size);
    if (stack->values == NULL) return false;

    stack->top = -1; // -1 代表当前位置不存在
    stack->maxTop = size - 1;

    return true;
}

bool IsFull(Stack* stack)
{
    // TODO:
    // 比较 top 和 max_top 的位置就行了
    if (stack->top == stack->maxTop) return true;
    return false;
}

bool IsEmpty(Stack* stack)
{
    // TODO:
    // 看 top 的位置就行了
    if (stack->top != -1) return false;
    return true;
}

bool Push(Stack* stack, double x)
{
    // TODO:
    // x 表示入栈的数
    /* 思路是: 1.先判断一下栈还有没有一个多余的位置 2. top++ 3. 在 values 中插入这个 x 到top 的位置(因为这个 top 代表的是当前位置, 而不是下一个空位置)
    */
    if (stack->top >= stack->maxTop) return false;

    stack->top++;
    stack->values[stack->top] = x;
    return true;
}

bool Pop(Stack* stack, double* x)
{
    // TODO:
    /* 思路是: 1. 判断一下栈中还有没有数了 2. 将 top 写入到 x 中 3. 将 top--
    */
    if (stack->top < 0) return false;
    *x = stack->values[stack->top];
    stack->top--;
    return true;
}

bool Top(Stack* stack, double* x)
{
    // TODO:
    // 我们需要将栈顶元素输出到 x 中, 而不是直接函数输出...
    /* 思路是: 1. 判断一下还有没有数在栈中 2. 将 values 数组的 top 位置的数 输出到 x 中
     */
    if (stack->top < 0)
        return false;
    *x = stack->values[stack->top];
    return true; 
}

void DisplayStack(Stack* stack)
{
    // TODO:
    /* 思路是: 1. 判断这个栈是否存在 2.使用一个标志位 p 从 top 开始一直到 0
    */
    if (!stack) return;
    for (int p = stack->top; p >= 0; p--)
    {
        printf("%.6f\n", stack->values[p]);
    }
}

void DestroyStack(Stack** stack)
{
    // TODO:
    /* 思路是: 1. 判断一下 stack 是不是 NULL 判断一下 *stack 是不是 NULL 2. 记得要先释放 values 数组的内存 3. 再去释放 struct stack 的内存
    */
    if (stack == NULL || *stack == NULL) return;
    free((*stack)->values);
    free(*stack);
    *stack = NULL;
}

