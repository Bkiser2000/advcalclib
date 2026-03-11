#include <iostream>
#include <calc.hpp>
#include <utils.hpp>

namespace units {

double grams_OZ(double grams) {
    if (grams <= 0) {
        std::cerr << "Mass cannot equal zero or be negative!";
        return utils::NAN();
    } else {
        double ozs = grams / 28.34952;
        return ozs;
    }
}

double ozs_Gs(double ounces) {
    if (ounces <= 0) {
        std::cerr << "Ounces cannot be zero or negative!";
        return utils::NAN();
    } else {
        double grams = ounces * 28.34952;
        return grams;
    }
}

double oz_LB(double ounces) {
    if (ounces <= 0) {
        std::cerr << "Ounces cannot be zero or negative!";
        return utils::NAN();
    } else {
        double lb = ounces / 16;
        return lb;
    }
}

double lb_kg(double pounds) {
    if (pounds <= 0) {
        std::cerr << "Pounds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double kg = pounds * 0.453592;
        return kg;
    }
}

double gal_Lit(double gallons) {
    if (gallons <= 0) {
        std::cerr << "Gallons cannot be zero or negative!";
        return utils::NAN();
    } else {
        double liters = gallons * 3.78541;
        return liters;
    }
}

double quart_Lit(double quarts) {
    if (quarts <= 0) {
        std::cerr << "Quarts cannot be zero or negative!";
        return utils::NAN();
    } else {
        double liters = quarts * 0.946353;
        return liters;
    }
}

double pint_Lit(double pints) {
    if (pints <= 0) {
        std::cerr << "Pints cannot be zero or negative!";
        return utils::NAN();
    } else {
        double liters = pints * 0.473176;
        return liters;
    }
}

double cups_mL(double cups) {
    if (cups <= 0) {
        std::cerr << "Cups cannot be zero or negative!";
        return utils::NAN();
    } else {
        double mL = cups * 236.588;
        return mL;
    }
}

double fozs_mL(double ounces) {
    if (ounces <= 0) {
        std::cerr << "Ounces cannot be zero or negative!";
        return utils::NAN();
    } else {
        double mL = ounces * 29.5735;
        return mL;
    }
}

double lit_Gal(double liters) {
    if (liters <= 0) {
        std::cerr << "Liters cannot be zero or negative!";
        return utils::NAN();
    } else {
        double gallons = liters * 0.264172;
        return gallons;
    }
}

double mL_Fozs(double mL) {
    if (mL <= 0) {
        std::cerr << "Milliliters cannot be zero or negative!";
        return utils::NAN();
    } else {
        double flOz = mL * 0.033814;
        return flOz;
    }
}

double inch_Cm(double inches) {
    if (inches <= 0) {
        std::cerr << "Inches cannot be zero or negative!";
        return utils::NAN();
    } else {
        double cm = inches * 2.54;
        return cm;
    }
}

double ft_M(double ft) {
    if (ft <= 0) {
        std::cerr << "Feet cannot be zero or negative!";
        return utils::NAN();
    } else {
        double m = ft * 0.3048;
        return m;
    }
}

double m_Ft(double meters) {
    if (meters <= 0) {
        std::cerr << "Inches cannot be zero or negative!";
        return utils::NAN();
    } else {
        double cm = inches * 2.54;
        return cm;
    }
}

double yd_M(double yards) {
    if (yards <= 0) {
        std::cerr << "Inches cannot be zero or negative!";
        return utils::NAN();
    } else {
        double m = yards * 0.9144;
        return m;
    }
}

double cm_In(double cm) {
    if (cm <= 0) {
        std::cerr << "Centimeters cannot be zero or negative!";
        return utils::NAN();
    } else {
        double inches = cm * 0.393701;
        return inches;
    }
}


double mile_KM(double miles) {
    if (miles <= 0) {
        std::cerr << "Miles cannot be zero or negative!";
        return utils::NAN();
    } else {
        double km = miles * 1.60934;
        return km;
    }
}

double inch_Ft(double inches) {
    if (inches <= 0) {
        std::cerr << "Inches cannot be zero or negative!";
        return utils::NAN();
    } else {
        double ft = inches / 12;
        return ft;
    }
}

double ft_In(double feet) {
    if (feet <= 0) {
        std::cerr << "Feet cannot be zero or negative!";
        return utils::NAN();
    } else {
        double inches = feet * 12;
        return inches;
    }
}

double sec_Min(double seconds) {
    if (seconds <= 0) {
        std::cerr << "Seconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double minutes = seconds / 60;
        return minutes;
    }
}

double sec_Hour(double seconds) {
    if (seconds <= 0) {
        std::cerr << "Seconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double hours = seconds / 3600;
        return hours;
    }
}

double mins_Sec(double minutes) {
    if (minutes <= 0) {
        std::cerr << "Minutes cannot be zero or negative!";
        return utils::NAN();
    } else {
        double seconds = minutes * 60;
        return seconds;
    }
}

double hours_Sec(double hours) {
    if (hours <= 0) {
        std::cerr << "Hours cannot be zero or negative!";
        return utils::NAN();
    } else {
        double seconds = hours * 3600;
        return seconds;
    }
}

double miS_NanS(double miS) {
    if (miS <= 0) {
        std::cerr << "Microseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double nanoS = miS * 1000;
        return nanoS;
    }
}

double nanS_MiS(double nanS) {
    if (nanS <= 0) {
        std::cerr << "Nanoseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double microS = nanS * 0.001;
        return microS;
    }
}

double sec_Ms(double seconds) {
    if (seconds <= 0) {
        std::cerr << "Seconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double ms = seconds * 1000;
        return ms;
    }
}

double ms_Sec(double ms) {
    if (ms <= 0) {
        std::cerr << "Milliseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double seconds = ms * 0.001;
        return seconds;
    }
}

double miS_Sec(double miS) {
    if (miS <= 0) {
        std::cerr << "Microseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double seconds = miS * 0.000001;
        return seconds;
    }
}

double ms_MicS(double ms) {
    if (ms <= 0) {
        std::cerr << "Milliseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double microS = ms * 1000;
        return microS;
    }
}

double nanS_Sec(double nanS) {
    if (nanS <= 0) {
        std::cerr << "Nanoseconds cannot be zero or negative!";
        return utils::NAN();
    } else {
        double seconds = nanS * 0.000000001;
        return seconds;
    }
}

double watts_KW(double watts) {
    if (watts <= 0) {
        std::cerr << "Watts cannot be zero or negative!";
        return utils::NAN();
    } else {
        double kW = watts / 1000;
        return kW;
    }
}

double kw_MW(double kW) {
    if (kW <= 0) {
        std::cerr << "Kilowatts cannot be zero or negative!";
        return utils::NAN();
    } else {
        double mW = kW / 1000;
        return kW;
    }
}

double kW_Hours(double watts, double hours) {
    if (watts <= 0 && hours <= 0) {
        std::cerr << "Watts/hours cannot be zero or negative!";
        return utils::NAN();
    } else {
        double kW_H = watts_KW(watts) / hours;
        return kW_H;
    }
}

double MW_Hours(double kW, double hours) {
    if (kW <= 0 && hours <= 0) {
        std::cerr << "Watts cannot be zero or negative!";
        return utils::NAN();
    } else {
        double mW_H = (kW / 1000) / hours;
        return mW_H;
    }
}
}
