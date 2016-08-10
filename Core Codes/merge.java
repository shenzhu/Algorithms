public class Merge {
	
	private static Comparable[] aux;		// helper array for merge sort

	public static void sort(Comparable[] a) {
		aux = new Comparable[a.length];		// allocate memory
		sort(a, 0, a.length - 1);
	}

	public static void merge(Comparable[] a, int lo, int mid, int hi) {
		// merge a[lo..mid] and a[mid + 1, hi]
		int i = lo, j = mid + 1;

		// Copy a[lo..hi] to aux[lo..hi]
		for (int k = lo; k <= hi; k++) {
			aux[k] = a[k];
		}

		// Merge a[lo..hi]
		for (int k = lo; k <= hi; k++) {
			if (i > mid) a[k] = aux[j++];
			else if (j > hi) a[k] = aux[i++];
			else if (less(aux[j], aux[i])) a[k] = aux[j++];
			else a[k] = aux[i++];
		}
	}

	private static void sort(Comparable[] a, int lo, int hi) {
		// sort array a[lo..hi]
		if (hi <= lo) return;
		int mid = low + (hi - lo) / 2;
		sort(a, lo, mid);		// sort left half
		sort(a, mid + 1, hi);	// sort right half
		merge(a, lo, mid, hi);	// merge
	}
}