function factorial(n){
	return  (n <= 1) ? 1 : n * factorial(n-1);
} // recursion

do {
	var x = Number(prompt("Enter a number (0 to stop):", 1));
	if (x != 0)
		console.log("The factorial of "+ x + " is: "+ factorial(x));
	else 
		console.log("Please input a number greater than 0!");
} while (x != 0);

