#include <iostream>
#include <physics.hpp>
#include <calc.hpp>

namespace physics {

double calculateGrav_Force(double Mass1, double Mass2, double dist) {
    if (Mass1 <= 0 || Mass2 <= 0 || dist <= 0) {
        std::cerr << "Error: Mass and distance must be positive!" << "\n";
        return -1;
    }
    const double GRAV_CONST = 6.674e-11;
    double gravForce;
    gravForce = (GRAV_CONST * Mass1 * Mass2) / (dist * dist);
    //cout << "The gravitational force between these two objects is: " << gravForce << "N\n";
    return gravForce;
} 

double calculateVelocity(double Dist, double Time) {
    if (Time <= 0 && Dist <= 0) {
        std::cerr << "Error: Time and distance must be positive!" << "\n";
        return -1;
    }
    double velocity;
    velocity = Dist / Time;
    //cout << "Velocity: " << velocity << " m/s\n";
    return velocity;
}

double calculateKin_Eng(double Mass, double Velocity) {
    if (Mass <= 0 || Velocity <= 0) {
        std::cerr << "Error: Mass and velocity must be positive!" << "\n";
        return -1;
    }
    double kinEng;
    kinEng = 0.5 * Mass * calc::expo(Velocity, 2);
    //cout << "Kinetic Energy: " << kinEng << " J\n";
    return kinEng;
}

double calculateHeat_Trans(double Mass, double specHeat, double tempChange) {
    if (Mass <= 0 || specHeat <= 0) {
        std::cerr << "Error: Mass and specific heat must be positive!" << "\n";
        return -1;
    }
    double heatTrans;
    heatTrans = Mass * specHeat * tempChange;
    //cout << "Heat Transferred: " << heatTrans << " J\n";
    return heatTrans;
}

double calculateIdeal_GasLaw(double Press, double Volume, double Moles, double Temp) {
    const double gasConst = 8.314;
    if (Volume <= 0 || Moles <= 0 || Temp <= 0) {
        std::cerr << "Error: Volume, moles, gas constant, and temperature must be positive!" << "\n";
        return -1;
    }
    double idealGasLaw;
    idealGasLaw = (Press * Volume) == (Moles * gasConst * Temp);
    //cout << "Ideal Gas Law Result: " << idealGasLaw << "\n";
    return idealGasLaw;
}

double density(double Mass, double Volume) {
    double density;
    if (Volume > 0 && Mass > 0) {
        density = Mass / Volume;
        //cout << "Density: " << density << " kg/m^3\n";
        return density; 
    } else {
        std::cerr << "Error: Mass/Volume cannot be zero or negative!" << "\n";
        return -1;
    }
}

double calculateForce(double Mass, double Accel) {
    if (Mass > 0 && Accel > 0) {
        double force = Mass * Accel;
        //cout << "Force: " << force << "\n";
        return force;
    } else {
        std::cerr << "Error: Mass and/or acceleration cannot be zero or negative!" << "\n";
        return -1;
    }
}

double calculatePot_Eng(double Mass, double Gravity, double Height) {
    double potentEng;
    if (Mass > 0 && Gravity > 0 && Height > 0) {
        potentEng = Mass * Gravity * Height;
        //cout << "Potential Energy: " << potentEng << "\n";
        return potentEng;
    } else {
        std::cerr << "Error: Mass/Gravity/Height cannot be zero or negative!";
        return -1;
    }
}

double idealGasLaw_SolveVolume(double Press, double Moles, double Temp) {
    const double gasConst = 8.314;
    if (Press <= 0 || Moles <= 0 || Temp <= 0) {
        std::cerr << "Error: Pressure, moles, and temperature must be positive!" << "\n";
        return -1;
    }
    double volume;
    volume = (Moles * gasConst * Temp) / Press;
    //cout << "Volume: " << volume << " m^3\n";
    return volume;
}

double idealGasLaw_SolvePressure(double Volume, double Moles, double Temp) {
    const double gasConst = 8.314;
    if (Volume <= 0 || Moles <= 0 || Temp <= 0) {
        std::cerr << "Error: Volume, moles, and temperature must be positive!" << "\n";
        return -1;
    }
    double pressure;
    pressure = (Moles * gasConst * Temp) / Volume;
    //cout << "Pressure: " << pressure << " Pa\n";
    return pressure;
}

double idealGasLaw_SolveMoles(double Press, double Volume, double Temp) {
    const double gasConst = 8.314;
    if (Press <= 0 || Volume <= 0 || Temp <= 0) {
        std::cerr << "Error: Pressure, volume, and temperature must be positive!" << "\n";
        return -1;
    }
    double moles;
    moles = (Press * Volume) / (gasConst * Temp);
    //cout << "Moles: " << moles << " mol\n";
    return moles;
}

double idealGasLaw_SolveTemp(double Press, double Volume, double Moles) {
    const double gasConst = 8.314;
    if (Press <= 0 || Volume <= 0 || Moles <= 0) {
        std::cerr << "Error: Pressure, volume, and moles must be positive!" << "\n";
        return -1;
    }
    double temp;
    temp = (Press * Volume) / (Moles * gasConst);
    //cout << "Temperature: " << temp << " K\n";
    return temp;
}

double calculateEnergy(double Mass) {
    const double speedOfLight = 299792458;
    if (Mass > 0) {
        double energy = Mass * calc::expo(speedOfLight, 2);
        //cout << "Energy: " << energy << " J\n";
        return energy;
    } else {
        std::cerr << "Error: Mass must be positive!" << "\n";
        return -1;
    }
}

double coulomb(double Charge1, double Charge2, double Dist) {
    const double COULOMB_CONST = 8.988e9;
    if (Charge1 > 0 && Charge2 > 0 && Dist > 0) {
        double force = (COULOMB_CONST * Charge1 * Charge2) / calc::expo(Dist, 2);
        //cout << "Coulomb Force: " << force << " N\n";
        return force;
    } else {
        std::cerr << "Error: Charges and distance must be positive!" << "\n";
        return -1;
    }
}

double electricField_TestCharge(double Force, double Magnitude) {
    if (Force > 0 && Magnitude > 0) {
        double field = Force / Magnitude;
        //cout << "Electric Field: " << field << " N/C\n";
        return field;
    } else {
        std::cerr << "Error: Charge and distance must be positive!" << "\n";
        return -1;
    }
}

double electricField_PointCharge(double Charge, double Dist) {
    const double COULOMB_CONST = 8.988e9;
    if (Charge > 0 && Dist > 0) {
        double field = (COULOMB_CONST * Charge) / calc::expo(Dist, 2);
        //cout << "Electric Field: " << field << " N/C\n";
        return field;
    } else {
        std::cerr << "Error: Charge and distance must be positive!" << "\n";
        return -1;
    }
}
}