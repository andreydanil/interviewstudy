package Arraylists;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SortLogs {

    public static class LogData{
        String firstColumn;
        String secondColumn;
        String thirdColumn;
        String fourthColumn;

        public LogData(String firstColumn, String secondColumn, String thirdColumn, String fourthColumn) {
            this.firstColumn = firstColumn;
            this.secondColumn = secondColumn;
            this.thirdColumn = thirdColumn;
            this.fourthColumn = fourthColumn;
        }

        public LogData(){}

        public String getFirstColumn() {
            return firstColumn;
        }

        public void setFirstColumn(String firstColumn) {
            this.firstColumn = firstColumn;
        }

        public String getSecondColumn() {
            return secondColumn;
        }

        public void setSecondColumn(String secondColumn) {
            this.secondColumn = secondColumn;
        }

        public String getThirdColumn() {
            return thirdColumn;
        }

        public void setThirdColumn(String thirdColumn) {
            this.thirdColumn = thirdColumn;
        }

        public String getFourthColumn() {
            return fourthColumn;
        }

        public void setFourthColumn(String fourthColumn) {
            this.fourthColumn = fourthColumn;
        }
    }

    static List<String> logs = new ArrayList<String>() {

    };

    public static void main(String[] args) {
        logs.add("t1 dbc 12 50");
        logs.add("a4 abc 52 12");
        logs.add("84 cds 83 12");

        for(String log: logs) {
            System.out.println(log);
        }

        Collections.sort(logs);

        System.out.println("Sorted: " + logs);

        List<String> secondColumn = new ArrayList<String>();


        LogData logData[] = new LogData[5];

        int counter = 0;
        for(String log: logs) {
            secondColumn.add(log.split(" ")[1] + " " + log.split(" ")[0] + " " + log.split(" ")[2] + " " + log.split(" ")[3]);
            counter++;
        }

        Collections.sort(secondColumn);

        List<String> result = new ArrayList<String>();

        System.out.println("Sorted second column: " + secondColumn);

        for(String log: secondColumn) {
            result.add(log.split(" ")[1] + " " + log.split(" ")[0] + " " + log.split(" ")[2] + " " + log.split(" ")[3]);
        }

        System.out.println("Final result " + result.toString());


    }

}
