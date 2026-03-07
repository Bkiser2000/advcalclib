#include <iostream>
#include "elec.hpp"
#include "calc.hpp"

namespace elec {

double power(double current, double voltage) {
    double watts;
    if (current > 0 && voltage > 0) {
        watts = current * voltage;
        //std::cout << "Power: " << power << " W" << std::endl;
        return watts;
    } else {
        std::cerr << "Error: Current and voltage must be positive!" << "\n";
        return -1;
    }
}

double voltage(double current, double resistance) {
    double volts;
    if (current > 0 && resistance > 0) {
        volts = current * resistance;
        //std::cout << "Voltage: " << voltage << " V\n";
        return volts;
    } else {
        std::cerr << "Error: Current and resistance must be positive!" << "\n";
        return -1;
    }
}

double current(double voltage, double resistance) {
    double amps;
    if (voltage > 0 && resistance > 0) {
        amps = voltage / resistance;
        //std::cout << "Current: " << amps << " A" << std::endl;
        return amps;
    } else {
        std::cerr << "Error: Voltage and resistance must be positive!" << std::endl;
        return -1;
    }
}

double calculatePowerFactor(double realPower, double apparentPower) {
    double powerFactor;
    if (realPower > 0 && apparentPower > 0) {
        powerFactor = realPower / apparentPower;
        //std::cout << "Power Factor: " << powerFactor << "\n";
        return powerFactor;
    } else {
        std::cerr << "Error: Real power and apparent power must be positive!" << "\n";
        return -1;
    }
}

double calculateCurrentFPV_SPAC(double power, double voltage, double powerFactor) {
    double current;
    if (power > 0 && voltage > 0 && powerFactor >= 0) {
        current = power / (voltage * powerFactor);
        //std::cout << "Current: " << current << "A" << std::endl;
        return current;
    } else {
        std::cerr << "Error: Power, voltage, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculateVoltageFPC_SPAC(double power, double current, double powerFactor) {
    double voltage;
    if (power > 0 && current > 0 && powerFactor >= 0) {
        voltage = power / (current * powerFactor);
        //std::cout << "Voltage: " << voltage << "V" << std::endl;
        return voltage;
    } else {
        std::cerr << "Error: Power, current, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculatePowerFVC_SPAC(double voltage, double current, double powerFactor) {
    double power;
    if (voltage > 0 && current > 0 && powerFactor >= 0) {
        power = voltage * current * powerFactor;
        //std::cout << "Power: " << power << "W" << std::endl;
        return power;
    } else {
        std::cerr << "Error: Voltage, current, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculatePowerFIR_SPAC(double current, double resistance) {
    double power;
    if (current > 0 && resistance > 0) {
        power = calc::expo(current, 2) * resistance;
        //std::cout << "Power: " << power << "W" << std::endl;
        return power;
    } else {
        std::cerr << "Error: Current and resistance must be positive!" << std::endl;
        return -1;
    }
}

double calculatePowerFVR_SPAC(double voltage, double resistance) {
    double power;
    if (voltage > 0 && resistance > 0) {
        power = calc::expo(voltage, 2) / resistance;
        //std::cout << "Power: " << power << "W" << std::endl;
        return power;
    } else {
        std::cerr << "Error: Voltage and resistance must be positive!" << std::endl;
        return -1;
    }
}

double calculateCurrentFPV_TPAC(double power, double voltage, double powerFactor) {
    double current;
    if (power > 0 && voltage > 0 && powerFactor >= 0) {
        current = power / (calc::squrt(3) * voltage * powerFactor);
        //std::cout << "Current: " << current << "A" << std::endl;
        return current;
    } else {
        std::cerr << "Error: Power, voltage, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculateVoltageFPC_TPAC(double power, double current, double powerFactor) {
    double voltage;
    if (power > 0 && current > 0 && powerFactor >= 0) {
        voltage = power / (calc::squrt(3) * current * powerFactor);
        return voltage;
    } else {
        std::cerr << "Error: Power, current, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculateTotalPower_TPAC(double phaseVoltage, double lineCurrent, double powerFactor) {
    double power;
    if (phaseVoltage > 0 && lineCurrent > 0 && powerFactor >= 0) {
        power = calc::squrt(3) * phaseVoltage * lineCurrent * powerFactor;
        return power;
    } else {
        std::cerr << "Error: Voltage, current, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculatePhasePower_TPAC(double phaseVoltage, double phaseCurrent, double powerFactor) {
    double power;
    if (phaseVoltage > 0 && phaseCurrent > 0 && powerFactor >= 0) {
        power = 3 * phaseVoltage * phaseCurrent * powerFactor;
        return power;
    } else {
        std::cerr << "Error: Voltage, current, and power factor must be positive!" << std::endl;
        return -1;
    }
}

double calculateWyeLineVoltage(double phaseVoltage) {
    double lineVoltage;
    if (phaseVoltage > 0) {
        lineVoltage = phaseVoltage * calc::squrt(3);
        return lineVoltage;
    } else {
        std::cerr << "Error: Phase voltage must be positive!" << std::endl;
        return -1;
    }
}

double calculateWyePhaseVoltage(double lineVoltage) {
    double phaseVoltage;
    if (lineVoltage > 0) {
        phaseVoltage = lineVoltage / calc::squrt(3);
        return phaseVoltage;
    } else {
        std::cerr << "Error: Line voltage must be positive!" << std::endl;
        return -1;
    }
}

double calculateDeltaLineCurrent(double phaseCurrent) {
    double lineCurrent;
    if (phaseCurrent > 0) {
        lineCurrent = phaseCurrent * calc::squrt(3);
        return lineCurrent;
    } else {
        std::cerr << "Error: Phase current must be positive!" << std::endl;
        return -1;
    }
}

double calculateDeltaPhaseCurrent(double lineCurrent) {
    double phaseCurrent;
    if (lineCurrent > 0) {
        phaseCurrent = lineCurrent / calc::squrt(3);
        return phaseCurrent;
    } else {
        std::cerr << "Error: Line current must be positive!" << std::endl;
        return -1;
    }
}

double resistance(double voltage, double current) {
    double resistance;
    if (voltage > 0 && current > 0) {
        resistance = voltage / current;
        return resistance;
    } else {
        std::cerr << "Error: Voltage and current must be positive!" << std::endl;
        return -1;
    }
}

double conductance(double resistance) {
    double conductance;
    if (resistance > 0) {
        conductance = 1 / resistance;
        return conductance;
    } else {
        std::cerr << "Error: Resistance must be positive!" << "\n";
        return -1;
    }
}

double impedance(double resistance, double reactance) {
    double impedance;
    if (resistance > 0 && reactance > 0) {
        impedance = calc::squrt(calc::expo(resistance, 2) + calc::expo(reactance, 2));
        return impedance;
    } else {
        std::cerr << "Error: Resistance and reactance must be positive!" << "\n";
        return -1;
    }
}

double capacitance(double permittivity, double area, double distance) {
    double capacitance;
    if (permittivity > 0 && area > 0 && distance > 0) {
        capacitance = (permittivity * area) / distance;
        return capacitance;
    } else {
        std::cerr << "Error: Permittivity, area, and distance must be positive!" << "\n";
        return -1;
    }
}

double calculateParal_Resis(double* values, int count) {
    double paralResist = values[0];
    double reciprocal_sum = 0.0;
    for (int i = 0; i < count; i++) {
        if (values[i] > 0) {
            reciprocal_sum += 1.0 / values[i];
        } else {
            std::cerr << "Error: Resistance cannot be zero or negative!" << "\n";
            return -1;
        }
    }
    paralResist = 1.0 / reciprocal_sum;
    return paralResist;
}

double calculateSeries_Resis(double* values, int count) {
    double seriesResist = values[0];
    double series_sum = 0.0;
    for (int i = 0; i < count; i++) {
        if (values[i] > 0) {
            series_sum += values[i];
        } else {
            std::cerr << "Error: Resistance cannot be zero or negative!" << "\n";
            return -1;
        }
    }
    seriesResist = series_sum;
    return seriesResist;
}

double calculateInduction(double turns, double magneticFlux, double timeChange) {
    if (turns > 0 && magneticFlux > 0 && timeChange > 0) {
        double emf = (turns * magneticFlux) / timeChange;
        return emf;
    } else {
        std::cerr << "Error: Turns, magnetic flux, and time change must be positive!" << "\n";
        return -1;
    }
}
}

