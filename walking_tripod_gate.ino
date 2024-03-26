#include <Servo.h>

#define NUM_LEGS 6
#define NUM_SERVOS_PER_LEG 3
int general_delay =100;
// Pins for servos
const int servoPins[NUM_LEGS][NUM_SERVOS_PER_LEG] = {
  {24, 23, 22},   // Leg 1 servo pins (e.g., coxa, femur, tibia)
  {51, 52, 53},   // Leg 2 servo pins
  {44, 43, 42},   // Leg 3 servo pins
  {45, 46, 47},   // Leg 4 servo pins
  {30, 29, 28},   // Leg 5 servo pins
  {27, 26, 25}    // Leg 6 servo pins
};

// Predefined offsets for each servo
#define pos1 83   // coxa 1
#define pos2 93   // femur 1
#define pos3 83   // tibia 1
#define pos4 70   // coxa 2
#define pos5 90   // femur 2
#define pos6 85   // tibia 2
#define pos7 60   // c3
#define pos8 93   // f3
#define pos9 80   // t3
#define pos10 90  // c4 
#define pos11 103 // f4
#define pos12 75  // t4
#define pos13 95  // c5
#define pos14 95  // f5
#define pos15 77  // t5
#define pos16 90  // c6
#define pos17 95  // f6
#define pos18 103 // t6

Servo servos[NUM_LEGS][NUM_SERVOS_PER_LEG];
int offsets[NUM_LEGS][NUM_SERVOS_PER_LEG] = {
  {pos1, pos2, pos3}, // Leg 1 offsets
  {pos4, pos5, pos6}, // Leg 2 offsets
  {pos7, pos8, pos9}, // Leg 3 offsets
  {pos10, pos11, pos12}, // Leg 4 offsets
  {pos13, pos14, pos15}, // Leg 5 offsets
  {pos16, pos17, pos18}  // Leg 6 offsets
};

void setup() {
  attach();
  offset();
  delay(2000);

}

void attach() {
  // Attach servos to pins manually
  servos[0][0].attach(servoPins[0][0]);
  servos[0][1].attach(servoPins[0][1]);
  servos[0][2].attach(servoPins[0][2]);

  servos[1][0].attach(servoPins[1][0]);
  servos[1][1].attach(servoPins[1][1]);
  servos[1][2].attach(servoPins[1][2]);

  servos[2][0].attach(servoPins[2][0]);
  servos[2][1].attach(servoPins[2][1]);
  servos[2][2].attach(servoPins[2][2]);

  servos[3][0].attach(servoPins[3][0]);
  servos[3][1].attach(servoPins[3][1]);
  servos[3][2].attach(servoPins[3][2]);

  servos[4][0].attach(servoPins[4][0]);
  servos[4][1].attach(servoPins[4][1]);
  servos[4][2].attach(servoPins[4][2]);

  servos[5][0].attach(servoPins[5][0]);
  servos[5][1].attach(servoPins[5][1]);
  servos[5][2].attach(servoPins[5][2]);
}

void offset() {
  // Set the predefined offsets for each servo
  // Leg 1
  servos[0][0].write(pos1); // coxa 1
  servos[0][1].write(pos2); // femur 1
  servos[0][2].write(pos3); // tibia 1

  // Leg 2
  servos[1][0].write(pos4); // coxa 2
  servos[1][1].write(pos5); // femur 2
  servos[1][2].write(pos6); // tibia 2

  // Leg 3
  servos[2][0].write(pos7); // c3
  servos[2][1].write(pos8); // f3
  servos[2][2].write(pos9); // t3

  // Leg 4
  servos[3][0].write(pos10); // c4
  servos[3][1].write(pos11); // f4
  servos[3][2].write(pos12); // t4

  // Leg 5
  servos[4][0].write(pos13); // c5
  servos[4][1].write(pos14); // f5
  servos[4][2].write(pos15); // t5

  // Leg 6
  servos[5][0].write(pos16); // c6
  servos[5][1].write(pos17); // f6
  servos[5][2].write(pos18); // t6
}

void moveLegs135() {
  // Move legs 1, 3, and 5 to follow half square
  // Example: Move leg 1
  /*servos[0][1].write(pos2); // Adjust position as needed
  servos[2][1].write(pos8); 
  servos[4][1].write(pos14); 
  delay(general_delay);*/
  servos[0][1].write(pos2 - 30); 
// Adjust position as needed femur 
  servos[2][1].write(pos8 - 30);
 
  servos[4][1].write(pos14 - 30);
  delay(general_delay);

  // leg 135
  servos[0][0].write(pos1 - 20);//coxa  
    // clowise + //anti -
  servos[2][0].write(pos7 + 20);

  servos[4][0].write(pos13 - 20);
delay(general_delay);

// leg 246 //coxa
  servos[1][0].write(pos4 - 20);
  
  servos[3][0].write(pos10 + 20);
  
  servos[5][0].write(pos16 + 20);
delay(general_delay);

  //leg 135 femur down
  servos[0][1].write(pos2);

  servos[2][1].write(pos8);
 
  servos[4][1].write(pos14);
  delay(general_delay);


  // Similar adjustments for legs 3 and 5
}

void moveLegs246() {
  // Move legs 1, 3, and 5 to follow half square
  // Example: Move leg 1
 /* servos[1][1].write(pos5); // Adjust position as needed
  servos[3][1].write(pos11); 
  servos[5][1].write(pos17); 
  delay(general_delay);*/

//leg 246 
  servos[1][1].write(pos5 - 30 );
  // Adjust position as needed femur 
  servos[3][1].write(pos11 - 30);
 
  servos[5][1].write(pos17 - 30);
  delay(general_delay);

//leg 246
  servos[1][0].write(pos4 + 20);
  servos[3][0].write(pos10 - 20);
  servos[5][0].write(pos16 - 20);
delay(general_delay);
  //otherpair backward push 135 
  servos[0][0].write(pos1 + 20);//coxa 
  servos[2][0].write(pos7 - 20);
  servos[4][0].write(pos13 + 20);


 

 delay(general_delay);
  servos[1][1].write(pos5);
  servos[3][1].write(pos11);
  servos[5][1].write(pos17);
  delay(general_delay);
  

  // Similar adjustments for legs 3 and 5
}

  void loop() {
  // Move legs 1, 3, and 5 to follow half square

 moveLegs135();
  // Adjust delay as needed
  
   
  //Move legs 2, 4, and 6 to follow the same half square
 moveLegs246();

  // Adjust delay as needed
  //offset();
  //delay(500);
}


