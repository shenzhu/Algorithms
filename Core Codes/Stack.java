Class Stack<E>
java.lang.Object
	java.util.AbstractCollection<E>
		java.util.AbstractList<E>
			java.util.Vector<E>
				java.util.Stack<E>
/*	
	Java 8 API Documentation
*/
Stack()

boolean 	empty()
E 			peek()
E 			pop()
E 			push(E item)
int 		search(Object o)


/*
	Implementation of Stack using resizable array
*/
import java.util.Iterator
public class ResizingArrayStack<Item> implements Iterable<Item>{
	// creating generic array is not acceptable in java, use cast
	private Item[] a = (Item[]) new Object[1];	
	// number of elements
	private int N = 0;

	public boolean isEmpty(){
		return N == 0;
	}

	public int size(){
		return N;
	}

	private void resize(int max){
		Item[] temp = (Item[]) new Object[max];
		for(int i = 0; i < N; i++){
			temp[i] = a[i];
		}
		a = temp;
	}

	public void push(Item item){
		// add item to the top of stack
		if(N == a.length) resize(2 * a.length);
		a[N++] = item;
	}

	public Item pop(){
		// pop element from top of Stack
		Item item = a[--N];

		// to avoid loitering
		a[N] = null;

		if(N > 0 && N == a.length / 4) resize(a.length / 2);
		return item;
	}

	public Iterator<Item> iterator(){
		return new ReserveArrayIterator();
	}

	private class ReserveArrayIterator implements Iterator<Item>{
		// to support FIFO iteration
		private i = N;
		
		public boolean hasNext(){
			return i > 0;
		}

		public Item next(){
			return a[--i];
		}

		public void remove(){

		}
	}
}


/*
	Implementation of Stack using linked list
*/
public Class Stack<Item> implements Iterable<Item>{
	// top of Stack
	private Node first;
	// number of elements
	private int N;
	private class Node{
		// inner class
		Item item;
		Node node;
	}

	public boolean isEmpty(){
		return first == null;
	}

	public int size(){
		return N;
	}

	public void push(Item item){
		// add item to top of Stack
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.node = oldfirst;
		N++;
	}

	public Item pop(){
		// delete item from top of Stack
		Item item = first.item;
		first = first.next;
		N--;
		return item;		
	}

	public Iterator<Item> iterator(){
		return new ListIterator();
	}

	private class ListIterator implements Iterator<Item>{
		private Node current = first;

		public boolean hasNext(){
			return current != null;
		}

		public void remove(){

		}

		public Item next(){
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
}




