/*
	Bag API Documentation
*/
Bag()

void 		add(Item item)
boolean 	isEmpty()
int 		size()


/*
	Implementation of bag using linked list
*/
import java.util.Iterator;

public class Bag<Item> implements Iterable<Item>{
	private Node first;		// first node in list
	int N;					// number of elements
	private class Node{
		Item item;
		Node next;
	}

	public int size(){
		return N;
	}

	public void add(Item item){
		// same as push() in Stack
		Node oldfirst = first;

		first = new Node();
		first.item = item;
		first.next = oldfirst;
		N++;
	}

	public Iterator<Item> iterator(){
		return new ListIterator():
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