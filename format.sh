# required: astyle

astyle --style=java addons/textmode/*.c
astyle --style=java addons/liballoc/*.c
astyle --style=java ctype/*.c
astyle --style=java kernel/*.c
astyle --style=java maths/*.c
astyle --style=java stdlib/*.c
astyle --style=java string/*.c

astyle --style=java include/*.h
astyle --style=java include/libfalcon/*.h

find . -name *.orig | xargs rm -f