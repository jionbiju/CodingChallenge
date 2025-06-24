let a,b;
a=10,b=20;
function add(a,b){
    return(a+b);
}
let res= add(a,b)
console.log(res);

//Arrow fuctions 
let sum = (a,b) => {
    return a+b;
}
console.log(sum(19,7));

//function expression

let sum2 = function (){
    console.log("Example of function expression");
}
sum2();