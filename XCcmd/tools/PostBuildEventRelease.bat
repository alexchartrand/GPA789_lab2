rem Copie le fichier lib. 
rem
rem Il ne devrait pas y avoir de collistion avec le fichier debug puisque ce 
rem dernier a �t� renom� avec le suffixe _d pour debug.

echo.
echo Copying release library file ...
echo.

copy "..\x64\Release\XCcmd.exe" "..\bin\XCcmd_x64.exe"
rem copy "..\x64\Release\XtractCcmd.pdb" "..\bin\XtractCcmd_x64.pdb"
