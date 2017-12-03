@echo off
echo ===================Starting GUI===================
echo ==================================================

call zConfig.bat

zStartGUI.bat %PathToJava% %1 %HandlingPort%

