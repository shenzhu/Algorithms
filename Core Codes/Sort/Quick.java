public class Quick {
	public static void sort(Comparable[] a) {
		StdRandom.shuffle(a);		// remove dependency for input
		sort(a, 0, a.length - 1);
	}

	private static void sort(Comparable[] a, int lo, int hi) {
		if(hi <= lo) return;
		int j = partition(a, lo, hi);		// partition
		sort(a, lo, j - 1);		// sort left half a[lo..j-1]
		sort(a, j + 1, hi);		// sort right half a[j+1..hi]
	}

	private static int partition(Comparable[] a, int lo, int hi) {
		int i = lo, j = hi + 1;
		Comparable v = a[lo];

		while(true) {
			// scan left and right
			while(less(a[++i], v)) if(i == hi) break;
			while(less(v, a[--j])) if(j == lo) break;
			if(i >= j) break;
			exch(a, i, j);
		}
		exch(a, lo, h);		// put v = a[j] to right position

		return j;
	}
}