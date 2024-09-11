const express = require("express");
const app = express();
const cors = require("cors");
const mongoose = require("mongoose");
const port = 4000;
const path = require("path");
const {error} = require("console");
require('dotenv').config();
const TodoModel = require('./Models/TodoModel')

//Cors 
app.use(cors({ origin: true, credentials: true }));
app.use(express.json());

//API Creation
app.get("/",(req,res)=>{
    res.send("Express App is Running")
})

//MongoDB connection
mongoose.connect(process.env.MONGO_DB)
.then(()=>{
    app.listen(port,() => {
        console.log("DB connected successfully and server is running in the port "+port);
    })
})
.catch((err)=>console.log("Mango DB connection error "+err));

//API for created for add task to DB
app.post('/add', (req, res) => {
    const todo = req.body.todo;
  
    TodoModel.create({ task: todo })
      .then((createdTodo) => {
        res.status(200).json(createdTodo); 
      })
      .catch((err) => {
        console.error(err);
        res.status(500).json({ error: 'Failed to create task' }); 
      });
  });

  //API to Delete task
  app.delete('/delete/:id',(req,res)=>{
    const {id} = req.params;
    TodoModel.findByIdAndDelete(id)
    .then(()=>res.status(200).json({ message: 'Task deleted successfully' }))
    .catch((error)=>console.log(error))
  })