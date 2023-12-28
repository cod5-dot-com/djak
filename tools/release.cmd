@echo off
pushd "%~dp0"

if exist jack-win32\ (
	rmdir /s /q jack-win32
)
if exist jack-win64\ (
	rmdir /s /q jack-win64
)
if exist jack-win32.zip (
	del jack-win32.zip
)
if exist jack-win64.zip (
	del jack-win64.zip
)

mkdir jack-win32
mkdir jack-win64
copy Release\jack.exe jack-win32\
copy x64\Release\jack.exe jack-win64\
copy README.md jack-win32\
copy LICENSE.txt jack-win32\
copy README.md jack-win64\
copy LICENSE.txt jack-win64\

powershell Compress-Archive "jack-win32"  "jack-win32.zip"
powershell Compress-Archive "jack-win64" "jack-win64.zip"

:exit
popd
@echo on

