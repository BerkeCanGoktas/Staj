import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:cbs_turkey/screens/admin_requests_screen.dart';
import 'screens/make_request_screen.dart';
import 'package:cbs_turkey/screens/welcome_screen.dart';
import 'package:cbs_turkey/screens/login_screen.dart';
import 'package:cbs_turkey/screens/register_screen.dart';
import 'package:cbs_turkey/screens/map_screen.dart';
import 'package:firebase_core/firebase_core.dart';
import 'screens/admin_city_submit_screen.dart';
import 'screens/admin_requests_screen.dart';
import 'package:cbs_turkey/data/requests_data.dart';
import 'screens/map_screen.dart';
import 'screens/city_onclicked_screen.dart';
import 'data/city_data.dart';

void main() async{ 
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(Turkey());
}


class Turkey extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => RequestData(),
      child: ChangeNotifierProvider(
        create: (context) => CityData(),
        child: MaterialApp(
          initialRoute: WelcomeScreen.id,
          routes: {
            WelcomeScreen.id: (context) => WelcomeScreen(),
            LoginScreen.id: (context) => LoginScreen(),
            RegisterScreen.id: (context) => RegisterScreen(),
            MapScreen.id: (context) => MapScreen(),
            AdminCitySubmitScreen.id: (context) => AdminCitySubmitScreen(),
            AdminRequestsScreen.id: (context) => AdminRequestsScreen(),
            MapScreen.id: (context) => MapScreen(),
            CityOnClickedScreen.id: (context) => CityOnClickedScreen(),
            MakeRequestScreen.id: (context) => MakeRequestScreen(),
          },
        ),
      ),
    );
  }
}
