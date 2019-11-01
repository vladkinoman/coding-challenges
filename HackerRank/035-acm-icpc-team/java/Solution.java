import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the acmTeam function below.
    static int[] acmTeam(String[] topic) {
        int n = topic.length;
        if (n < 2 || n > 500)
            throw new IllegalArgumentException();
        int m = topic[0].length();
        if (n < 1 || n > 500)
            throw new IllegalArgumentException();
        
        // Combinatorics: p!/2.
        int nOfWaysToFormTeam = n * (n - 1) / 2;
        String[] team = new String [nOfWaysToFormTeam];
        int maxNumberOfTopics = 0;
        int nOfTeamsThatKnowMaxTopics = 0;
        
        int i = 0; // first attendee
        int j = 0; // second attendee
        for (int k = 0; k < nOfWaysToFormTeam; k++, j++) {    
            // We don't need the same members on the new teams.
            if (i == j && j != n) {
                j++;
            } else if (j == n) {
                i++;
                j = i + 1;
            }

            // Apply the Disjunction operation to form a new team.
            StringBuilder sb = new StringBuilder();
            for (int p = 0; p < m; p++) {
                sb.append((char)(topic[i].charAt(p) 
                | topic[j].charAt(p)));
            }
            team[k] = sb.toString();
            
            // Analyze the knowledge of the k-th team.
            int nOfKnownTopics = 0;
            for (int q = 0; q < m; q++) {
                if (team[k].charAt(q) == '1') {
                    nOfKnownTopics++;
                }
            }

            // Trying to find the maximum number of topics 
            // and teams that know them.
            if (nOfKnownTopics > maxNumberOfTopics) {
                maxNumberOfTopics = nOfKnownTopics;
                nOfTeamsThatKnowMaxTopics = 1;
            } else if (nOfKnownTopics == maxNumberOfTopics) {
                nOfTeamsThatKnowMaxTopics++;
            }
        }

        return new int [] {maxNumberOfTopics,
            nOfTeamsThatKnowMaxTopics};
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        String[] topic = new String[n];

        for (int i = 0; i < n; i++) {
            String topicItem = scanner.nextLine();
            topic[i] = topicItem;
        }

        int[] result = acmTeam(topic);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
