/*
 * author  : [Phan Shi Yu]
 * matric no. : [A0091024U]
 */

import java.util.*;

class Measurement
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    
    Person[] group = new Person[100];
    
    int N = sc.nextInt();
    
    Person tallest = new Person("",0,0);
    
    Person shortest = new Person("",10000,0);
    
    int i; //Loop counter//
    
    for (i=0 ; i<N ; ++i)
    {
      group[i] = new Person(sc.next(),sc.nextInt(),sc.nextInt());
      
      if(group[i].height>tallest.height)
        tallest = group[i];
      if(group[i].height<shortest.height)
        shortest = group[i];
    }
    
    System.out.printf("%s is the shortest with BMI equals to %.2f.\n", shortest.name, shortest.computeBMI());
    System.out.printf("%s is the tallest with BMI equals to %.2f.\n", tallest.name, tallest.computeBMI());
    
  }
}

class Person
{
  String name;
  double height=0;
  int weight=0;
  
  public Person(String name, int height, int weight)
  {
    this.name = name;
    this.height = (double)height/100;
    this.weight = weight;
  }
  
  public double computeBMI()
  {
    return (weight/(height*height));
  }
}



      
      