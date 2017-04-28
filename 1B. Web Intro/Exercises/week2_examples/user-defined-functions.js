// Note to Students: Each example is separated by a title comment.  To test
// each example below, simply un-comment the example, save the file and open 
// in your web browser.

/************************************
 * examples: function without return.
 ************************************/
/*greetings( prompt("Please enter your name") );

function greetings (name) {
	console.log("Hello " + name);
}

//go(); // will give Exception; need to run after "go" is defined. 

var go = function () {
	console.log( "GO LEAFS GO" );
};

go(); */

/*******************************************
 * examples: adding two numbers using functions.
 *******************************************/
/*// using function declaration approach
function addTwoNumbers(a, b) {return a + b;}

// using function expression approach
var add2numbers = function(a, b){return a + b;};

// function with multiple or without parameter(s)
function addNumbers() {
   var sum = 0;
   for (var i=0; i<arguments.length; i++) {
		 sum += arguments[i];
   }
   return sum;
}

console.log( addTwoNumbers(2, 3) ); // 5
console.log( add2numbers(2, 4) );   // 6
console.log( addNumbers() );        //0
console.log( addNumbers(2, 6, 8) ); //16 */
