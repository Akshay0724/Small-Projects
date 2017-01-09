import java.io.*;
import java.util.*;
import java.net.*;
public class sk_thread
{
    public static void main(String args[])
    {
    	String msg;
    	sk_thread obj=new  sk_thread();
    	
        try
        {
           ServerSocket server= new ServerSocket(1234);
           
           final Scanner sc=new Scanner(System.in);
           while(true)
           {
        	   Socket socket= server.accept();
               System.out.println("Server ready for service");
               if(socket==null)
            	   break;
               BufferedReader br= new BufferedReader(new InputStreamReader(socket.getInputStream()) );
               final PrintStream out= new PrintStream(socket.getOutputStream());
        	   
                  runnable run=new runnable(br,out);
                  Thread t=new Thread(run);
                  t.start();
          }
          System.out.println("connection closing....");
          Thread.sleep(3000);
          
          server.close();
          System.out.println("connection closed");
      } 
      catch(Exception ex) 
      {
           System.out.println(ex);
      }
  }




}







