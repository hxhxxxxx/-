题目：
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素

解题思路：这里借用了一个辅助栈来记录最小值，先在辅助栈中入住一个最大元素，然后后续入栈的元素会跟辅助栈的栈顶元素相比，记录其较小值
这样就可以储存每个阶段当前栈内的最小值。而原先想用一个数字储存但是如果出栈后就会丢失最小值，或者可以用链表储存最小值即可

class MinStack {
private:
    stack<int>x_stack;
    stack<int>min_stk;
public:
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        x_stack.push(val);
        min_stk.push(min(min_stk.top(),val));
    }
    
    void pop() {
        x_stack.pop();
        min_stk.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
