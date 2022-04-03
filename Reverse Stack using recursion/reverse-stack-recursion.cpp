void insertAtBottom(stack<int> &s,int n){
    if(s.empty()){
        s.push(n);
        return;
    }
 
    int elem = s.top();
    s.pop();
    
    insertAtBottom(s,n);
    s.push(elem);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()) return;
    
    int num = stack.top();
    stack.pop();
    
    reverseStack(stack);
    insertAtBottom(stack,num);
}