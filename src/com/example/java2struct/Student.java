package com.example.java2struct;

public class Student {
	public int ID;
	public String name;
	public byte[] data;

	public int getID() {
		return ID;
	}

	public void setID(int iD) {
		ID = iD;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public byte[] getData() {
		return data;
	}

	public void setData(byte[] data) {
		this.data = data;
	}

	public Student(int iD, String name, byte[] data) {
		super();
		ID = iD;
		this.name = name;
		this.data = data;
	}

	public Student() {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Student " + "ID: " + this.ID + ";name: " + this.name
				+ ";data: " + new String(data);
	}

}
