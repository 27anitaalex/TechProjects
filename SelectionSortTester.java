// SelectionSortTester.java
// Anita Alex
// this is the tester class for selectionsort

public class SelectionSortTester
{
   public static void main(String[] args)
   {
      // Test with a given array
      int[] arr = {20, 35, 18, 41, 17, 2, 5, 21, 41, 6};
      SelectionSort obj1 = new SelectionSort(arr);
      System.out.println(obj1); // print original array
      obj1.selectionSort();     // sort and print each iteration

      System.out.println(); // spacing between tests

   
   }
}