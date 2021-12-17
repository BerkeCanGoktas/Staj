class Task{
  final String taskName;
  bool isDone;
  Task({required this.taskName, required this.isDone});
  void toggleDone(){
    isDone = !isDone;
  }

}