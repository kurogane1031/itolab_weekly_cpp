#pragma once
#include <chrono>
#include <iostream>

class Timer{
public:
  Timer()
  {
    m_StartTimepoint = std::chrono::high_resolution_clock::now();
  }

  ~Timer()
  {
    Stop();
  }

  void Stop(){
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTimepoint - m_StartTimepoint).count() / (float)repeat;
    auto ms = duration * 0.001;

    std::cout << "Total repetition: " << repeat << ", duration: " << duration << " us (" << ms << " ms)\n";
  }

  void iteration(){
    repeat++;
  }
  
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
  int repeat = 0;
};
