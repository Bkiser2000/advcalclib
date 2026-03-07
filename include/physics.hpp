#ifndef PHYSICS_H
#define PHYSICS_H

namespace physics {

double calculateGrav_Force(double Mass1, double Mass2, double Dist);

double calculateForce(double Mass, double Accel);

double calculateVelocity(double Dist, double Time);

double calculateKin_Eng(double Mass, double Velocity);

double calculatePot_Eng(double Mass, double Gravity, double Height);

double calculateIdeal_GasLaw(double Press, double Volume, double Moles, double Temp);

double idealGasLaw_SolveVolume(double Press, double Moles, double Temp);

double idealGasLaw_SolvePressure(double Volume, double Moles, double Temp);

double idealGasLaw_SolveMoles(double Press, double Volume, double Temp);

double idealGasLaw_SolveTemp(double Press, double Volume, double Moles);

double calculateHeat_Trans(double Mass, double specHeat, double tempChange);

double density(double Mass, double Volume);

extern double tempChange;

extern double Press;

extern double Dist;
}

#endif
