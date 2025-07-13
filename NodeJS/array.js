let arr = new Array(5);
for (let i = 0; i < arr.length; i++) {
    arr[i] = i + 5;
}

console.log(arr);
//for of loop
for( let a of arr){
    console.log(a);
}

//add an element at the end
arr.push(10);
console.log(arr);

//add an element at the begining
arr.unshift(4);
console.log(arr);
    
//remove an element at the end
let x=arr.pop();//pop() return the removed element
console.log(arr);
console.log("Removed element:",x)

//remove an element from the begining
let y=arr.shift();//shift() return the removed element
console.log(arr);
console.log("Removed element:",y);


//splice(startindex,deleteCount,items)
//used to delete/add elements at a particular index
let removedArr = arr.splice(1,2);
console.log(arr);
console.log("Removed element:",removedArr);

//add one element using splice
arr.splice(1,0,60);
console.log(arr);

//add more than one elements using splice
arr.splice(1,0,6,7);
console.log(arr);

//delete and addd
let removed = arr.splice(2,2,66,77);
console.log(arr);
console.log("Removed element:",removed);

//search the index of an element
console.log("Index is ",arr.indexOf(77));
