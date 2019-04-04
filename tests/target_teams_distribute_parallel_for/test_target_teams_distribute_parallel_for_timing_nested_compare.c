#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "ompvv.h"
#include "ompvv_timing.h"

// Test for OpenMP 4.5 target data with if
int main() {
  OMPVV_INIT_TIMERS;
  int a_map_var = 0;
  //target teams distribute
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for nested");

  //target teams distribute collapse
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for collapse(1)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for collapse combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for collapse(1)
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for collapse nested");

  //target teams distribute defaultmap
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for defaultmap(tofrom: scalar)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for defaultmap combined");


  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target defaultmap(tofrom: scalar)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for defaultmap nested");

  //target teams distribute default(none)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for default(none)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(none) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams default(none)
        {
          #pragma omp distribute parallel for default(none)
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(none) nested");

  //target teams distribute default(shared)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for default(shared)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(shared) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams default(shared)
        {
          #pragma omp distribute parallel for default(shared)
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for default(shared) nested");

  //target teams distribute depend
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for depend(inout:a_map_var)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for depend combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target depend(inout:a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for depend nested");

  //target teams distribute device
  a_map_var = omp_get_default_device();
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for device(a_map_var)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for device combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target device(a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for device nested");

  //target teams distribute firstprivate
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for firstprivate(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for firstprivate combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for firstprivate(a_map_var)
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for firstprivate nested");

  //target teams distribute if(true)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for if(1)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(true) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target if(1)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for if(1)
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(true) nested");

  //target teams distribute if(false)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for if(0)
      for (int x = 0; x < 1024; ++x){
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(false) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target if (0)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for if(0)
          for (int x = 0; x < 1024; ++x){
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for if(false) nested");

  //target teams distribute lastprivate
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for lastprivate(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for lastprivate combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for lastprivate(a_map_var)
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for lastprivate nested");

  //target teams distribute map(to)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(to: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(to) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target map(to: a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(to) nested");

  //target teams distribute map(from)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(from: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(from) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target map(from: a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(from) nested");

  //target teams distribute map(tofrom)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(tofrom: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(tofrom) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target map(tofrom: a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(tofrom) nested");

  //target teams distribute map(alloc)
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for map(alloc: a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(alloc) combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target map(alloc: a_map_var)
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for map(alloc) nested");

  //target teams distribute private
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for private(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for private combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams
        {
          #pragma omp distribute parallel for private(a_map_var)
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for private nested");

  //target teams distribute shared
  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target teams distribute parallel for shared(a_map_var)
      for (int x = 0; x < 1024; ++x){
          a_map_var = 0;
          OMPVV_TIMING_LOAD;
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for shared combined");

  OMPVV_INIT_TEST;
  for (int i = 0; i < NUM_REP; ++i){
      OMPVV_START_TIMER;
      #pragma omp target
      {
        #pragma omp teams shared(a_map_var)
        {
          #pragma omp distribute parallel for shared(a_map_var)
          for (int x = 0; x < 1024; ++x){
              a_map_var = 0;
              OMPVV_TIMING_LOAD;
          }
        }
      }
      OMPVV_STOP_TIMER;
      OMPVV_REGISTER_TEST;
  }
  OMPVV_TIMER_RESULT("target teams distribute parallel for shared nested");

  return 0;
}