import 'package:flutter/material.dart';

void main(){
  runApp(MyApp());
}
class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return  MaterialApp(
      theme: ThemeData(primaryColor:Colors.green),
      home:HomeScreen(),
    );
  }
}

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      appBar:AppBar(
        backgroundColor: Colors.green,
        leadingWidth:50 ,
        title: Text('Listview Example' ,style:TextStyle(
          fontSize: 30,
          fontWeight: FontWeight.bold,
        ) , ),
      ),
      body: SafeArea(child: ListView.separated(
        itemBuilder: (ctx,index){
          return ListTile(
            title: Text('Person $index'),
            subtitle: Text('Message $index'),
            leading: CircleAvatar(
              radius: 30,
              backgroundImage: NetworkImage('https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQd8J3lWEfbtGBiLlzvHit3pnxDicrxzACmkg&usqp=CAU')
            ),
            trailing: Text('10:$index AM'),
          );
        }, 
        separatorBuilder: (ctx,index){
          return Divider();
        },
         itemCount: 20),),
    );
  }
}