 .386
 .model flat,stdcall
option casemap:none

includelib kernel32.lib
include windows.inc
include \masm32\include\kernel32.inc

 .const

sConsoleTitle db 'My First Console Application',0
sWriteText db 'hEILo, Wo(R)LD!!'

 .code

Main PROC
  LOCAL hStdout :DWORD

  invoke SetConsoleTitle, offset sConsoleTitle
  invoke GetStdHandle, STD_OUTPUT_HANDLE
  mov hStdout,EAX
  invoke WriteConsole, hStdout, offset sWriteText, 16d, NULL, NULL
  invoke Sleep, 2000d
  invoke ExitProcess, NULL

Main ENDP

end Main