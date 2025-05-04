import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ReadFile {
  public static void main(String[] args){
    System.out.println("##### Start Read files #####");

    long startTime = System.nanoTime();

    for(int i = 0 ; i < 200 ; i++ ){
      Path path = Paths.get("./input_data/" + (i+1)+ ".txt");
      try {
        String content = Files.readString(path);
        // System.out.println(content);
      } catch(IOException e) {
        e.printStackTrace();  
      }
    }

    long endTime = System.nanoTime();

    System.out.println("time: " + (endTime - startTime) + "ns");
  }
}
