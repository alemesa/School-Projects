/* Week1-Exercise5 */
var number = prompt("Enter a number");
var prime = true;
var i;

//Prime numbers are divided by 1 and itself only
//Checking the range in between them

for(i=number-1;i>1;i--){
  
  if(number%i==0){
    prime = false;
    break;
  }
  
}

if(prime){
  console.log(number + " is a prime number");
  alert(number + " is a prime number");
}
else{
  console.log(number + " is not a prime number");
  alert(number + " is not a prime number");
}



