/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode collection = new ListNode(0);
        ListNode head = collection;
        
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                collection.next = list1;
                list1 = list1.next;
                collection = collection.next;
            } else {
                collection.next = list2;
                list2 = list2.next;
                collection = collection.next;
            }
        }
        
        if (list1 != null) {
            collection.next = list1;
            list1 = list1.next;
            collection = collection.next;
        } else if (list2 != null) {
            collection.next = list2;
            list2 = list2.next;
            collection = collection.next;
        }
        
        return head.next;
    }
}