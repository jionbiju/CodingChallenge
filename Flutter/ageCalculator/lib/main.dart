
import 'package:flutter/material.dart';



void main(){
  runApp(MyApp());
}
class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return  MaterialApp(
      theme: ThemeData(primaryColorLight: Colors.indigo),
      home: _HomeScreenState(),
    );
  }
}
class _HomeScreenState extends StatefulWidget {
  const _HomeScreenState({super.key});

  @override
  State<_HomeScreenState> createState() => __HomeScreenStateState();
}

class __HomeScreenStateState extends State<_HomeScreenState> {
  String myAge='';
  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      appBar: AppBar(
        title:const Center(child: Text('Age Calculator',style: TextStyle(
        fontSize: 30,
        fontWeight: FontWeight.bold,
        ), )),
        
      ),
      body: Center(child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
       const Text('Your age is ',style: TextStyle(
        fontSize: 25,
        fontWeight: FontWeight.w600,
       ),),
       const SizedBox(height:10 ,),
      Text(myAge),
      const SizedBox(height: 30,),
       ElevatedButton(
              onPressed: () => pickdob(context),
              child: const Text('Pick Your Date of Birth'),
            )
      ],),),
  
    );
  }
  pickdob(BuildContext context){
  calculateAge(DateTime birth) {
    DateTime now = DateTime.now();
    Duration age = now.difference(birth);
    int years = age.inDays ~/ 365;
    int months = (age.inDays % 365) ~/ 30;
    int days = ((age.inDays % 365) % 30);
    setState(() {
      myAge = '$years years, $months months and $days days';
    });
  }
  showDatePicker(
    context: context,
    initialDate: DateTime.now(),
     firstDate: DateTime(1900), 
     lastDate: DateTime.now()
     ).then((pickedDate) {
      if (pickedDate != null) {
        calculateAge(pickedDate);
      }
    });
   
}
}


