with Ada.Text_IO; use Ada.Text_IO;
with Interfaces.C;
with advcalc;

procedure proj is
   A, B, C : Integer;
   D : Integer := 20;
   type Matrix_Arr is array (Positive range <>, Positive range <>) of Float;

function exarr(Index : Integer) return Integer is
   E : array(1..5) of Integer := (2, 4, 6, 8, 10);
begin
   Put_Line("Element at Index " & Integer'Image(index) &  ": " & Integer'Image(E(Index)));
   return E(index);
end exarr;

function matrix(Rows, Cols : Positive) return Matrix_Arr is
   M : Matrix_Arr(1 .. Rows, 1 .. Cols);
begin
   for i in M'Range(1) loop
      for j in M'Range(2) loop
         M(i,j) := 0.0;
      end loop;
   end loop;
   return M;
end matrix;

procedure Print(M : Matrix_Arr) is
begin
   for R in M'Range(1) loop
      for C in M'Range(2) loop
         Ada.Text_IO.Put(Float'Image(M(R, C)) & " ");
      end loop;
      New_Line;
   end loop; 
end Print;

begin
   A := Integer'Value (Get_Line);
   B := Integer'Value (Get_Line); 
   C := A + B;

   if C = 0 then
      Put_line ("Result is 0");
   elsif C > 0 then
      Put_Line ("Positive Result :" & Integer'Image (C));
   else
      Put_Line ("Negative Result :" & Integer'Image (C));
   end if;
   D := exarr(1);
   D := exarr(3);

   declare
      E : Matrix_Arr := matrix(3, 5);
   begin
      E(1,1) := 4.20;
      E(1,2) := 6.9;
      E(1,3) := 3.6;
      E(1,4) := 2.4;
      E(1,5) := 5.2;
      E(2,3) := 7.5;
      Print(E);
   end;
end proj;