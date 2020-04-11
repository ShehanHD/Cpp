typedef struct self{
    int x;
    struct self* next;
}NODE;

NODE* create(NODE* head);
NODE* add(NODE* head, int val, int possition);  // terza prametro si dice a dove inserisce coda o testa
    NODE* addToHead(NODE* head, int val);
    NODE* addToTail(NODE* head, int val);
    NODE *addInMiddle(NODE *head, int val, int where);
NODE* del(NODE* head, int possition);           // seconda prametro si dice da dove elimina coda o testa
    NODE* delFromHead(NODE* head);
    NODE* delFromTail(NODE* head);
void printList(NODE *head);
