package com.example.java2struct;

public class JNIUtils {
	public static native void passJava2Native(Student persion);
	public static native Student getJavaFromNative();
	static {
		System.loadLibrary("java2struct");
	}
}
