FROM gcc:7.3.0

RUN apt-get -qq update
RUN apt-get -qq upgrade

# cpp libs
RUN apt-get -qq install libboost-all-dev=1.62.0.1

# cpp tools
RUN apt-get -qq install build-essential
RUN apt-get -qq install cmake
RUN apt-get -qq install remake
RUN apt-get -qq install valgrind
RUN apt-get -qq install cppcheck
RUN apt-get -qq install clang-format-7

# plant-uml tools
RUN apt-get -qq install openjdk-8-jre
RUN apt-get -qq install graphviz

# usr
RUN apt-get -qq install vim
RUN apt-get -qq install sudo
RUN apt-get -qq install zsh
# RUN useradd -ms /usr/bin/zsh dev
# USER dev
