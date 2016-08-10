public class MergeBU {
	private static Comparable[] aux;	// helper array

	public static void merge(Comparable[] a, int lo, int mid, int hi) {
		// merge a[lo..mid] and a[mid + 1, hi]
		int i = lo, j = mid + 1;

		// Copy a[lo..hi] to aux[lo..hi]
		for (int k = lo; k <= hi; k++) {
			aux[k] = a[k];
		}

		// Merge to a[lo..hi]
		for(int k = lo; k <= hi; k++) {
			if(i > mid) a[k] = aux[j++];
			else if(j > hi) a[k] = aux[i++];
			else if(less(aux[j], aux[i])) a[k] = aux[j++];
			else a[k] = aux[i++];
		}
	}

	public static void sort(Comparable[] a) {
		// Merge logN times
		int N = a.length;
		aux = new Comparable[N];
		for(int sz = 1; sz < N; sz = sz + sz) {
			for(int lo = 0; lo < N - sz; lo += sz + sz) {
				merge(a, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, N - 1));
			}
		}
	}
}