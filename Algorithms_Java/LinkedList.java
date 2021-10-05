package Algorithms_Java;

public class LinkedList {
    public class Node {
		int data;
		Node next;
	}

	private Node head;
	private Node tail;
	private int size;

	public LinkedList() {
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	private void handleOnlyAddition(int data) {
		Node newnode = new Node();
		newnode.data = data;
		newnode.next = null;
		this.head = this.tail = newnode;
		// this.tail = newnode;
		this.size++;
	}

	private int handleOnlyItemRemoval() {
		Node nodetoberemoved = this.head;
		this.head = this.tail = null;
		this.size--;
		return nodetoberemoved.data;
	}

	public void addFirst(int data) {
		if (this.size() == 0) {
			handleOnlyAddition(data);
			return;
		}

		Node newnode = new Node();
		newnode.data = data;
		newnode.next = this.head;
		this.head = newnode;
		this.size++;
	}

	public void AddAt(int index, int data) throws Exception {
		if (index < 0 || index > this.size()) {
			throw new Exception("Index out of bounds");
		} else if (index == 0) {
			this.addFirst(data);
		} else if (index == this.size()) {
			this.addLast(data);
		} else {
			Node node = new Node();
			node.data = data;
			Node prevnode = this.getNodeAt(index - 1);
			node.next = prevnode.next;
			prevnode.next = node;
			this.size++;
		}
	}

	public void addLast(int data) {
		if (this.size() == 0) {
			handleOnlyAddition(data);
		} else {
			Node newnode = new Node();
			newnode.data = data;
			newnode.next = null;
			this.tail.next = newnode;
			this.tail = newnode;
			this.size++;
		}
	}

	public int getFirst() throws Exception {
		if (this.size() == 0) {
			throw new Exception("Linked list is empty.");
		}
		return this.head.data;
	}

	public int getValueAt(int index) throws Exception {
		if (index < 0 || index >= this.size()) {
			throw new Exception("Index out of bounds.");
		}
		Node node = this.head;
		for (int i = 0; i < index; i++) {
			node = node.next;
		}
		return node.data;
	}

	public Node getNodeAt(int index) throws Exception {
		if (index < 0 || index >= this.size()) {
			throw new Exception("Index out of bounds.");
		}
		Node node = this.head;
		for (int i = 0; i < index; i++) {
			node = node.next;
		}
		return node;
	}

	public int getLast() throws Exception {
		if (this.size() == 0) {
			throw new Exception("Linked list is empty.");
		}
		return this.tail.data;
	}

	public int removeFirst() throws Exception {
		if (this.size() == 0) {
			throw new Exception("Linked list is empty.");
		}
		if (this.size() == 1) {
			int rv = handleOnlyItemRemoval();
			return rv;
		}
		Node nodetoberemoved = this.head;
		this.head = nodetoberemoved.next;
		this.size--;
		return nodetoberemoved.data;
	}

	public int removeAt(int index) throws Exception {
		if (index < 0 || index >= this.size()) {
			throw new Exception("Index out of bounds");
		} else if (index == 0) {
			return this.removeFirst();
		} else if (index == this.size() - 1) {
			return this.removeLast();
		} else {
			Node prevnode = this.getNodeAt(index - 1);
			Node nextnode = prevnode.next;
			prevnode.next = nextnode.next;
			this.size--;
			return prevnode.data;
		}
	}

	public int removeLast() throws Exception {
		if (this.size() == 0) {
			throw new Exception("Linked list is empty.");
		}
		if (this.size() == 1) {
			int rv = handleOnlyItemRemoval();
			return rv;
		}
		Node nodetoberemoved = this.tail;
		Node prevnode = this.getNodeAt(this.size() - 2);
		prevnode.next = null;
		this.size--;
		return nodetoberemoved.data;
	}

	public int size() {
		return this.size;
	}

	public boolean isEmpty() {
		return this.size() == 0;
	}

	public void display() {
		for (Node node = this.head; node != null; node = node.next) {
			System.out.print(node.data + "->");
		}
		System.out.println(".");
	}

	public void displayReverse() {
		this.displayReverseHelper(this.head);
	}

	private void displayReverseHelper(Node node) {
		if (node.next == null) {
			System.out.println(node.data);
			return;
		}
		displayReverseHelper(node.next);
		System.out.println(node.data);
	}

	public void reverseDataIterative() throws Exception {
		Node left = this.head;
		Node right = this.tail;
		int li = 0;
		int ri = this.size() - 1;
		while (li <= ri) {
			int temp = left.data;
			left.data = right.data;
			right.data = temp;
			left = left.next;
			right = this.getNodeAt(ri - 1);
			li++;
			ri--;
		}
	}

	public void reversePointerIterative() {
		Node prevnode = this.head;
		Node currnode = prevnode.next;
		while (currnode != null) {
			Node tempnext = currnode.next;
			currnode.next = prevnode;
			prevnode = currnode;
			currnode = tempnext;
		}
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;
		this.tail.next = null;
	}

	public void reversePointerRecursive() {
		rprHelper(this.head);
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;
		this.tail.next = null;
	}

	private void rprHelper(Node node) {
		if (node.next == null) {
			return;
		}
		rprHelper(node.next);
		node.next.next = node;
	}

	public class HeapMover {
		Node node;
	}

	public void reverseDataRecursive() {
		HeapMover left = new HeapMover();
		left.node = this.head;
		Node right = this.head;
		rdrHelper(left, right, 0);
	}

	private void rdrHelper(HeapMover left, Node right, int floor) {
		if (right == null) {
			return;
		}
		rdrHelper(left, right.next, floor + 1);
		if (floor >= this.size() / 2) {
			int temp = left.node.data;
			left.node.data = right.data;
			right.data = temp;
		}
		left.node = left.node.next;
	}

	public void fold() {
		HeapMover left = new HeapMover();
		left.node = this.head;
		Node right = this.head;
		foldHelper(left, right, 0);
	}

	private void foldHelper(HeapMover left,Node right,int floor) {
		foldHelper(left, right.next, floor + 1);
		if (floor >= this.size() / 2) {
			Node temp = left.node.next;
			left.node.next = right;
			right.next = temp;
		}
		if(floor==this.size()/2) {
			this.tail=right;
			this.tail.next=null;
		}
		left.node=left.node.next.next;
	}
}
