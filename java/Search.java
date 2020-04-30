import java.util.Arrays;
import java.util.concurrent.*;

public class Search {
	
	public static void main(String[] args)
	{
		// All of the arrays
		
		System.out.println("Array Size: 3,000,000. Time spent on search: " + makeArray(3000000, 500));
		System.out.println("Array Size: 15,000,000. Time spent on search: " + makeArray(15000000, 500));
		System.out.println("Array Size: 7,500,000. Time spent on search: " + makeArray(7500000, 500));
		System.out.println("Array Size: 3,750,000. Time spent on search: " + makeArray(3750000, 500));
		System.out.println("Array Size: 1,875,000. Time spent on search: " + makeArray(1875000, 500));
		
	}
	
	public static long makeArray(int arraySize, int searchFor)
	{
		// Set up returned variable
		long time = 0;
		
		// make the array
		int[] bigArray = new int[arraySize];
		for(int i = 0; i < arraySize; ++i)
			bigArray[i] = i;
		
		// set up time
		
		long start = System.nanoTime();
		
		int getIndex = Arrays.binarySearch(bigArray, searchFor);
		
		long end = System.nanoTime();
		
		time = end - start;
		
		return time;
	}

}
