//Remove Zero Sum Consecutive Nodes from Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int j=0;
      ListNode* h=head;
      vector<int> v;
      while(h)
      {
          v.push_back(h->val);
          h=h->next;
      }
      vector<int> a;
      for(int i=0;i<v.size();i++)
      {
          int s=0;int id=i;
         for(int j=i;j<v.size();j++)
         {
          s+=v[j];
          if(s==0)
          {i=j;
          break;}
         }
         if(s!=0)
         a.push_back(v[id]);
      }
      ListNode* f=new ListNode(0);
      head=f;
      for(auto i : a)
      {
          f->next=new ListNode(i);
          f=f->next;
      }
      return head->next;
    }
};