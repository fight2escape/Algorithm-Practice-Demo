package interview.recursion;

import interview.common.Node;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LinkedListCreator {

    public Node createLinkedList(List<Integer> data) {
        if (data.isEmpty()) {
            return null;
        }
        Node firstNode = new Node(data.get(0));
        firstNode.setNext(createLinkedList(data.subList(1, data.size())));
        return firstNode;
    }

    public static void main(String[] args) {
        LinkedListCreator creator = new LinkedListCreator();

        Node.printLinkedList(creator.createLinkedList(new ArrayList<>()));
        Node.printLinkedList(creator.createLinkedList(Arrays.asList(1)));
        Node.printLinkedList(creator.createLinkedList(Arrays.asList(1, 2, 3, 4, 5)));

    }
}
