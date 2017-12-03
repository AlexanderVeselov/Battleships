@echo off
echo ===================Starting GUI===================
echo ==================================================

call zConfig.bat

zStartGUI.bat %PathToJava% %ServerIP% %HandlingPort%
