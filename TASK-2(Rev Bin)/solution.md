The RE tools used for the problem were: GDB and Ghidra

Procedure followed:
- The binary file was opened on ghidra to decompile it into a more readable format resembling C.  This gave insights about what was happening in the main function.
- There was a function **checkPassword** which returned some value and depending on that value some if else statements will print access granted or invalid password.
- In this function there was a function **checkRes** which finally stores a 30 charachter string in a local variable which probably contains password.
- Then there is a for loop that compares our input char by char with the password array and then if all charachters match it returns 0 while if any charachter is not same that loop breas and 1 is returned.
- But actually if we would simply jump to the instruction where return 0 statement is implemented then we can simply get Access Granted.
- Now I used GDB to disassemble checkRes and then went through its assembly instructions.(Also selecting a specific statement in ghidra shows the corresponding assembly instructions so that helped in finding which instruction did what)
- Finally figured out that just after enetring the while loop, the if statement that checks if the iterator variable is less than 30 or not, it had Jump instruction that sent the code again to start of while loop.
- So simply skipped that jump by using jump command in GDB and jumped to next memory address and finally checkRes returned 0 and problem was solved.
