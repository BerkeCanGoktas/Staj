import 'package:flutter/material.dart';

class RequestTile extends StatefulWidget {
  final String requestCityName;
  final VoidCallback longPressCallback;
  final VoidCallback onTapCallback;
  final String requestText;

  RequestTile({required this.requestText, required this.requestCityName, required this.longPressCallback, required this.onTapCallback});

  @override
  State<RequestTile> createState() => _RequestTileState();
}

class _RequestTileState extends State<RequestTile>  with SingleTickerProviderStateMixin {
 
   @override
  Widget build(BuildContext context) {
    return ListTile(
      onLongPress: widget.longPressCallback,
      onTap: widget.onTapCallback,
      title: Text(
        '${widget.requestCityName}:',
        style: TextStyle(
            color: Colors.black),
      ),
      trailing: Text(widget.requestText, style: TextStyle(color: Colors.black87),),
    );
  }
}