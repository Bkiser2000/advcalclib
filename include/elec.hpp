#ifndef ELEC_H
#define ELEC_H

namespace elec {

double calculateParal_Resis(double* values, int count);

double calculateSeries_Resis(double* values, int count);

double power(double current, double voltage);

double voltage(double current, double resistance);

double current(double voltage, double resistance);

double resistance(double voltage, double current);

double capacitance(double permittivity, double area, double distance);

double impedance(double resistance, double reactance);

double conductance(double resistance);

double calculateCurrentFPV_SPAC(double power, double voltage, double powerFactor);

double calculateVoltageFPC_SPAC(double power, double current, double powerFactor);

double calculatePowerFVC_SPAC(double voltage, double current, double powerFactor);

double calculatePowerFIR_SPAC(double current, double resistance);

double calculatePowerFVR_SPAC(double voltage, double resistance);
}

#endif
