/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* detectLoop(Node *head){
        if(head == NULL) return NULL;
    
        Node* slow = head;
        Node* fast = head;
    
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
    
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
    
    Node* getStartNode(Node *head){
        if(head == NULL) return NULL;
    
        Node* intersection = detectLoop(head);// floyd's algorithm
        if(intersection == NULL) return NULL;
        
        Node* slow = head;
    
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
    
        return slow;
    }

Node *removeLoop(Node *head)
{
    if(head == NULL) return NULL;

        Node* startofLoop = getStartNode(head);
    	if(startofLoop == NULL) return head;
    
        Node* temp = startofLoop;
    
        while(temp->next != startofLoop){
            temp = temp->next;
        }
        temp->next = NULL;
    	return head;
}