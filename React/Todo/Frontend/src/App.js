import React from 'react';
import './App.css';
import { useState } from 'react';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import {  faCheckSquare } from '@fortawesome/free-solid-svg-icons'
import { faTrash } from '@fortawesome/free-solid-svg-icons'
import { v4 as uuidv4 } from "uuid";

function App() {
  const [todos,setTodos]=useState([])
  const [todo,setTodo]=useState('')
  const addTodo=(e)=>{
    setTodos([...todos,{id: uuidv4(),text:todo, status:false}])
    setTodo("")
    e.preventDefault()  
  }
  const toggleComplete=(id)=>{
    setTodos(
      todos.map((todo) =>
        todo.id === id ? { ...todo, status: !todo.status } : todo
      )
    )
  }
  const deleteTodo=(id)=>{
    setTodos(todos.filter((todo)=> todo.id!==id))
  }
  return (
    <div className="app">
      <div className="mainHeading">
        <h1>To-Do List</h1>
      </div>
      <div className="subHeading">
        <h2> Whoop, it's Monday 🌝 ☕ </h2>
      </div>
      <form className='todo-form' onSubmit={addTodo}>
        <input className='todo-input' value={todo} onChange={(e)=>setTodo(e.target.value)}
        type='text' placeholder='What is the task today?' />
        <button className='todo-btn' type='submit'>Add Task</button>
      </form>
      <div>
      {
        
        todos.map((obj)=>(
            <div className='Todo'>
            <p  className={`${obj.status?'completed' : "incompleted"}`} >{obj.text}</p>
            <div className="todo-icons">
            <FontAwesomeIcon className="edit-icon" icon={faCheckSquare} onClick={()=>toggleComplete(obj.id)}/>
            <FontAwesomeIcon className="delete-icon" icon={faTrash} onClick={()=>deleteTodo(obj.id)} />
            </div>
            </div>
          )
        )
      }
      </div>
    </div>
  );
}

export default App;
