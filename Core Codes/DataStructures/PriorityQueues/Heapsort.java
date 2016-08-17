public class Heapsort {
	public static void sort(Comparable[] a) {
		int N = a.length;

		// Construct heap
		for(int k = N / 2; k >= 1; k--) {
			sink(a, k, N);
		}

		// Sort
		while(N > 1) {
			exch(a, 1, N--);
			sink(a, 1, N);
		}
	}
}