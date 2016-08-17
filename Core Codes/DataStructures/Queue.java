Interface Queue<E>
java.util

/*
	API Documentation
*/
All Known Implementing Classes:
    AbstractQueue, ArrayBlockingQueue, ArrayDeque, ConcurrentLinkedDeque, ConcurrentLinkedQueue, DelayQueue, 
    LinkedBlockingDeque, LinkedBlockingQueue, LinkedList, LinkedTransferQueue, PriorityBlockingQueue, 
    PriorityQueue, SynchronousQueue

boolean		add(E e): Thorws an IllegalStateException if no space is current available
E 			element(): Retrieves, but does not remove, the head of this queue, throws exception if can not
boolean		offer(E e): Insert the specified element if it is possible without violating capacity restrictions
E 			peek(): Retrieves, but does not remove the head, returns null if empty
E 			poll(): Retrieves and removes the head, returns null if empty
E 			remove(): Retrieves and removes head


/*
	Implementation of Queue
*/
import java.util.Iterator;

public class Queue<Item> implements Iterable<Item>{
	private Node first;
	private Node last;
	private int N;
	private class Node{
		Item item;
		Node next;
	}

	public boolean isEmpty(){
		return first == null;
	}

	public void enqueue(Item item){
		// Add itme to the end of the list
		Node oldlast = last;

		last = new Node();
		last.item = item;
		last.next = null;

		if(isEmpty()) first = last;
		else oldlast.next = last;
		N++;
	}

	public Item dequeue(){
		// Remove item from the beginning of the the list
		Item item = first.item;
		first = first.next;
		N--;
		if(isEmpty()) last = null;	
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