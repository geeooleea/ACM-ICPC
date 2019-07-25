import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.time.LocalDate;

public class Main {
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin()
    {
        String input;
        StringTokenizer idata;
        
        while ((input = Main.ReadLn (255)) != null) {
            idata = new StringTokenizer (input);
            int n = Integer.parseInt(idata.nextToken());
            int day = Integer.parseInt(idata.nextToken());
            int month = Integer.parseInt(idata.nextToken());
            int year = Integer.parseInt(idata.nextToken());
            
            if (n==0 && day==0 && month==0 && year==0) return;
            
            LocalDate date = LocalDate.of(year, month, day);
            
            System.out.println(date.plusDays(n).getDayOfMonth() + " " + date.plusDays(n).getMonth().getValue() + " " + date.plusDays(n).getYear());
        }
    }
}