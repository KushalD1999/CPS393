!/bin/bash
clear
find /usr/courses/cps393/dwoit/courseNotes/ \( -name  "*.h"  -and  ! -name "*t*" \) -group "cps393" -atime -75 2>/dev/null -ls
exit=0 
