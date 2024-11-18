package lab8;
import java.util.Scanner;

public class BankersAlgorithm {
  private int n; // number of processes
  private int m; // number of resources
  private int[][] allocation; // Allocation matrix
  private int[][] max; // Maximum demand matrix
  private int[][] need; // Need matrix
  private int[] available; // Available resources
  private boolean[] finish; // To check if a process is finished or not
  // Function to check if the system is in a safe state

  private boolean isSafe() {
    int[] work = new int[m];
    System.arraycopy(available, 0, work, 0, m);
    int[] safeSequence = new int[n];
    int count = 0;
    while (count < n) {
      boolean found = false;
      for (int i = 0; i < n; i++) {
        if (!finish[i]) {
          int j;
          for (j = 0; j < m; j++) {
            if (need[i][j] > work[j])
              break;
          }
          if (j == m) { // If all needs can be satisfied
            for (int k = 0; k < m; k++) {
              work[k] += allocation[i][k];
            }
            safeSequence[count++] = i;
            finish[i] = true;
            found = true;
          }
        }
      }
      if (!found) {
        return false; // If no process can proceed, the system is not in a safe state
      }
    }
    // Print the safe sequence
    System.out.println("System is in a safe state.");
    System.out.print("Safe sequence: ");
    for (int i = 0; i < n; i++) {
      System.out.print(safeSequence[i] + " ");
    }
    System.out.println();
    return true;
  }

  // Function to input the data
  public void input() {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the number of processes: ");
    n = sc.nextInt();
    System.out.print("Enter the number of resource types: ");
    m = sc.nextInt();
    allocation = new int[n][m];
    max = new int[n][m];
    need = new int[n][m];
    available = new int[m];
    finish = new boolean[n];
    System.out.println("Enter the allocation matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        allocation[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the maximum matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        max[i][j] = sc.nextInt();
      }
    }
    System.out.println("Enter the available resources:");
    for (int i = 0; i < m; i++) {
      available[i] = sc.nextInt();
    }
    // Calculate the need matrix
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        need[i][j] = max[i][j] - allocation[i][j];
      }
    }
  }

  public static void main(String[] args) {
    BankersAlgorithm bankersAlgorithm = new BankersAlgorithm();
    bankersAlgorithm.input();
    if (!bankersAlgorithm.isSafe()) {
      System.out.println("System is not in a safe state.");
    }
  }
}
