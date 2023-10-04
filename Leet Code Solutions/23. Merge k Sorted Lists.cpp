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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;

        if(lists.size()==0)
        return NULL;
        
        for(auto x:lists){
            ListNode*tmp=x;
           while(tmp!=NULL){
               pq.push(tmp->val);
               tmp=tmp->next;
           }
        }
        if(pq.empty())
        return NULL;

        ListNode* node=new ListNode(pq.top());
        ListNode*res=node;

        ListNode* dummy= new ListNode(0);
        dummy->next=res;
        pq.pop();
        while(!pq.empty()){
            ListNode* node=new ListNode(pq.top());
            res->next=node;
            pq.pop();
            res=res->next;
        }
        return dummy->next;
    }
};
