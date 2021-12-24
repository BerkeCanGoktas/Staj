import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'tasks/task_data.dart';
import 'screens/login_screen.dart';
import 'screens/register_screen.dart';
import 'screens/welcome_screen.dart';
import 'screens/management_screen.dart';
import 'package:firebase_core/firebase_core.dart';

void main() async{ 
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(WorkManagement());
}

class WorkManagement extends StatelessWidget {

  static int initDatabase = 0;

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => TaskData(),
      child: MaterialApp(
        initialRoute: WelcomeScreen.id,
        routes: {
          WelcomeScreen.id: (context) => WelcomeScreen(),
          LoginScreen.id: (context) => LoginScreen(),
          RegistrationScreen.id: (context) => RegistrationScreen(),
          ManagementScreen.id: (context) => ManagementScreen(),
        },
      ),
    );
  }
}
