package interview.loop;

import interview.common.Node;


public class LinkedListReverse {

    public Node linkedListReverse(Node head) {
        Node newHead = null;
        Node curHead = head;

        while(curHead != null) {
            Node next = curHead.getNext();
            curHead.setNext(newHead);
            newHead = curHead;
            curHead = next;
        }

        return newHead;
    }

    public Node createLargeLinkedList(int n) {
        Node head = null;

        if(n > 0) {
            head = new Node(1);
        }

        Node curNode = head;

        for(int i=2; i<=n; i++) {
            Node next = new Node(i);
            curNode.setNext(next);
            curNode = curNode.getNext();
        }

        return head;
    }


    public static void main(String[] args) {
        LinkedListReverse loopTest = new LinkedListReverse();
        Node list = loopTest.createLargeLinkedList(10);
        Node.printLinkedList(list);
        Node revList = loopTest.linkedListReverse(list);
        Node.printLinkedList(revList);
    }
}
