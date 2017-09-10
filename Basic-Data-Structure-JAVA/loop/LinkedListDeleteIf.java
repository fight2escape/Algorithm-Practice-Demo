package interview.loop;

import interview.common.Node;

import java.util.Arrays;
import java.util.List;

public class LinkedListDeleteIf {

    public Node linkedListDeleteIf(Node head, int val) {
        while(head != null && head.getValue() == val) {
            head = head.getNext();
        }
        if(head == null) {
            return null;
        }
        Node prev = head;

        // prev != null
        while(prev.getNext() != null) {
            if(prev.getNext().getValue() == val) {
                prev.setNext(prev.getNext().getNext());
            }else{
                prev = prev.getNext();
            }
        }
        return head;
    }

    public Node createLinkedList(List<Integer> data) {
        Node head = null;
        Node curr = null;
        if(data.size() <= 0){
            return head;
        }

        do {
            Node node = new Node(data.get(0));
            if(head == null){
                head = node;
                curr = node;
            }else{
                curr.setNext(node);
                curr = curr.getNext();
            }
            data = data.subList(1, data.size());
        } while(data.size() > 0);

        return head;
    }


    public static void main(String[] args) {
        LinkedListDeleteIf deleteIf = new LinkedListDeleteIf();
        Node test = deleteIf.createLinkedList(Arrays.asList(2,2,3,2,2));
        Node.printLinkedList(test);
        Node head = deleteIf.linkedListDeleteIf(test, 2);
        Node.printLinkedList(head);
    }
}
