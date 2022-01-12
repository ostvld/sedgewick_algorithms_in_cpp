# !bin/bash

if ! [ -d ./build ]; then
mkdir ./build
fi

if ! [ -d ./build ]; then
echo "./build not found."
exit
else
echo "./build found."
fi

# ~/Qt/Tools/CMake/bin/cmake -G "Unix Makefiles" -D CMAKE_CXX_FLAGS="-g -O2 -w -fprofile-arcs -ftest-coverage" -D CMAKE_C_FLAGS="-g -O2 -w -fprofile-arcs -ftest-coverage" CMAKE_CODEBLOCKS_MAKE_ARGUMENTS=-j8 -S ./ -B ./build
~/Qt/Tools/CMake/bin/cmake -G "Unix Makefiles" CMAKE_CODEBLOCKS_MAKE_ARGUMENTS=-j8 -S ./ -B ./build
cd build
~/Qt/Tools/CMake/bin/cmake --build . --target all

./server_tests/server_tests
./server/run_server & pidof run_server
pidof run_server | echo
#read
./client_tests/client_tests
./qttest/qttest
./qttest/qttest1

# cd ./server/CMakeFiles/server.dir/src/
SERVERPID="$(pidof run_server)"
echo $SERVERPID
#read
kill -9 $SERVERPID
#read
cd ..

if ! [ -d ./doc ]; then
mkdir ./doc
else
rm -fr ./doc/*
fi

if ! [ -d ./doc ]; then
echo "./doc not found."
exit
else
echo "./doc found."
fi

doxygen ./Doxyfile

if ! [ -d ./coverage ]; then
mkdir ./coverage
else
rm -fr ./coverage/*
fi

if ! [ -d ./coverage ]; then
echo "./coverage not found."
exit
else
echo "./coverage found."
fi


#pipenv run gcovr -r . --filter 'server/' --filter 'client/' --html-details -o ./coverage/report.html

#firefox ./coverage/report.html &
xdg-open ./doc/html/index.html &
# lcov --external --remove test.info "/usr*" "*include/gtest*" "*/src/gtest*" -o test.info -d . > lcov.log

# echo "lcov done"

# pwd
# ls ./

# cur_date=$(date +%Y_%m_%d-%H_%M_%S)
# genhtml -o ./$cur_date test.info
# echo "genhtml done"
