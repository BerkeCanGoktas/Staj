import 'package:flutter/material.dart';

class TaskTile extends StatefulWidget {

  bool isChecked;
  final String taskName;
  final Function checkboxCallback;
  final VoidCallback longPressCallback;
  final VoidCallback onTapCallback;
  final int duration;

  TaskTile({required this.taskName, required this.isChecked, required this.checkboxCallback, required this.longPressCallback, required this.onTapCallback,
            required this.duration});

  @override
  State<TaskTile> createState() => _TaskTileState();
}

class _TaskTileState extends State<TaskTile>  with SingleTickerProviderStateMixin {
  // late AnimationController animationController;
  // late Animation animation;
  // late Animation animationColor;
  // @override
  // void initState() {
  //   super.initState();
  //   animationController = AnimationController(
  //     duration: Duration(minutes: null ?? widget.duration),
  //     vsync: this,
  //   );
  //   animationColor =
  //       ColorTween(begin: Colors.black, end: Colors.red)
  //           .animate(animationController);
  //   animationController.forward();
  //   animationController.addListener(() {
  //     setState(() {});
  //     print(animationController.value);
  //   }); 
  // }

  // @override
  // void dispose() {
  //   super.dispose();
  //   animationController.dispose();
  // }
   @override
  Widget build(BuildContext context) {
    return ListTile(
      onLongPress: widget.longPressCallback,
      onTap: widget.onTapCallback,
      title: Text(
        widget.taskName,
        style: TextStyle(
            decoration: widget.isChecked ? TextDecoration.lineThrough : null,
            color: Colors.black /*animationColor.value*/),
      ),
      trailing: Checkbox(
      activeColor: Colors.lightBlueAccent,
      value: widget.isChecked,
      onChanged: (value) {widget.checkboxCallback(value);},
    ),
    );
  }
}