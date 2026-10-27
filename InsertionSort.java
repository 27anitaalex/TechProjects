// InsertionSort.java
// Anita Alex
// 2/12/26

public class InsertionSort
{
   // data fields (instance variables)
   private int length, max;
   private int[] originalArr;
   private int[] sortedArr;

   // constructor: uses given array
   public InsertionSort(int[] arr)
   {
      //gets length from the given array and assigns it to the original and sorted array
      length = arr.length; 
      originalArr = new int[length];
      sortedArr = new int[length];
      
      // copies all values from given array into both new arrays
      for (int i = 0; i < length; i++)
      {
         originalArr[i] = arr[i];
         sortedArr[i] = arr[i];
      }
   }
   
   //sorts the array from small to large
   public void insertionSort()
   {  
      
      // goes to each index in the sorted array
      for (int i = 1; i < sortedArr.length; i++)
      {
         int index = sortedArr[i]; // the value in each index of the array
         int j = i - 1; // index number of the one before i
         
         // checks if that first index(j) is smaller or larger than the one after it(i)
         while (j >= 0 && sortedArr[j] > index)
         {
            sortedArr[j + 1] = sortedArr[j]; // moves it if it is larger
            j--;
         }
         
         sortedArr[j + 1] = index;  
         
         // calls the sortedArr to be printed after each iteration
         System.out.println(this);
      }
   }
   
   //prints sortedArr in format
   public String toString()
   {
      String result = "";
      
      // after each integer, places a , and space
      for (int i = 0; i < sortedArr.length; i++)
      {
         result += sortedArr[i];
         
         if (i < sortedArr.length - 1)
            result += ", ";
      }
      
      return result;
   }
}