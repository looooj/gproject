set TCC_APP=..\..\third_party\tcc\tcc

%TCC_APP% sleep.c
%TCC_APP% -luser32 sendkey.c
pause


