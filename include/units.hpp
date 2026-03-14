#ifndef UNITS_H
#define UNITS_H

namespace units {

double grams_OZ(double grams);
double ozs_Gs(double ounces);
double oz_LB(double ounces);
double lb_kg(double pounds);
double gal_Lit(double gallons);
double quart_Lit(double quarts);
double pint_Lit(double pints);
double cups_mL(double cups);
double fozs_mL(double ounces);
double lit_Gal(double liters);
double mL_Fozs(double mL);
double inch_Cm(double inches);
double ft_M(double ft);
double m_Ft(double meters);
double yd_M(double yards);
double cm_In(double cm);
double mile_KM(double miles);
double inch_Ft(double inches);
double ft_In(double feet);
double sec_Min(double seconds);
double sec_Hour(double seconds);
double mins_Sec(double minutes);
double hours_Sec(double hours);
double miS_NanS(double miS);
double nanS_MiS(double nanS);
double sec_Ms(double seconds);
double ms_Sec(double ms);
double miS_Sec(double miS);
double ms_MicS(double ms);
double nanS_Sec(double nanS);
double watts_KW(double watts);
double kw_MW(double kW);
double kW_Hours(double watts, double hours);
double MW_Hours(double kW, double hours);
}

#endif
