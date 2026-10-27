// InsertionSortTester.java
// Anita Alex
// 2/12/26

public class InsertionSortTester
{
   public static void main(String[] args)
   {
      int[] arr = {34, 15, 47, 9, 17, 26, 30, 5, 33, 15};
      InsertionSort video = new InsertionSort(arr);
      System.out.println(video); // we want to see what the array is
      video.insertionSort(); // do the sorting and print to screen each iteration
   }
}
/*
output:

34, 15, 47, 9, 17, 26, 30, 5, 33, 15
15, 34, 47, 9, 17, 26, 30, 5, 33, 15
15, 34, 47, 9, 17, 26, 30, 5, 33, 15
9, 15, 34, 47, 17, 26, 30, 5, 33, 15
9, 15, 17, 34, 47, 26, 30, 5, 33, 15
9, 15, 17, 26, 34, 47, 30, 5, 33, 15
9, 15, 17, 26, 30, 34, 47, 5, 33, 15
9, 15, 17, 26, 30, 34, 47, 5, 33, 15
5, 9, 15, 17, 26, 30, 34, 47, 33, 15
5, 9, 15, 17, 26, 30, 33, 34, 47, 15
5, 9, 15, 15, 17, 26, 30, 33, 34, 47
*/