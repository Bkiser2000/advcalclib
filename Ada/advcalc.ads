with Interfaces.C;

package Advcalc is
   use Interfaces.C;

   -- ========== BASIC ARITHMETIC ==========
   
   function Add(num1 : double; num2 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc3addEdd";

   function Subtract(num1 : double; num2 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc3subEdd";

   function Multiply(num1 : double; num2 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc4multEdd";

   function Divide(num1 : double; num2 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc3divEdd";

   -- ========== EXPONENTS & ROOTS ==========
   
   function Exponent(num1 : double; num2 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc4expoEdd";

   function Square_Root(num1 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc5squrtEd";

   function Cube_Root(num1 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc5cubrtEd";

   function Factorial(num1 : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc4factEd";

   function Natural_Log(value : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc3logEd";

   -- ========== TEMPERATURE CONVERSIONS ==========
   
   function Celsius_To_Fahrenheit(c_temp : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc9degrees_FEd";

   function Fahrenheit_To_Celsius(f_temp : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc9degrees_CEd";

   function Fahrenheit_To_Kelvin(f_temp : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc4FtoKEd";

   function Celsius_To_Kelvin(c_temp : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN4calc4CtoKEd";

   function Feet_To_Meters(ft : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units4ft_MEd";

   function Meters_To_Feet(meters : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units4m_FtEd";

   function Yards_To_Meters(yards : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units4yd_MEd";
   
   function Cent_To_Inches(cm : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units5cm_InEd";

   function Feet_To_Inches(feet : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units5ft_InEd";

   function KW_To_MW(kW : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units5kw_MWEd";

   function Lbs_To_Kg(pounds : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units5lb_kgEd";

   function Ozs_To_Lbs(ounces : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units5oz_LBEd";

   function Ms_To_Secs(ms : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units6ms_SecEd";

   function Ozs_To_Gs(ounces : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units6ozs_GsEd";

   function Sec_To_Ms(seconds : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units6sec_MsEd";

   function Cups_To_ML(cups : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7cups_mLEd";

   function FlOzs_To_ML(ounces : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7fozs_mLEd";

   function Gallons_To_Lit(gallons : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7gal_LitEd";
   
   function Inches_To_Cm(inches : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7inch_CmEd";

   function Inches_To_Feet(inches : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7inch_FtEd";

   function Lit_To_Gallons(liters : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7lit_GalEd";

   function Miles_To_Km(miles : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7mile_KMEd";

   function MicroSec_To_Sec(miS : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7miS_SecEd";

   function ML_To_FlOzs(mL : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7mL_FozsEd";

   function MilliSec_To_Microsec(ms : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7ms_MicSEd";

   function MicroSec_To_Sec(miS : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7miS_SecEd";

   function Sec_To_Min(seconds : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7sec_MinEd";

   function Grams_To_Ozs(grams : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units8grams_OZEd";

   function KW_Hours(watts : double; hours : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units7miS_SecEd";

   function Mins_To_Sec(minutes : double) return double
      with Import => True,
           Convention => C,
           External_Name => "_ZN5units8mins_SecEd";


end Advcalc;
