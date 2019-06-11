
import java.io.*;
import java.util.*;

class Test {

    int n, m, steg;
    char[][] tabell = new char[24][52];
    char[][] lovlig = new char[24][52];
    char[][] neste = new char[24][52];

    public static void main(String[] args) {
        Test myWork = new Test();
        myWork.begin();
    }

    void begin() {
        String s;
        StringTokenizer st;
        int i, j;

        s = Test.readLn(255);
        st = new StringTokenizer(s);
        // Number of scenarios
        int num = Integer.parseInt(st.nextToken());
        // System.out.println("Antall kjoeringer "+num);
        for (int runs = 0; runs < num; runs++) {
            // Les inn data
            s = Test.readLn(255);
            st = new StringTokenizer(s);
            int max_moves = Integer.parseInt(st.nextToken());
            // System.out.println("max moves "+max_moves);
            s = Test.readLn(255);
            st = new StringTokenizer(s);
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            // System.out.println("n="+n+" m="+m);
            s = Test.readLn(255);
            int slutt = s.indexOf('G');
            for (i = 2; i < n + 2; i++) {
                s = Test.readLn(255);
                for (j = 1; j <= m; j++) {
                    tabell[i][j] = s.charAt(j - 1);
                    lovlig[i][j] = '.';
                    neste[i][j] = '.';
                }
            }
            for (j = 1; j <= m; j++) {
                tabell[1][j] = 'O';
                tabell[n + 2][j] = 'O';
                lovlig[1][j] = '.';
                lovlig[n + 2][j] = '.';
                neste[1][j] = '.';
                neste[n + 2][j] = '.';
            }
            s = Test.readLn(255);
            int start = s.indexOf('F');
	    System.out.println("start="+start+" slutt="+slutt);
            lovlig[n + 2][start + 1] = '@';
            steg = 0;
            skriv_bane();

            // Kjoer algoritme
            for (steg = 1; steg <= max_moves; steg++) {
                // Oppdater veiene
                for (i = 0; i < n; i++) {
                    if ((i % 2) == 0) { // gaar mot hoeyre
                        for (j = m; j >= 1; j--) {
                            tabell[n - i + 1][j + 1] = tabell[n - i + 1][j];
                        }
                        tabell[n - i + 1][1] = tabell[n - i + 1][m + 1];
                    } else {  // gaar mot venstre
                        for (j = 1; j <= m; j++) {
                            tabell[n - i + 1][j - 1] = tabell[n - i + 1][j];
                        }
                        tabell[n - i + 1][m] = tabell[n - i + 1][0];
                    } // else
                } // for antall veier
                // Oppdater hvor vi kan gaa
                for (i = 1; i < n + 3; i++) {
                    for (j = 1; j <= m; j++) {
                        if (lovlig[i][j] == '@') {
                            if (tabell[i][j] == 'O') {
                                neste[i][j] = '@';
                            }
                            if (tabell[i - 1][j] == 'O') {
                                neste[i - 1][j] = '@';
                            }
                            if (tabell[i + 1][j] == 'O') {
                                neste[i + 1][j] = '@';
                            }
                            if (tabell[i][j + 1] == 'O') {
                                neste[i][j + 1] = '@';
                            }
                            if (tabell[i][j - 1] == 'O') {
                                neste[i][j - 1] = '@';
                            }
                        } // if
                    } // for
                }	     // Flytter verdiene tilbake
                for (i = 1; i < n + 3; i++) {
                    for (j = 1; j <= m; j++) {
                        lovlig[i][j] = neste[i][j];
                        neste[i][j] = '.';
                    }
                }
		skriv_bane();
                if (lovlig[1][slutt + 1] == '@') {
                    break;
                }
            } // for antall steg i algoritmen

            if (lovlig[1][slutt + 1] == '@') {
                System.out.println("The minimum number of turns is " + steg + ".");
            } else {
                System.out.println("The problem has no solution.");
            }
        } // for antall scenarioer
    } // void begin

    void skriv_bane() {
        System.out.println("Steg: " + steg);
        for (int i = 1; i < n + 3; i++) {
            for (int j = 1; j < m + 1; j++) {
                System.out.print(tabell[i][j]);
            }
            System.out.print("  ");
            for (int j = 1; j < m + 1; j++) {
                System.out.print(lovlig[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    static String readLn(int maxLg) {
        byte lin[] = new byte[maxLg];
        int lg = 0, car = -1;
        String line = "";

        try {
            while (lg < maxLg) {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) {
                    break;
                }
                lin[lg++] += car;
            }
        } catch (IOException e) {
            return (null);
        }

        if ((car < 0) && (lg == 0)) {
            return (null);
        }
        return (new String(lin, 0, lg));
    }
}
