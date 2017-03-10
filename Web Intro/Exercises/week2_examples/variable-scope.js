var display = "";      // Global variable
ident_A = 5;           // Global variable - bad practice

function someFunction() {   // Start of function

	 var ident_B = 15;      // Local  variable
	 ident_C     = 34;      // Global variable - bad practice
	 var ident_A = 0;
	 ident_C++;             // increment ident_C by 1 
	 ident_A     = ident_B + ident_C;
	 console.log(ident_A);        // show the value of ident_A inside the function      

} // End of function

someFunction();      // call the function
console.log(ident_A);      // show the value of ident_A outside the function
console.log(ident_C);      // show the value of ident_C
console.log(ident_B);      // what happens here?
