// SelectionSort.java
// Anita Alex
// 2/23/26

/* Goes through the array and checks which of the numbers is 
the smallest and then switches it with the first. Then it 
goes through the rest of the array and checks if the 
next number is smallest and then switches it with 
the second position. It continues until the array 
is in increasing order. 
*/

import java.util.Random;

public class SelectionSort
{
   private int length, max;
   private int[] originalArr;
   private int[] sortedArr;

   public SelectionSort(int[] arr)
   {
      length = arr.length; // length of given array
      originalArr = new int[length]; // length should be same as orginal array
      sortedArr = new int[length]; // length should be same as each sorted array

      // copy values into both arrays
      for (int i = 0; i < length; i++)
      {
         originalArr[i] = arr[i];
         sortedArr[i] = arr[i];
      }
   }

   public void selectionSort()
   {
      // prints original array first
      System.out.println(this);

      // checks each position in the array
      for (int i = 0; i < sortedArr.length - 1; i++)
      {
         int minIndex = i; // assumes current position is smallest

         // checks which position has the smallest number
         for (int j = i + 1; j < sortedArr.length; j++)
         {
            if (sortedArr[j] < sortedArr[minIndex])
            {
               minIndex = j; // update index of smallest value
            }
         }

         // swaps smallest value with current position
         int temp = sortedArr[i];
         sortedArr[i] = sortedArr[minIndex];
         sortedArr[minIndex] = temp;

         // prints array after each iteration
         System.out.println(this);
      }
   }

   // prints out array after sorted from least to greatest
   public String toString()
   {
      String result = "";

      for (int i = 0; i < sortedArr.length; i++)
      {
         result += sortedArr[i];

         if (i < sortedArr.length - 1)
            result += ", ";
      }

      return result;
   }
}