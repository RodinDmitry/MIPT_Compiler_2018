 .386
 .model flat, stdcall
option casemap:none

includelib kernel32.lib
include /masm32/include/windows.inc
include /masm32/include/kernel32.inc
include /masm32/include/masm32rt.inc

 .const

sConsoleTitle db 'Test',0
sWriteText db 'Sample text'
newLine db 10, 13

.data 

myvar db 52, 0

 .code

print_num PROC var:DWORD

   invoke StdOut, str$(var)
   invoke StdOut, offset newLine
   ret 0

print_num ENDP

main PROC
  invoke SetConsoleTitle, offset sConsoleTitle

  invoke print_num, 442
  invoke ExitProcess, NULL
  ret 0
main ENDP

end main