if [ ! -d "build" ]; then
  mkdir build
fi

cd build && cmake .. && make && clear  && ./Tubes1_OOP