The RE tools used for the problem were: GDB and Ghidra

Procedure followed:
- The binary file was opened on ghidra to decompile it into a more readable format resembling C.  This gave insights about what was happening in the main function.
Main function:
![Screenshot from 2022-08-16 22-53-14](https://user-images.githubusercontent.com/97296908/184951668-48b495ac-0f25-436d-b2fb-ff8838e57f5f.png)

- There was a function **checkPassword** which returned some value and depending on that value some if else statements will print access granted or invalid password.
checkPassword:
![Screenshot from 2022-08-16 22-56-04](https://user-images.githubusercontent.com/97296908/184951954-24a0f469-adfd-4335-acb9-0bc97fa56f03.png)

- In this function there was a function **checkRes** which finally stores a 30 charachter string in a local variable which probably contains password.
chekRes:
![Screenshot from 2022-08-16 22-56-18](https://user-images.githubusercontent.com/97296908/184952008-5a27766a-bca9-49c3-9158-d8ee2370553b.png)

- Then there is a for loop that compares our input char by char with the password array and then if all charachters match it returns 0 while if any charachter is not same that loop breas and 1 is returned.
- But actually if we would simply jump to the instruction where return 0 statement is implemented then we can simply get Access Granted.
- Now I used GDB to disassemble checkRes and then went through its assembly instructions.(Also selecting a specific statement in ghidra shows the corresponding assembly instructions so that helped in finding which instruction did what)
- Finally figured out that just after enetring the while loop, the if statement that checks if the iterator variable is less than 30 or not, it had Jump instruction that sent the code again to start of while loop.
- So simply skipped that jump by using jump command in GDB and jumped to next memory address and finally checkRes returned 0 and problem was solved.
Finally cracking the file:
![Screenshot from 2022-08-16 21-53-36](https://user-images.githubusercontent.com/97296908/184952197-723cfaf5-abe2-456f-9225-51180725c9ce.png)
