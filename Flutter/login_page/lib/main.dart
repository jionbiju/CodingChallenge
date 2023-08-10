import 'package:flutter/material.dart';
import 'package:login_page/screen/splash.dart';
import 'package:shared_preferences/shared_preferences.dart';

const SAVE_KEY_NAME='UserLoggedIn';
void main() {
  runApp(const MyApp());
}
class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return  MaterialApp(
      title:'Login Page',
      theme: ThemeData(
        primaryColor: Colors.blue
      ,),
      home: const ScreenSplash(),
    );
  }
}

