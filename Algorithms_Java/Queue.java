package Algorithms_Java;

import java.util.Arrays;

public class Queue {
	int[] data;
	int size;
	int front;

	public Queue(int capacity) {
		this.data = new int[capacity];
		this.size = 0;
		this.front = 0;
	}

	public Queue() {
		this(5);
	}
	
	public Queue(int[] arr) {
		this.data=Arrays.copyOf(arr, arr.length);
		this.size = arr.length;
		this.front = 0;
	}

	public int size() {
		return this.size;
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public void enQueue(int value) throws Exception{
		if (this.size == this.data.length) {
			throw new Exception("Queue is full");
		}
		int tail = (front + size) % this.data.length;
		this.data[tail] = value;
		this.size++;
	}

	public int deQueue() throws Exception{
		if (isEmpty()) {
			throw new Exception("Queue is empty");
		}
		int delval = this.data[this.front];
		this.data[this.front] = 0;
		this.front = (this.front + 1) % this.data.length;
		this.size--;
		return delval;
	}

	public int front() throws Exception{
		if (isEmpty()) {
			throw new Exception("Queue is empty");
		}
		return this.data[front];
	}

	public void display() {
		for (int i = 0; i <this.size; i++) {
			int temp= (i + this.front) % this.data.length;
			System.out.print(this.data[temp] + "->");
		}
		System.out.println("Queue End");
		System.out.println("----------------------------");
	} 
}

