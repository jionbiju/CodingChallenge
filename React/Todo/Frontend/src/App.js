import React from 'react';
import './App.css';
import { useState } from 'react';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import {  faCheckSquare } from '@fortawesome/free-solid-svg-icons'
import { faTrash } from '@fortawesome/free-solid-svg-icons'
import axios from 'axios';

function App() {
  const [todos,setTodos]=useState([])
  const [todo,setTodo]=useState('')
  
  const addTodo = (e) => {
    e.preventDefault();
    if (todo.trim() === '') return;
    axios.post('http://localhost:4000/add', { todo })
      .then((response) => {
        const newTodo = { id: response.data._id, text: response.data.task, status: false };
        setTodos([...todos, newTodo]);
        console.log('Task added:', response.data);
      })
      .catch((err) => console.log('Error adding task:', err));
  
    setTodo("");
  };

  const toggleComplete=(id)=>{
    setTodos(
      todos.map((todo) =>
        todo.id === id ? { ...todo, status: !todo.status } : todo
      )
    )
  }
  const deleteTodo=(id)=>{
    setTodos(todos.filter((todo)=> todo.id!==id))
    axios.delete('http://localhost:4000/delete/'+id)
    .then(()=>console.log('Task Deleted successfully'))
    .catch((error)=>console.log('Error in sending id for deletion',error))
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
        <button  className='todo-btn' type='submit'>Add Task</button>
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
