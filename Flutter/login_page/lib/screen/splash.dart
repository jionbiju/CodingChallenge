import 'package:flutter/material.dart';
import 'package:login_page/main.dart';
import 'package:login_page/screen/home.dart';
import 'package:login_page/screen/login.dart';
import 'package:shared_preferences/shared_preferences.dart';

class ScreenSplash extends StatefulWidget {
  const ScreenSplash({super.key});

  @override
  State<ScreenSplash> createState() => _ScreenSplashState();
}

class _ScreenSplashState extends State<ScreenSplash> {
  @override
  void initState() {
    checkUserLoggedin();
    super.initState();
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child:Image.asset('assets/images/flutter5786.jpg'),),
    );
  }
  Future<void> gotologin() async{
    await Future.delayed(Duration(seconds: 3));
    Navigator.of(context).push(MaterialPageRoute(builder: (ctx){
      return  LoginPage();
    }));
  }
Future<void> checkUserLoggedin()async{
  final sharedpref=await SharedPreferences.getInstance();
  final UserLoggedIn=sharedpref.getBool(SAVE_KEY_NAME);
  if(UserLoggedIn==null || UserLoggedIn==false){
    gotologin();
  }else{
    Navigator.of(context).pushReplacement(MaterialPageRoute(builder: (ctx)=> HomeScreen()));
  }
}
}
