package interview.recursion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Combinations {

    /**
     * Generates all combinations and output them,
     * selecting n elements from data
     * @param data
     * @param n
     */
    public void combinations(List<Integer> selected, List<Integer> data, int n) {
        // select element 0

        if(n == 0){
            // output all selected elements
            for (Integer i : selected){
                System.out.print(i);
                System.out.print(' ');
            }
            System.out.println();
            return;
        }

        if(data.isEmpty()) {
            return ;
        }

        selected.add(data.get(0));
        combinations(selected, data.subList(1, data.size()), n-1);
        
        selected.remove(selected.size() - 1);
        combinations(selected, data.subList(1, data.size()), n);
    }

    public static void main(String[] args) {
        Combinations comb = new Combinations();
        comb.combinations(new ArrayList<>(), Arrays.asList(1, 2, 3, 4), 2);
        System.out.println("=============");
        comb.combinations(new ArrayList<>(), new ArrayList<>(), 2);
        System.out.println("=============");
        comb.combinations(new ArrayList<>(), new ArrayList<>(), 0);
        System.out.println("=============");
        comb.combinations(new ArrayList<>(), Arrays.asList(1, 2, 3, 4), 1);
        System.out.println("=============");
        comb.combinations(new ArrayList<>(), Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 3);

    }
}
