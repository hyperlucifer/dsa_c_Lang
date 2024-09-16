/*
Algo

1)scan the exp from right to  left 
2)for each char in prefix exp
    do 
        if operatent is there push it into stack
        else if =operator is there ,pop 2 elements
            op1=top element; 
            op2=next to top element; 
            result =op1 operator op2;
        push result into the stack 
        return stack[top];
*/