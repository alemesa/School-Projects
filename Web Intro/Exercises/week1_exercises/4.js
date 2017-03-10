/* Week1-Exercise4 */
var number = prompt("Enter a number (1-10) ");
var console_output = "";
var total = number * number;
var space_counter = number;

if(number<=10){
  
  //Print row
  for(i=0;i<total;i++){
    
    console_output = console_output + "* ";
    space_counter--;
    
    if(space_counter==0){
      
      console_output = console_output + "\n";
      space_counter = number;
      
    }
    
    
  }
  
 
}
else{
  alert("Number bigger than 10, sorry");
}

console.log(console_output);
alert(console_output);


