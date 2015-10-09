
public class taxCompute {
	
	
	// main ()
	public static void main(String []agrs){
		taxCompute tc = new taxCompute();
		System.out.println(tc.computer(99999));
	}
	

	
	public int Three(int x){              //0-3000
		if (x<5) return 0;
		else if(x<15) return 1;
		else if(x<25) return 2;
		else{
			int a=x/1000;
			int b=(x-a*1000)/100;
			int c=x%100;
			int d;
			int e=a*100+b*10;
			switch(d=c/25){
			case 1:
				return e+4;
			case 2:
				return e+6;
			case 3:
				return e+9;
			case 0:
				return e+1;
			}
		}
		
		return 0;
	}
	
	public int ThreetoNineOne(int x){    //3000-9100
		int a=x/1000;
		int b=(x-a*1000)/100;
		int e=a*100+b*10;
		int c=x%100;
		if(c>=50){
			return e+8;
		}
		else
		{
			return e+3;
		}
		
	}
	
	
	public int NineOnetoThirtySixNine(int x){              //9100-36900
		
		int a=(x-9100)/50;
		
		return a/2*15+a%2*8+915;
	}
	
	
	
	
	public int ThirtySixNinetoEightyNineThirtyFive(int x){                    //36900-89350
		
		int a=(x-36900)/50;
		return a/2*25+a%2*12+5088;
	}
	
	public int EightyNineThirtyFiveto(int x){                     //   89350-100000
		int a=x-89350;
		
		return a/50*14+18201;
	}
	
	
	public int HundredThousand(int x){
		double b;
		double c;
		if(x<186350) {b=0.28;c=6824.25;}
		else if(x<405100) {b=0.33;c=16141.75;}
		else if(x<406750) {b=0.35;c=24243.75;}
		else {
			b=0.396;
			c=42954.25;
		}
		
		double a=x*b-c;
		
		return (int)a;
		
	}
	
	
	public int computer(int x){
		taxCompute tc = new taxCompute();
		if(x<3000) return tc.Three(x);
		else if(x<9100) return tc.ThreetoNineOne(x);
		else if(x<36900) return tc.NineOnetoThirtySixNine(x);
		else if(x<89350) return tc.ThirtySixNinetoEightyNineThirtyFive(x);
		else if(x<100000) return tc.EightyNineThirtyFiveto(x);
		else return tc.HundredThousand(x);
		
	}
	
	
}
