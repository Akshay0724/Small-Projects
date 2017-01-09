import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class runnable implements Runnable{
	String msg;
	PrintStream out;
	BufferedReader br;
	int A[];
	List<int[]> B = new ArrayList<int[]>();
	public runnable(BufferedReader br,PrintStream out){
		this.br=br;
		this.out=out;
	}
	
	public void run(){
		String msg = null;
			try {
				msg = br.readLine();
				System.out.println(msg.split(","));
				String[] str=msg.split(",");
				A=new int[str.length];
				int i=0;
				for(String s:str){
					A[i++]=Integer.parseInt(s);
				}
				msg = br.readLine();
				str=msg.split(" ");
				i=0;
				for(String s:str){
					String[] str1=s.split(",");
					int j=0;
					int[] temp=new int[str1.length];
					for(String s1:str1){
					  	temp[j++]=Integer.parseInt(s1);
					}
					B.add(temp);
					i++;
				}
				System.out.println(msg);
				
				if(A.length!=B.size()){
					out.println("cannot be multiplied");
					return;
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			  String reply = "";
			  for(int i=0;i<B.get(0).length;i++){
				  int temp=0;
				  for(int j=0;j<A.length;j++){
					  temp+=A[j]*B.get(j)[i];
				  }
				  reply+=String.valueOf(temp);
				  reply+=" ";
				  
			  }
              out.println(reply) ;
              System.out.println("Response successfully send......");
       
}}