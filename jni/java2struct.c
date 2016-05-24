#include <jni.h>
#include <stdio.h>
#include "com_example_java2struct_JNIUtils.h"

typedef struct {
	int ID;
	char name[255];
	char data[255];

} Student;

void printStudent(Student student) {
	LOGE("ID: %d", student.ID);
	LOGE("name: %s", student.name);
	LOGE("data: %s", student.data);
}

JNIEXPORT void JNICALL Java_com_example_java2struct_JNIUtils_passJava2Native(
		JNIEnv * env, jclass class, jobject object) {
	LOGE("call passJava2Native!");
	jclass jcRec = (*env)->FindClass(env, "com/example/java2struct/Student");
	jfieldID jfID = (*env)->GetFieldID(env, jcRec, "ID", "I");
	jfieldID jfname = (*env)->GetFieldID(env, jcRec, "name",
			"Ljava/lang/String;");
	jfieldID jfdata = (*env)->GetFieldID(env, jcRec, "data", "[B");
	int ID = (*env)->GetIntField(env, object, jfID);
	LOGE("ID: %d", ID);
	jstring name = (jstring)(*env)->GetObjectField(env, object, jfname);
	//convert jstring to char
	char* charname = (char*) (*env)->GetStringUTFChars(env, name, 0);
	LOGD("name: %s", charname);
	LOGE("name size : %d", strlen(charname));
	jbyteArray ja = (jbyteArray)(*env)->GetObjectField(env, object, jfdata);
	int nArrLen = (*env)->GetArrayLength(env, ja);
	char *chardata = (char*) (*env)->GetByteArrayElements(env, ja, 0);
	LOGW("data: %s", chardata);
	Student student;
	student.ID = ID;
	strcpy(student.name, charname);
	strcpy(student.data, chardata);
	printStudent(student);
}

JNIEXPORT jobject JNICALL Java_com_example_java2struct_JNIUtils_getJavaFromNative(
		JNIEnv * env, jclass class) {
	Student student;
	student.ID = 1234;
	char *charname = "Paul";
	char *chardata = "I am a student";
	strcpy(student.name, charname);
	strcpy(student.data, chardata);
	printStudent(student);

	LOGE("call getJavaFromNative!");
	jclass jcRec = (*env)->FindClass(env, "com/example/java2struct/Student");
	jfieldID jfID = (*env)->GetFieldID(env, jcRec, "ID", "I");
	jfieldID jfname = (*env)->GetFieldID(env, jcRec, "name",
			"Ljava/lang/String;");
	jfieldID jfdata = (*env)->GetFieldID(env, jcRec, "data", "[B");

	jobject joRec = (*env)->AllocObject(env, jcRec);

	(*env)->SetIntField(env, joRec, jfID, student.ID);

	//convert char to jstring
	jstring jstrn = (*env)->NewStringUTF(env, student.name);
	(*env)->SetObjectField(env, joRec, jfname, jstrn);

	//convert char to byte
	int length = strlen(student.data);
	jbyteArray jbarr = (*env)->NewByteArray(env, length);
	jbyte *jb = (*env)->GetByteArrayElements(env, jbarr, 0);
	memcpy(jb, student.data, length);
	(*env)->SetByteArrayRegion(env, jbarr, 0, length, jb);
	(*env)->SetObjectField(env, joRec, jfdata, jbarr);
	return joRec;
}

