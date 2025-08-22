import java.io.*;
import java.util.*;

class Result {

    public static String balancedSums(List<Integer> arr) {
        long totalSum = 0;
        for (int val : arr) {
            totalSum += val;
        }

        long leftSum = 0;
        for (int val : arr) {
            long rightSum = totalSum - leftSum - val;
            if (leftSum == rightSum) {
                return "YES";
            }
            leftSum += val;
        }
        return "NO";
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(bufferedReader.readLine().trim());

        for (int t = 0; t < T; t++) {
            int n = Integer.parseInt(bufferedReader.readLine().trim());
            String[] arrTemp = bufferedReader.readLine().trim().split(" ");

            List<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                arr.add(Integer.parseInt(arrTemp[i]));
            }

            String result = Result.balancedSums(arr);
            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
