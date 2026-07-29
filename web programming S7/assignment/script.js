function addTask(){

    let task = document.getElementById("task").value;
    let member = document.getElementById("member").value;

    if(task==""){
        alert("Enter a task");
        return;
    }

    let table = document.getElementById("taskList");

    let row = table.insertRow();

    let c1 = row.insertCell(0);
    let c2 = row.insertCell(1);
    let c3 = row.insertCell(2);
    let c4 = row.insertCell(3);

    c1.innerHTML = task;
    c2.innerHTML = member;
    c3.innerHTML = "Pending";

    c4.innerHTML =
    `<button onclick="completeTask(this)">Complete</button>
     <button onclick="deleteTask(this)">Delete</button>`;

    document.getElementById("task").value="";
}

function completeTask(btn){

    let row = btn.parentNode.parentNode;

    row.cells[2].innerHTML="Completed";
    row.cells[0].classList.add("completed");
}

function deleteTask(btn){

    let row = btn.parentNode.parentNode;
    row.remove();
}