/* Program Outline
 * This program has the job of encrypting and decrypting messages by comparing it to a key code.
 * The Plan is to 
 * 
 * Get the key and initialise important variables.
 * Let them make a choice and act from that choice using an If statement.
 * Option 1 encrypt. check 1 character at a time and loop this process
 * Option 2 decrypt. check 1 character at a time and loop this process
 * Message stating end of program.
 */

// decrypt missing letters or invalid positions does not work so not included in code
// decrypt does not work when numbers outside of scope are entered.


import java.util.Scanner;
//Author: Connor Chamberlain 18/04/16.
//References listed at the end of the program.

public class SentenceCipher {
  public static void main(String[] args) {
    
    Scanner sc1 = new Scanner(System.in);        // Creates scanner 1.
    
    int i;                         // Variable initialisation
    int position = 0;              // storage for character position
    double invalidChar = 0;        // used in loss of characters
    double informationLoss, length;// length = length of message, or key.
    String message;                // User imputted message to encrypt/decrypt
    char ch;                       // char read in conversion, storage       
    int index;                     // position of a character.
    String end = "";               // end result               
    final int Encrypt = 1;         // Encrypts message
    final int Decrypt = 2;         // Decrypts message
    final int Stop = -2;           // stops imput into scanner
    final int InvalidChar = -1;    // Invalid position of a character, not there.
    {
      
      
      // This is where the user enters the key.
      System.out.println("Program Begins");
      System.out.print("Enter your Key: ");                     // Prompt for key.
      String key = sc1.nextLine();                              // User imput: key.
      System.out.println("Your key is: " + key);                // User visual confirmation of key.
      
      // This is where user chooses their intention.
      System.out.print("Press (1) to Encrypt, or (2) to Decrypt a message: ");        // Prompt for action.
      int action = sc1.nextInt();                                                     // User imput for action.
      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      // This is where the user has made the choice to encrypt.
      if(action == Encrypt) {                                                      // Check choice is 1 for encrypt.
        
        System.out.print("Type your message to encrypt: ");                  // Prompt user for message
        message = sc1.next();                                           
        length= message.length();                                        
        
        System.out.print("Encrypted Message: ");                             // Start of later encrypted message.
        
        
        
        for (i = 0; i < length; i++) {       // The loop which goes through each character one at a time to encrypt it.
          
          ch = message.charAt(position);         
          index = key.indexOf(ch);                
          
          
          if(index == InvalidChar) {                           // The if statement used to check for invalid message characters.
            
            System.out.print("_ ");          
            invalidChar++;                
          }
          
          
          else {                                                                // Else statement for valid characters.
            
            System.out.print(index + " ");    
          } 
          
          position++;                                         
        }         
        
        
        
        
        // Outside of if statement. Nearing end of Encryption.
        System.out.println("-2");                              
        informationLoss = (100 / length) * invalidChar;        // Calculation for Information loss. Invalid characters.
        System.out.println("Information loss = " + informationLoss + "%");         // Prints the results in a sentence.
      }  
      
      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      // This is where the user has made the choice to decrypt.
      if (action == Decrypt) {
        
        System.out.println("Type your encrypted message one number at a time: ");     // get values and issues prompts
        System.out.println("Enter -2 to to signify end of encrypted message.");    
        position = sc1.nextInt();                      
        ch = key.charAt(position);                    
        end += ch;
        length = key.length();
        {
          
          // While loop to detect end of message.
          while (position!= Stop) {                                                     // Keeps user imput ongoing until.
            
            position = sc1.nextInt();            
            
            // repetition to start.//
            if (position!= Stop) {                                // Start of if statement to add characters to the output.
              
              
              ch = key.charAt(position);
              end += ch;                             
              
            }
            
            else {                                                                               // End of if statement. 
              System.out.println(end); 
            }   // Prints the final result of the decrypted message.
          }   // end of while loop
        }
      } 

      
      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      // Final print stating the program is over.
      System.out.println("Program ended");
    } 
    sc1.close();
  }
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* References + Bibliography
 * https://blog.udemy.com/java-charat/
 * http://www.javatpoint.com/java-string-charat
 * http://codingbat.com/doc/java-string-indexof-parsing.html
 * http://www.javacoffeebreak.com/faq/faq0056.html
 * http://www.java-examples/com/java-boolean-primitive-example
 * http://www.java-examples/com/do-while-loop
 * http://stackoverflow.com/questions/12734721/string-not-replacing-characters
 * Java API (2015) oracle        http://docs.oracle.com/javase/6/docs/api/  Most used Source
 * Leture notes, Tutorials, and teacher.
 */