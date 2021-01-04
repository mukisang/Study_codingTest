import java.util.Scanner;

public class galho {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String str="",tmp;
		str=sc.next();
		System.out.println(str);
		//String str="55-50+20-40+40-10",tmp;
		int check=0,result=0;
		boolean sign=true; //+는 true
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)=='+')
			{
				tmp=str.substring(check,i);
				if(sign==true)
				{
					result+=Integer.parseInt(tmp);
				}
				else
				{
					result-=Integer.parseInt(tmp);
				}
				check=i+1;
			}
			else if(str.charAt(i)=='-')
			{
				tmp=str.substring(check,i);
				if(sign==true)
				{
					result+=Integer.parseInt(tmp);
				}
				else
				{
					result-=Integer.parseInt(tmp);
				}
				check=i+1;
				sign=false;
			}
			else if(i==str.length()-1)
			{
				tmp=str.substring(check,i+1);
				
				if(sign==true)
				{
					result+=Integer.parseInt(tmp);
				}
				else
				{
					result-=Integer.parseInt(tmp);
				}
			}
			//숫자가 나온 경우는 단순히 반복문을 반복한다
			
		}
		System.out.println("결과는"+result);
		
	}

}
