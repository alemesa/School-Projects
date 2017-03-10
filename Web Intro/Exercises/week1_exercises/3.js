/* Week1-Exercise3 */
var number = prompt("Enter a number");

var factors = [];
var i = 1;
var y = 0;


for(i;i<=number;i++){
  
  if( number%i==0){
    
    factors[y]= i;
    y++;
    
  };
  
};

alert("The factors of "+ number + " are:" + factors);
console.log("The factors of "+ number + " are:" + factors);

