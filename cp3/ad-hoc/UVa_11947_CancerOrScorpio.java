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
        
        input = Main.ReadLn (255);
        int n = Integer.parseInt(input);
        
        for (int i=1; i<=n; i++) {
            input = Main.ReadLn(255);
            LocalDate conceive = LocalDate.of(Integer.parseInt(input.substring(4,8)), Integer.parseInt(input.substring(0,2)), Integer.parseInt(input.substring(2,4)));
            LocalDate birth = conceive.plusWeeks(40);
            System.out.println(i + " " + String.format("%02d", birth.getMonth().getValue()) + "/" + String.format("%02d", birth.getDayOfMonth()) + "/" + birth.getYear() + " " + getSign(birth));
        }
    }
    
    public String getSign(LocalDate birth) {
        if (birth.isBefore(LocalDate.of(birth.getYear(),2,20)) && birth.isAfter(LocalDate.of(birth.getYear(),1,20)))
            return "aquarius";
        if (birth.isAfter(LocalDate.of(birth.getYear(),2,19)) && birth.isBefore(LocalDate.of(birth.getYear(),3,21)))
            return "pisces";
        if (birth.isAfter(LocalDate.of(birth.getYear(),3,20)) && birth.isBefore(LocalDate.of(birth.getYear(),4,21)))
            return "aries";
        if (birth.isAfter(LocalDate.of(birth.getYear(),4,20)) && birth.isBefore(LocalDate.of(birth.getYear(),5,22)))
            return "taurus";
        if (birth.isAfter(LocalDate.of(birth.getYear(),5,21)) && birth.isBefore(LocalDate.of(birth.getYear(),6,22)))
            return "gemini";
        if (birth.isAfter(LocalDate.of(birth.getYear(),6,21)) && birth.isBefore(LocalDate.of(birth.getYear(),7,23)))
            return "cancer";
        if (birth.isAfter(LocalDate.of(birth.getYear(),7,22)) && birth.isBefore(LocalDate.of(birth.getYear(),8,22)))
            return "leo";
        if (birth.isAfter(LocalDate.of(birth.getYear(),8,21)) && birth.isBefore(LocalDate.of(birth.getYear(),9,24)))
            return "virgo";
        if (birth.isAfter(LocalDate.of(birth.getYear(),9,23)) && birth.isBefore(LocalDate.of(birth.getYear(),10,24)))
            return "libra";
        if (birth.isAfter(LocalDate.of(birth.getYear(),10,23)) && birth.isBefore(LocalDate.of(birth.getYear(),11,23)))
            return "scorpio";
        if (birth.isAfter(LocalDate.of(birth.getYear(),11,22)) && birth.isBefore(LocalDate.of(birth.getYear(),12,23)))
            return "sagittarius";
        if (birth.isAfter(LocalDate.of(birth.getYear(),12,22)) && birth.isBefore(LocalDate.of(birth.getYear()+1,1,1)) || 
                birth.isAfter(LocalDate.of(birth.getYear()-1,12,31)) && birth.isBefore(LocalDate.of(birth.getYear(),1,21)))
            return "capricorn";
        return "";
    }
}