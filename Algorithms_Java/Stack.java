package Algorithms_Java;
import java.util.Arrays;

public class Stack {

	int[] data;
	int tos = -1;

	public Stack(int capacity) {
		this.data = new int[capacity];
	}

	public Stack() {
		this(5);
	}

	public Stack(int[] arr) {	//this will add reverse elements in stack
		this.data=new int[arr.length];
		//this.data=Arrays.copyOf(arr, arr.length);
		this.tos=arr.length-1;
	}
	
	public int size() {
		return this.tos + 1;
	}

	public boolean isEmpty() {
		return this.size() == 0;
	}

	public void push(int value) throws Exception{
		if (this.tos == this.data.length - 1) {
			throw new Exception("Stack Is Full");
		}
		this.tos++;
		this.data[this.tos] = value;
	}

	public int pop() throws Exception{
		if (this.tos == -1) {
			throw new Exception("Stack Is Empty");
		}
		int deldata = this.data[this.tos];
		this.data[this.tos] = 0;
		this.tos--;
		return deldata;
	}

	public int top() throws Exception{
		if (isEmpty()) {
			throw new Exception("Stack Is Empty");
		}
		return this.data[this.tos];
	}

	public void display() {
		for (int i = this.tos; i >= 0; i--) {
			System.out.print(this.data[i] + "->");
		}
		System.out.println("End");
	}
}
