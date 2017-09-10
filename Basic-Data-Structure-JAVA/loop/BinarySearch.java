package interview.loop;

import interview.common.Node;

import java.util.Arrays;

public class BinarySearch {

    public int binarySearch(int[] data, int val) {
        int start = 0;
        int stop = data.length - 1;
        int mid;

        while(start <= stop) {
//            mid = (start + stop) / 2; // ( start + stop ) maybe overflow!
            mid = start + (stop - start) / 2;
            if(data[mid] == val) {
                return mid;
            }else {
                if(data[mid] > val) {
                    stop = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        BinarySearch bs = new BinarySearch();
        System.out.println((bs.binarySearch(new int[]{},4)));
        System.out.println((bs.binarySearch(new int[]{4, 1},4)));
        System.out.println((bs.binarySearch(new int[]{1, 4},4)));
        System.out.println((bs.binarySearch(new int[]{1, 2, 4},4)));
        System.out.println((bs.binarySearch(new int[]{1, 2, 10, 15, 100},15)));
    }
}