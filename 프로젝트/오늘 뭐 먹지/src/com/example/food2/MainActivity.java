package com.example.food2;

import java.util.Random;

import android.app.Activity;
import android.hardware.Camera.Size;
import android.os.Bundle;
import android.text.InputFilter.LengthFilter;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;

public class MainActivity extends Activity {

	String[][] foodname	= {
			{"��ȥ�κ� ������", "�����", "����������"}, // ��������
			{"ƴ�����"}, // �����
			{"��������", "�߹̰�", "�̼Ҿ�", "�谡��", "��������", "�̹н�", "�Ѽ�", "�丶�䵵�ö�", "�����������", "���������", "���õ��"}, // ���� 
			{"����", "û��", "�Ͽ���", "��¥���"}, // �߱���
			{"���Ĺ��� �Ĵ�", "ġ��ġ��", "���ġŲ", "�����ȴ�"}, // ġŲ 
			{"������â��", "���ѵ���", "���̵���"}, //�������
			{"����������", "���ڽ���"} // ������ 
		  };
	TextView textview;
	Random random;
	
	public void all(View v) {
		int count = 0;
		for(int i=0; i<foodname.length; i++) // foodname�� �� ���� 
			count += foodname[i].length;
		
		int food = random.nextInt(count);	// foodname ��ü���� �������� ���� �̰�
			
		int sum = 0;
		for(int i=0; i<foodname.length; i++) {
			if(food < sum+foodname[i].length) {
					textview.setText(foodname[i][food-sum]);		
					break;		
			}
			sum += foodname[i].length;	
		}
	}
	
	public void Dduckboki(View v) {
		int food_x= 0;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void ramen(View v) {
		int food_x= 1;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void rice(View v) {
		int food_x= 2;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void china(View v) {
		int food_x= 3;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void chicken(View v) {
		int food_x= 4;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void pork(View v) {
		int food_x= 5;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	public void pizza(View v) {
		int food_x= 6;
		int food_y= random.nextInt(foodname[food_x].length);
		
		textview.setText(foodname[food_x][food_y]);
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		textview = (TextView)findViewById(R.id.textview);
		random = new Random();
	}
}
