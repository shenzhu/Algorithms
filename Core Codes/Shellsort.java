public class Shellsort{
    public static void sort(Comparable[] a){
        // Sort a[] into increasing order
        int N = a.length;
        int h = 1;
        while(h < N / 3) h = 3 * h + 1;     // 1, 4, 13, 40, 121, 364, 1093, ...
        while(h >= 1){
            // H-sort the array
            for(int i = h; i < N; i++){
                // Insert a[i] among a[i - h], a[i - 2 * h], a[i - 3 * h]...
                for(int j = i; j >= h && less(a[j], a[j - h]); j -= h){
                    exch(a, j, j - h);
                }
            }
            h = h / 3;
        }
    }

    private static boolean less(Comparable v, Comparable w){
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j){
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void show(Comparable[] a){
        // Print the array, on a single line
        for(int i = 0; i < a.length; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static boolean isSorted(Comparable[] a){
        // Test whether the array entries are in order
        for(int i = 1; i < a.length; i++){
            if(less(a[i], a[i - 1])) return false;
        }
        return true;
    }
}