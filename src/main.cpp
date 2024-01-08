/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// mano                 motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;


void avanzar(double distancia_en_pulgadas) {
  // Verifica la dirección del movimiento
  if (distancia_en_pulgadas >= 0.0) {
    // Avanza hacia adelante
    Drivetrain.driveFor(reverse,distancia_en_pulgadas,inches);
  }else if (distancia_en_pulgadas <= 0.0){
    distancia_en_pulgadas = distancia_en_pulgadas*-1;
    // Avanza hacia atrás
    Drivetrain.driveFor(forward,distancia_en_pulgadas,inches);

    
  }

}

// Función para girar
void giro(double grados) {
  // Verifica la dirección del giro
  if (grados >= 0.0) {
    // Gira a la derecha
    Drivetrain.turnFor(right,grados,degrees);
  } else {
    grados=grados*-1;
    // Gira a la izquierda
    Drivetrain.turnFor(left,grados,degrees);
  }

  }


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
  int lento=30;
  int rapido=90;
  int normal=55;
  
  void autonomofuncional()
{
  Drivetrain.setDriveVelocity(lento, percent);
  avanzar(25.0);
  giro(90.0);
  Drivetrain.setDriveVelocity(normal,percent);
  avanzar(22.0);
  avanzar(-22.0);
  giro(-90.0);
  avanzar(16.0);
  giro(-90.0);
  avanzar(-28);
}

void printPosition() {
  // Print GPS position values to the V5 Brain
  Brain.Screen.print("X: %.2f", GPS8.xPosition(mm));
  Brain.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  Brain.Screen.newLine();
}

void autonomoalterno()
{
 Drivetrain.setDriveVelocity(lento, percent);
  BRAZO.stop(hold);
  avanzar(22.0);
  giro(90.0);
  Drivetrain.setDriveVelocity(25,percent);
  Drivetrain.drive(reverse);
  wait(25,sec);
  Drivetrain.stop();

  /*
  avanzar(20.0);
  giro(-90.0);
  manoAbajo();
  avanzar(-21);
  manoArriba();
  avanzar(24);
  Drivetrain.setDriveVelocity(rapido,percent);
  avanzar(-24);
  */
  Drivetrain.stop();
}

/* 

void movimientoGPS(int equis, int ye)
{
  {
  // Calibrate the GPS before starting
  GPS8.calibrate();
  while (GPS8.isCalibratRing()) { task::sleep(50); }

  // Orient the drivetrain's heading with the GPS heading
  //Drivetrain.setHeading(GPS8.heading(), degrees);
  Drivetrain.setTurnVelocity(25, percent);

  // Print the starting position of the robot
  printPosition();

  // Store the current position of the robot
  float startingX = GPS8.xPosition(mm);
  float startingY = GPS8.yPosition(mm);

  // Store the target ending position of the robot
  float endingX = equis;

  float endingY = ye;

  // Implement atan2 to calculate the heading that the robot needs to
  // turn to in order to drive towards the ending position
  float turnAngle = atan((endingX - startingX) / (endingY - startingY)) * 180 / M_PI;
  if (endingY - startingY < 0) {
    turnAngle = turnAngle + 180;
  }

  // Turn the robot to face the ending position
  Drivetrain.turnToHeading(turnAngle, degrees, true);

  // Calculate the drive distance needed, then drive towards the target position
  float driveDistance = sqrt(((endingX - startingX) * (endingX - startingX)) + ((endingY - startingY) * (endingY - startingY)));

  Drivetrain.driveFor(forward, driveDistance, mm, true);
  
  // Print the ending position of the robot
  printPosition();
}

}
 */
 
void autonomoalterno2()
{
 Drivetrain.setDriveVelocity(lento, percent);
  BRAZO.spin(forward);
  wait(500,msec);
  BRAZO.stop(hold);
  avanzar(-28.0);
  giro(90.0);
  Drivetrain.setDriveVelocity(25,percent);
  avanzar(-24);
  BRAZO.spin(forward);
  wait(2300,msec);
  BRAZO.spin(reverse);
  wait(2500,msec);
  BRAZO.stop(hold);
  avanzar(20);
  giro(180);
  avanzar(15);


}

void autonomoalterno2continuacion()
{
    Drivetrain.setDriveVelocity(rapido,percent);
  wait(200,msec);
  avanzar(45);
  wait(200,msec);
  
  Drivetrain.stop(coast);
  wait(200,msec);
  Drivetrain.setDriveVelocity(normal,percent);
  avanzar(24);
  giro(45);
  avanzar(20);
}




void autonomoSkills()
{
Drivetrain.setDriveVelocity(lento, percent);
  BRAZO.spin(forward);
  wait(500,msec);
  BRAZO.stop(hold);
  avanzar(-28.0);
  giro(90.0);
  Drivetrain.setDriveVelocity(25,percent);
  avanzar(-24);
  BRAZO.spin(forward);
  wait(2300,msec);
  BRAZO.spin(reverse);
  wait(2600,msec);
  BRAZO.stop(hold);
  Drivetrain.drive(forward);
  wait(5,sec);
  Drivetrain.setDriveVelocity(normal, percent);
  Drivetrain.turn(right);
  wait(300,msec);
  Drivetrain.turn(left);
   wait(300,msec);
    Drivetrain.turn(right);
  wait(300,msec);
  Drivetrain.turn(left);
   wait(300,msec);
  Drivetrain.stop();
  Drivetrain.drive(forward);
  wait(1500,msec);
  Drivetrain.stop();
  
}
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // .........................................................................

 //autonomoalterno2();
 //movimientoGPS(10,10);
 autonomoSkills();
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
// VEXcode device constructors

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
      
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}