#ifndef MultiTask_H
#define MultiTask_H
 
#include <Arduino.h>
 
class MultiTask {

private:
  unsigned long miliseconds;
  unsigned long currentMicros = 0;
  bool taskEnable = false;
    
public:
  MultiTask ();
  ~MultiTask ();
  void runTask(unsigned long miliseconds);
  bool isTaskDue();
  void disableTask();
};
 
#endif
