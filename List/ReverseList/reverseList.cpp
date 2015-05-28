#include <iostream>

using std::cout;
using std::endl;

struct ListNode
{
  int mValue;
  ListNode* mNext;
};

ListNode* reverseList(ListNode* pRoot)
{
  if (pRoot == NULL) return NULL;
  ListNode* r = NULL;
  while (pRoot != NULL) {
    ListNode* pNext = pRoot->mNext;
    pRoot->mNext = r;
    r = pRoot;
    pRoot = pNext;
  }

  return r;
}

int main(void)
{
  ListNode* pHead = NULL;
  ListNode* pCur, * pPrev;
  for (int i = 0; i < 6; i++) {
    pCur = new ListNode();
    pCur->mValue = i;
    pCur->mNext = NULL;

    if (pHead == NULL) pHead = pCur;
    else        pPrev->mNext = pCur;

    pPrev = pCur;
    pCur = pCur->mNext;
  }
  pHead = reverseList(pHead);
  cout << "pHead->mValue = " << pHead->mValue << endl;

  ListNode** pRoot = &pHead;

  while (pRoot && *pRoot) {
    ListNode * tmp = *pRoot;
    cout << tmp->mValue << endl;
    *pRoot = (*pRoot)->mNext;
    delete tmp;
  }

  cout << endl;
  pHead = NULL;
  pHead = reverseList(pHead);
  cout << pHead << endl;

  return 0;
}
