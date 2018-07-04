package day03;

import java.util.Scanner;

public class hh {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("원화를 입력하시오");
		final double RATE = 1180.7;
		double won = scanner.nextInt();
		double dollar = 0.0;
		dollar = won / RATE;
		System.out.printf("%f", dollar);
        
	}
}