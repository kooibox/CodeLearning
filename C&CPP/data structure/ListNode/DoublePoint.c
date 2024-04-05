// Floyd算法（龟兔赛跑算法）
    // 假想「乌龟」和「兔子」在链表上移动，「兔子」跑得快，「乌龟」跑得慢。
    // 当「乌龟」和「兔子」从链表上的同一个节点开始移动时，如果该链表中没有环，那么「兔子」将一直处于「乌龟」的前方；
    // 如果该链表中有环，那么「兔子」会先于「乌龟」进入环，并且一直在环内移动。
    // 等到「乌龟」进入环时，由于「兔子」的速度快，它一定会在某个时刻与乌龟相遇，即套了「乌龟」若干圈。
    // 具体地，我们定义两个指针，一快一慢。慢指针每次只移动一步，而快指针每次移动两步。
    // 初始时，慢指针在位置 head，而快指针在位置 head.next。这样一来，如果在移动的过程中，快指针反过来追上慢指针，就说明该链表为环形链表。
    // 否则快指针将到达链表尾部，该链表不为环形链表。

//如果使用while循环，由于循环条件先于循环体，循环条件是判断快慢指针是否重逢。
//将两个指针的初始位置都设置在链表的 head 那么while循环就不会执行。
//因此我们可以假想一个在 head 之前的 虚拟节点。慢指针从虚拟节点移动 一步到达 head，快指针从虚拟节点移动 两步 到达 head.next
//如果使用do-while循环。就可以将快慢指针的初始位置设置为head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//检查链表中是否存在环
bool hasCycle(struct ListNode *head) {
    //如果链表为空或者只有一个节点，则不存在环
    if(head == NULL || head->next == NULL){return false;}
    //定义慢指针和快指针，指向头节点
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    //快指针每次移动两步，慢指针每次移动一步
    while(slow != fast){
        //如果快指针或者快指针的下一个节点为空，则不存在环
        if(fast == NULL || fast->next == NULL){return false;}
        //快指针每次移动两步
        fast = fast->next->next;
        //慢指针每次移动一步
        slow = slow->next;
    }
    //当快指针和慢指针相遇时，表示存在环
    return true;
}