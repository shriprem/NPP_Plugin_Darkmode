@ECHO OFF

SET PLATFORM=x64
SET SOURCE_DIR=Release\%PLATFORM%
SET DEST_DIR_1=..\FWDataViz\DM_includes\%PLATFORM%
SET DEST_DIR_2=..\Goto-Line-Col-NPP-Plugin\DM_includes\%PLATFORM%

COPY /Y %SOURCE_DIR%\NPP_Plugin_Darkmode.dll %DEST_DIR_1%\
COPY /Y %SOURCE_DIR%\NPP_Plugin_Darkmode.lib %DEST_DIR_1%\

COPY /Y %SOURCE_DIR%\NPP_Plugin_Darkmode.dll %DEST_DIR_2%\
COPY /Y %SOURCE_DIR%\NPP_Plugin_Darkmode.lib %DEST_DIR_2%\

EXIT 0
