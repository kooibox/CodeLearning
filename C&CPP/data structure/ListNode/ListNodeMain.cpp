#include <bits/stdc++.h>
using namespace std;

// 定义一个节点模板
template <typename T>

struct Node
{
    T data;
    // 数据域
    Node *next;
    // 指针域
    Node() : next(nullptr) {}
    Node(const T &d) : data(d), next(nullptr) {}
};

// 删除p结点后面的元素
template <typename T>
void Remove(Node<T> *p)
{
    if (p == nullptr || p->next == nullptr)
        return;

    auto tmp = p->next->next;
    delete p->next;
    p->next = tmp;
}

// 在p结点后面插入元素
template <typename T>
void Insert(Node<T> *p, const T &d)
{
    auto tmp = new Node<T>(data);
    tmp->next = p->next;
    p->next = tmp;
}

// 遍历链表
template <typename T, typename V>
void Walk(Node<T> *p, const V &visitor)
{
    while (p != nullptr)
    {
        visitor(p);
        p = p->next;
    }
}
int main()
{
    auto p = new Node<int>(1);
    Insert(p, 2);
    int sum = 0;
    Walk(p, [&sum](const Node<int> *p) -> void
         { sum += p->data; });
    cout << sum << endl;
    Remove(p);
    sum = 0;
    Walk(p, [&sum](const Node<int> *p) -> void
         { sum += p->data; });
    cout << sum << endl;
    return 0;
}

// 这段代码定义了一个链表节点模板（Node），并实现了删除、插入和遍历链表的功能。以下是代码的详细解释：
// 1. 定义一个节点模板（Node）：这个模板定义了一个数据域（data）和一个指针域（next），用于存储链表中的数据和指向下一个节点的指针。
// 2. 删除p结点后面的元素：这个函数接受一个指向链表节点的指针p，并删除p结点后面的元素。首先检查p是否为空或者p的下一个节点是否为空，如果满足条件，则将p的下一个节点的指针赋值给tmp，然后删除p的下一个节点，最后将p的指针指向tmp。
// 3. 在p结点后面插入元素：这个函数接受一个指向链表节点的指针p和一个要插入的数据元素d，然后在p结点后面插入一个新的节点，新节点的数据域为d，指针域指向p的下一个节点。
// 4. 遍历链表：这个函数接受一个指向链表节点的指针p和一个访问者（visitor），用于处理遍历过程中的每个节点。在遍历过程中，对每个节点执行visitor函数，并将节点指针p传递给visitor。
//    在main函数中，首先创建一个链表节点p，并插入一个元素2。然后定义一个变量sum，用于存储遍历链表过程中累加的元素和。使用Walk函数遍历链表，将每个节点的数据累加到sum中。最后删除p结点，并再次遍历链表，将每个节点的数据累加到sum中。
