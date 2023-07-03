var operator
var oldValue
var newValue
var result
function buttonclick(val){

    document.getElementById("screen").value+=val
}

function clearDisplay(){
    document.getElementById("screen").value=""
}
function plusButton(){
    oldValue=parseInt(document.getElementById("screen").value)
    document.getElementById("screen").value=""
    operator='+'
}
function minusButton(){
    oldValue=document.getElementById("screen").value
    document.getElementById("screen").value=""
    operator='-'
}
function multiButton(){
    oldValue=document.getElementById("screen").value
    document.getElementById("screen").value=""
    operator='*'
}
function divisionButton(){
    oldValue=document.getElementById("screen").value
    document.getElementById("screen").value=""
    operator='/'
}
function equalButton(){
    newValue=parseInt(document.getElementById("screen").value)
    document.getElementById("screen").value=""
    result
    if(operator =='+'){
        result=oldValue + newValue
        document.getElementById("screen").value=result;
    }
    else if(operator=='-'){
        result=oldValue - newValue
        document.getElementById("screen").value=result;
    }
    else if(operator=='*'){
        result=oldValue * newValue
        document.getElementById("screen").value=result;
    }
    else if(operator=='/'){
        result=oldValue / newValue
        document.getElementById("screen").value=result;
    }
}
