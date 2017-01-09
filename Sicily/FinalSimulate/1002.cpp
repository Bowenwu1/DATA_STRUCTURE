void List::insert(int toadd, int pos) {
    ListNode* temp = head;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }
    ListNode* tempNext = temp->next;
    temp->next = new ListNode();
    temp->next->data = toadd;
    temp->next->next = tempNext;
}