# required: astyle

astyle --style=java hooks/textmode/*.c
astyle --style=java ctype/*.c
astyle --style=java include/*.h
astyle --style=java kernel/*.c
astyle --style=java maths/*.c
astyle --style=java stdlib/*.c
astyle --style=java string/*.c

find . -name *.orig | xargs rm -f