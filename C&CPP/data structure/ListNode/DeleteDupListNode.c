//删除链表重复元素
//方法：一次遍历。从指针cur指向链表的头节点，随后开始遍历。
//     如果当前的cur与cur.next对应的元素相同，那么就把cur.next从链表中移除；
//     否则说明链表中不存在其他与cur对应的元素相同的节点，因此可以将cur指向cur.next
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode* cur = head;
    while (cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}


// struct ListNode* deleteDuplicates(struct ListNode* head){
//     struct ListNode* p = head;
//     while (p && p->next)
//         if (p->val == p->next->val) p->next = p->next->next;
//         else p = p->next;
//     return head;
// }
