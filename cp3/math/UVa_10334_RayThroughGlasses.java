import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Main
{
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
        BigInteger fib[] = new BigInteger[1002];
        fib[0] = new BigInteger("1");
        fib[1] = new BigInteger("1");
        for (int i=2; i<=1001; i++) {
            fib[i] = new BigInteger("0");
            fib[i] = fib[i].add(fib[i-1]);
            fib[i] = fib[i].add(fib[i-2]);
        }
        while ((input = Main.ReadLn (255)) != null)
        {
          idata = new StringTokenizer (input);
          int n = Integer.parseInt (idata.nextToken());
          System.out.println(fib[n+1]);
        }
    }
}