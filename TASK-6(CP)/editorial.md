### **Hint** 
>solve the equations  **a+b+c=n**  and  **a<sup>2</sup> +b<sup>2</sup> = c<sup>2</sup>**, eliminate one variable and try writing some constant as a multiplication of two other expressions containing the variables.
### **Solution**
> Substitute **c=n-a-b** in **a<sup>2</sup> +b<sup>2</sup> = c<sup>2</sup>**  
> **a<sup>2</sup>+b<sup>2</sup> = n<sup>2</sup>+a<sup>2</sup>+b<sup>2</sup>-2na-2nb+2ab**
> **n<sup>2</sup>/2 -na-nb+ab=0**  
> **(n-a)(n-b)=n<sup>2</sup>/2**  
> Now use seive algorithm to precompute all divisors of every n<1000000.  
> Cycle through divisors of **n<sup>2</sup>/2** and assign the pair of divisor to n-a and n-b.  
> choose appropriate divisors such that a and b come out to be natural numbers.  