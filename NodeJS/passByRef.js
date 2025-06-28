const { name } = require("ejs");

let a1={
    name:"Jion",
    phone:7954852476,
    city:'Kannur'
};
console.log(a1);
let a2=a1;

function exp(person){
    console.log("inside fuction");
    
    console.log(person.name);   
}
exp(a2);

