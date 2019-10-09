# Test file for Lab3_bitManip


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PIND: 0x01 => PORTC: 0x01" 
setPIND 0x01
continue 5
expectPORTC 0x01
checkResult

test "PIND: 0x02 => PORTC: 0x02" 
setPIND 0x02
continue 5
expectPORTC 0x02
checkResult

test "PIND: 0x03 => PORTC: 0x03" 
setPIND 0x03
continue 5
expectPORTC 0x03
checkResult

echo Completed function check. DA_COUNTA is working correctly.\n\n

test "PINA: 0x01, PIND: 0x00 => PORTC: 0x00, PORTB = 0x01"
setPINA 0x01
setPIND 0x00
continue 5
expectPORTC 0x00
expectPORTB 0x01
checkResult

test "PINA: 0x01, PIND: 0x02 => PORTC: 0x02, PORTB: 0x05"
setPINA 0x01
setPIND 0x02
continue
expectPORTC 0x02
expectPORTB 0x01
checkResult

test "PINA: 0x01, PIND: 0x03 => PORTC: 0x03, PORTB: 0x05"
setPINA 0x01
setPIND 0x03
continue
expectPORTC 0x03
expectPORTB 0x05
checkResult



# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
