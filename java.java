package com.bimbel.month5.week2;
import java.util.Scanner;
public class testbungatahunan {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//syariaaaaaah
		double amount, rate, fiv;
		int years;
		
		Scanner scanDouble = new Scanner(System.in);
		Scanner scanYears = new Scanner(System.in);
		System.out.print("Enter amount: ");
		amount = scanDouble.nextDouble();
		System.out.print("Enter rate: ");
		rate = scanDouble.nextDouble();
		System.out.print("Enter years: ");
		years = scanYears.nextInt();
		System.out.println("===================================================");
		System.out.println("Tahun		FIV		    Konvensional");
		System.out.println("===================================================");
		double cnv = amount;
		
		for (int thn = 1; thn <= years; thn++) {
		
			fiv = bungatahunan.futureInvestmentValue(cnv, rate, thn);
			cnv = fiv;
			System.out.println(thn + "	" + fiv + "	" + cnv);
	    
		}
		
		
		//fiv = bungatahunan.futureInvestmentValue(amount, rate, years);
		//System.out.print("Future Investmen Value: " + fiv);
		
		

	}

}
