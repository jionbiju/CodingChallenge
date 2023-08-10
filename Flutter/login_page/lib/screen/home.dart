import 'package:flutter/material.dart';
import 'package:login_page/screen/login.dart';
import 'package:shared_preferences/shared_preferences.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      appBar: AppBar(
        title:const Text('Home'),
        actions: [
          IconButton(onPressed: (){
            signout(context);
          }, 
          icon:Icon(Icons.exit_to_app))
        ],
      ),
      body:SafeArea(
        child: Center(
        child: const Text('Home'))),
    );
  }
  signout(BuildContext ctx)async {
    final SharedPref=await SharedPreferences.getInstance();
    await SharedPref.clear();

    Navigator.of(ctx).pushAndRemoveUntil(
    MaterialPageRoute(builder: (ctx)=>LoginPage()), (route) => false);
  }
}