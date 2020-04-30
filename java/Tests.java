import java.util.Arrays;
import java.util.concurrent.*;

public class Tests {
	
	// Global length
	static int len = 29997529;
	
	public static void main(String[] args)
	{
		// Find out averages
		
		// --- 1 Dimension Arrays ----
		
		long average = 0;
		
		for(int i = 0; i < 10; ++i)
			average += single();
		
		average /= 10.0;
		
		System.out.println("Average time for 1d Arrays: " + average + " nanoseconds.");
		
		// --- 2 Dimension Arrays ----
		average = 0;
		
		for(int j = 0; j < 10; ++j)
			average += mult();
		
		average /= 10.0;
		
		System.out.println("Average time for 2D Arrays: " + average + " nanoseconds.");
	}
	
	public static long single()
	{
		// Time variables
		long mult;
		long ope;		
				 
		// ----- ADDING -----
				 
		// make two arrays
		int[] arra1 = new int[len];
		Arrays.fill(arra1, 5);
				 
		int[] arra2 = new int[len];
		Arrays.fill(arra2, 2);
				 
		// make result array
		int[] res = new int[len];
				 
		// Find out how much time it takes
		long start = System.nanoTime();
		for(int i = 0; i < len; i++)
		{
			res[i] = arra1[i] + arra2[i];
		}
				 
		long end = System.nanoTime();
				 
		mult = (end - start);
				 
		return mult;
	}
	
	public static long mult()
	{
		// Time variables
		long mult;
		long ope;
				
		// ---- MULT ----
		int[][] twoArra1 = new int[5477][5477];
		for(int[] row: twoArra1)
		 Arrays.fill(row, 5);
				 
		int[][] twoArra2 = new int[5477][5477];
		for(int[] row: twoArra2)
		Arrays.fill(row, 2);
				 
		int[][] resArra = new int[5477][5477];
				 
		long start = System.nanoTime();
				 
		for(int j = 0; j < 5477; j++)
			 for(int k = 0; k < 5477; k++)
				resArra[j][k] = twoArra1[j][k] + twoArra2[j][k];
				 
		long end = System.nanoTime();
				 
		mult = end - start;		
		
		return mult;
	}

}
