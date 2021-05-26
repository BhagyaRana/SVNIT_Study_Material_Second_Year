import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class maxAreaHistogram {

    public static void main(String[] args) {
        try {
            File output = new File("output.txt");
            output.createNewFile();
            FileWriter writer = new FileWriter(output);
            ArrayList<Integer> l = new ArrayList<>();
            long startTime, endTime, timeTaken;
            String file;
            int noOfFiles=10;
            int noOFTimes=10;
            for (int i = 1; i <= noOfFiles; i++) {
                file = String.format("File %d.txt", i);
                try {
                    loadFile(l, file);
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                }
                int[] heights = l.stream()
                .mapToInt(Integer::intValue)
                .toArray();
                int size = heights.length;
                int ans = 0;
                writer.write("File " + i + "\n");
                System.out.println("File " + i);

                // Iterative
                timeTaken = 0;
                startTime = System.nanoTime();
                for (int j = 0; j < noOFTimes; j++) {
                    ans = maxAreaIterative(heights);
                }
                endTime = System.nanoTime();
                timeTaken = (endTime - startTime)/noOFTimes;
                writer.write(ans + ", ");
                System.out.print(ans + ", ");
                writer.write(timeTaken + " ns, ");
                System.out.print(timeTaken + " ns, ");

                // Divide and conquer
                timeTaken = 0;
                startTime = System.nanoTime();
                for (int j = 0; j < noOFTimes; j++) {
                    ans = maxAreaDnC(heights, 0, size - 1);
                }
                endTime = System.nanoTime();
                timeTaken = (endTime - startTime)/noOFTimes;
                writer.write(ans + ", ");
                System.out.print(ans + ", ");
                writer.write(timeTaken + " ns\n");
                System.out.println(timeTaken + " ns");
                l.clear();
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void loadFile(ArrayList<Integer> A, String file) throws FileNotFoundException {
        Scanner s = new Scanner(new File(file));
        int temp;
        while (s.hasNext()) {
            temp = s.nextInt();
            A.add(temp);
        }
    }

    public static int maxAreaIterative(int[] heights) {
        int maxArea = 0;
        int minHeight = 0;
        for (int i = 0; i < heights.length; i++) { 
            maxArea = Math.max(heights[i], maxArea);
            minHeight = heights[i];
            for(int j = i - 1; j >= 0 ; j--) {
                minHeight = Math.min(heights[j], minHeight);
                int width = (i - j + 1);
                maxArea = Math.max(maxArea, (minHeight * width));
            }
        }
        return maxArea;
    }

    public static int maxAreaDnC(int[] heights, int left, int right) {
        if (left == right) {
            return heights[left];
        }
        if (left + 1 == right) {
            int minH = Math.min(heights[left], heights[right]);
            return Math.max(minH * 2, Math.max(heights[left], heights[right]));
        }
        int mid = (left + right) / 2;
        // left max area
        int leftArea = maxAreaDnC(heights, left, mid-1);
        // right max area
        int rightArea = maxAreaDnC(heights, mid+1, right);
        // mid max area, including current bar
        int i = mid, j = mid;
        int width, midArea = 0;
        int height = heights[mid];
        while (i >= left && j <= right) {
            width = j - i + 1;
            height = Math.min(height, Math.min(heights[i], heights[j]));
            midArea = Math.max(midArea, width * height);
            if (i == left) {
                j += 1;
            } else if (j == right) {
                i -= 1;
            } else if (heights[i-1] >= heights[j+1]) {
                i -= 1;
            } else {
                j += 1;
            }
        }
        return Math.max( midArea, Math.max(leftArea, rightArea) );
    }
}
