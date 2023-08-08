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
			{"신혼부부 떡볶이", "레드썬", "신전떡볶이"}, // 떡볶이집
			{"틈새라면"}, // 라면집
			{"국수나무", "야미가", "미소야", "김가네", "수육국밥", "미밀스", "한솥", "토마토도시락", "봉구스밥버거", "쉐프밥버거", "김밥천국"}, // 밥집 
			{"리강", "청궁", "하오츠", "손짜장면"}, // 중국집
			{"미쳐버린 파닭", "치르치르", "썬더치킨", "엽기팔닭"}, // 치킨 
			{"도야지창고", "착한돼지", "돈이돈이"}, //돼지고기
			{"오구쌀피자", "피자스쿨"} // 피자집 
		  };
	TextView textview;
	Random random;
	
	public void all(View v) {
		int count = 0;
		for(int i=0; i<foodname.length; i++) // foodname의 총 갯수 
			count += foodname[i].length;
		
		int food = random.nextInt(count);	// foodname 전체에서 랜덤으로 숫자 뽑고
			
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
