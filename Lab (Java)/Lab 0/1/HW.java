import java.util.*;
import java.lang.String;

class HelloWorld
{
  public static boolean intToBool (int a)
  {
    return (a != 0);
  }
  
  public static int operation (String op, int c, int d)
  {
    
    boolean a = intToBool(c);
    boolean b = intToBool(d);
    
    if (op.equals("AND"))
    {
      if(a && b)
        return 1;
      else 
        return 0;
    }
    
    if (op.equals("OR"))
    {
      if (a || b)
        return 1;
      else
        return 0;
    }
    
    return 1000;
  }
  
  public static void printResults (int[] results, int n)
  {
    int i;
    for (i=0 ; i<n ; ++i)
    System.out.println(results[i]);
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int[] results  = new int[99];
    int i = 0; //Loop counter//
    
    switch (sc.nextInt()) //Takes in value to determine type//
    {
      case 1:
      {
        int n = sc.nextInt(); //Takes in value for number of inputs//
        
        for ( i=0 ; i < n ; i++)
          results[i] = operation(sc.next(), sc.nextInt(), sc.nextInt());
          
        printResults (results, n);
      }
      break;
      
      case 2:
      {
        while (true)
        {
          if (sc.hasNextInt())
          {
              break;
          }
          
          results[i] = operation(sc.next(), sc.nextInt(), sc.nextInt());
          
          ++i;
        }
        printResults (results, i);
      }
      break;
      
      case 3:
      {
        do
        {
          results[i] = operation(sc.next(), sc.nextInt(), sc.nextInt());
          sc.next();
          ++i;
          System.out.println("HAHA");
        }
        while (sc.hasNextLine());
        printResults (results, i);
      }
      
      break;
    }
  }
}
  
          
          
        
          
          
        
            
          
        
    
    
    
    