with Ada.Text_IO; use Ada.Text_IO;
with Ada.Strings; 
with Ada.Strings.Fixed;
with Interfaces.C;
with Advcalc;

procedure Calc is
   use Interfaces.C;
   use Advcalc;

   result : double;

    -- ========== FORMATTING FUNCTION ==========
   function Format_Double (value : double; decimal_places : Integer := 2) return String is
      package Double_IO is new Ada.Text_IO.Float_IO(double);
      output : String(1..20);
   begin
      Double_IO.Put(output, value, Exp => 0, Aft => decimal_places);
      return Ada.Strings.Fixed.Trim(output, Ada.Strings.Both);
   end Format_Double;

begin
   Put_Line("=========================================");
   Put_Line("  CALC.HPP Ada Interface Test");
   Put_Line("=========================================");
   New_Line;

   -- ========== BASIC ARITHMETIC ==========
   Put_Line("--- Basic Arithmetic ---");
   
   result := Add(10.5, 5.3);
   Put_Line("Add(10.5, 5.3) = " & Format_Double(result, 2));
   
   result := Subtract(10.5, 5.3);
   Put_Line("Subtract(10.5, 5.3) = " & Format_Double(result, 2));
   
   result := Multiply(10.5, 5.3);
   Put_Line("Multiply(10.5, 5.3) = " & Format_Double(result, 2));
   
   result := Divide(10.5, 5.3);
   Put_Line("Divide(10.5, 5.3) = " & Format_Double(result, 2));
   
   New_Line;

   -- ========== EXPONENTS & ROOTS ==========
   Put_Line("--- Exponents & Roots ---");
   
   result := Exponent(2.0, 8.0);
   Put_Line("Exponent(2.0, 8.0) = " & Format_Double(result, 0) & " (2^8)");
   
   result := Square_Root(16.0);
   Put_Line("Square_Root(16.0) = " & Format_Double(result, 2));
   
   result := Cube_Root(27.0);
   Put_Line("Cube_Root(27.0) = " & Format_Double(result, 4));
   
   result := Factorial(5.0);
   Put_Line("Factorial(5.0) = " & Format_Double(result, 0));
   
   result := Natural_Log(2.718281828);
   Put_Line("Natural_Log(e) = " & Format_Double(result, 4) & " (should be ~1.0)");
   
   New_Line;

   -- ========== TEMPERATURE CONVERSIONS ==========
   Put_Line("--- Temperature Conversions ---");
   
   result := Celsius_To_Fahrenheit(0.0);
   Put_Line("0°C to Fahrenheit = " & Format_Double(result, 2) & "°F (should be 32)");
   
   result := Fahrenheit_To_Celsius(32.0);
   Put_Line("32°F to Celsius = " & Format_Double(result, 2) & "°C (should be 0)");
   
   result := Celsius_To_Kelvin(0.0);
   Put_Line("0°C to Kelvin = " & Format_Double(result, 2) & "K (should be 273.15)");
   
   result := Celsius_To_Kelvin(25.0);
   Put_Line("25°C to Kelvin = " & Format_Double(result, 2) & "K (should be 298.15)");
   
   result := Fahrenheit_To_Kelvin(32.0);
   Put_Line("32°F to Kelvin = " & Format_Double(result, 2) & "K (should be 273.15)");
   
   Put_Line("=========================================");
   Put_Line("All tests completed successfully!");
   Put_Line("=========================================");

end Calc;