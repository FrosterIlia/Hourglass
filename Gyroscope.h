#pragma once
#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

class Gyroscope {
  public:
    Gyroscope() {
      init();


      _mpuFlag = false;  // interrupt flag

    }

    void begin(){
      do{
        //initialize mpu and interrupts
        mpu.reset();
        mpu.resetDMP();
        mpu.initialize();
        mpu.dmpInitialize();
        mpu.setDMPEnabled(true);
      } while (!mpu.testConnection());
      
      //Serial.println(getRotationX());
      // mpu.CalibrateAccel(6);
    }

    void dmpReady() { // interrupt ready
      _mpuFlag = true;
    }
    void tick() {
      
      if (_mpuFlag && mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
        
        // calculations
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        _mpuFlag = false;
      }
    }

    int getRotationX(){
      return degrees(ypr[2]);
    }
    int getRotationY(){
      return degrees(ypr[1]);
    }
    int getRotationZ(){
      return degrees(ypr[0]);
    }
    
  private:
    volatile bool _mpuFlag;
    uint8_t fifoBuffer[45];
    float ypr[3];
    Quaternion q;
    VectorFloat gravity;
    MPU6050 mpu;
};