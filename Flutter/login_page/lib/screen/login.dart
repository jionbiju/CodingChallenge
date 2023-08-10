import 'package:flutter/material.dart';
import 'package:login_page/main.dart';
import 'package:login_page/screen/home.dart';
import 'package:shared_preferences/shared_preferences.dart';

class LoginPage extends StatelessWidget {
   LoginPage({super.key});
  final _usernameController=TextEditingController();
  final _passwordController=TextEditingController();
 

  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(15.0),
          child: Column(
            children: [
              const Text('Login',style: TextStyle(
                fontSize: 30,
                color: Colors.black,
                fontWeight: FontWeight.bold,
              ),
              ),
              const SizedBox(
                  height: 20,
                ),
              TextFormField(
                controller: _usernameController,
                decoration:const InputDecoration(
                  border: OutlineInputBorder(),
                  hintText: 'Username',
                ),
              ),
               const SizedBox(
                  height: 20,
                ),
              TextFormField(
                controller: _passwordController,
                obscureText: true,
                decoration:const InputDecoration(
                  border: OutlineInputBorder(),
                  hintText: 'Password',
                ),
              ),
              const SizedBox(
                  height: 20,
                ),
              ElevatedButton.icon(onPressed:() {
                checkLogin(context);
              }, 
              icon:const Icon(Icons.check), 
              label: const Text('Login') )
            ],
          ),
        ),
      )
    );
  }
  void checkLogin(BuildContext ctx)async {
    final _username=_usernameController.text;
    final _password= _passwordController.text;
    if(_username ==_password){
      //Goto homescreen
    final sharedPref=await SharedPreferences.getInstance();
    await sharedPref.setBool(SAVE_KEY_NAME, true);

      Navigator.of(ctx).pushReplacement(MaterialPageRoute(builder: (ctx){
        return HomeScreen();
      }));
    }else{
      //snackbar
      final _errormessage='User name and password does not match';
    //alert dialog 
    showDialog(context: ctx, builder: (ctx1){
      return AlertDialog(
        title:const Text('Error'),
        content: Text(_errormessage),
        actions: [
          TextButton(onPressed: (){
            Navigator.of(ctx1).pop();
          }, child: const Text('Close')),
        ],
      );
    });
    }
  }
}