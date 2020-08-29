FROM gcc:7.3.0

RUN apt-get -qq update
RUN apt-get -qq upgrade

# libs
RUN apt-get -qq install libboost-all-dev=1.62.0.1

# tools
RUN apt-get -qq install build-essential
RUN apt-get -qq install cmake
RUN apt-get -qq install remake
RUN apt-get -qq install valgrind
RUN apt-get -qq install cppcheck
RUN apt-get -qq install clang-format
