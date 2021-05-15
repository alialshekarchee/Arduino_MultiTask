#include "MultiTask.h"

MultiTask::MultiTask()
{
  
}

MultiTask::~MultiTask()
{

}

void MultiTask::runTask(unsigned long miliseconds)
{
  this->miliseconds = miliseconds;
  this->currentMicros = micros();
  this->taskEnable = true;
}

bool MultiTask::isTaskDue()
{
  if((micros() - this->currentMicros) / 1000 >= this->miliseconds && this->taskEnable)
  {
    this->currentMicros = micros();
    this->taskEnable = false;
    return true;
  }
  else
  {
    if(micros() >  4294967000)
    {
      this->currentMicros = 0;
    }
    return false;
  }
}

void MultiTask::disableTask() {
  this->taskEnable = false;
}