import java.util.*;
import java.io.*;

public class Main {

    static int BessieNumMoves, ElsieNumMoves, count;
    static char Direction;
    static ArrayList<Integer> BessieMoves, ElsieMoves;
    public static void getInput() throws IOException {
        File inputFile = new File("greetings.in");
        Scanner sc = new Scanner(inputFile);
        BessieNumMoves = sc.nextInt();
        ElsieNumMoves = sc.nextInt();
        BessieMoves = new ArrayList<Integer>();
        ElsieMoves = new ArrayList<Integer>();
        for (int i=0; i<BessieNumMoves; i++) {
            int steps = sc.nextInt();
            Direction = sc.next().charAt(0);
            if (Direction == 'L') {
                for (int j=0; j<steps; j++) {
                    BessieMoves.add(-1);
                }
            } else { // R
                for (int j = 0; j < steps; j++) {
                    BessieMoves.add(1);
                }
            }
        }
        for (int i=0; i<ElsieNumMoves; i++) {
            int steps = sc.nextInt();
            Direction = sc.next().charAt(0);
            if (Direction == 'L') {
                for (int j = 0; j < steps; j++) {
                    ElsieMoves.add(-1);
                }
            } else { // R
                for (int j = 0; j < steps; j++) {
                    ElsieMoves.add(1);
                }
            }
        }
    }
    public static int getMax(int i, int j) {
        if ( i < j ) {
            return j;
        } else {
            return i;
        }
    }
    public static void runSimulation() {
        int BessiePos = 0, ElsiePos = 0;
        boolean together = true;
        int maxSteps = getMax(BessieMoves.size(), ElsieMoves.size());

        count = 0;
        for (int i=0; i<maxSteps; i++) {
            if (i < BessieMoves.size()) {
                BessiePos += BessieMoves.get(i);
            }
            if (i< ElsieMoves.size()) {
                ElsiePos += ElsieMoves.get(i);
            }
            if (together) {
                if (BessiePos != ElsiePos) {
                    together = false;
                }
            } else {
                if (BessiePos == ElsiePos) {
                    together = true;
                    count++;
                }
            }
        }
    }

    public static void putOutput() throws IOException {
        FileWriter fileWriter = new FileWriter("greetings.out");
        PrintWriter printWriter = new PrintWriter(fileWriter);
        printWriter.printf("%d\n", count);
        printWriter.close();
    }
    public static void main(String[] args) throws IOException {
        getInput();
        runSimulation();
        putOutput();
    }
}