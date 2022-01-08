FROM ubuntu:21.04

# switch to root
USER root

# install a few tools for more convenient developing
RUN apt-get update -y --fix-missing&& \
    apt-get -y upgrade && \
    apt-get clean

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Zurich
RUN apt-get install -y tzdata

RUN apt-get -y install git cmake build-essential ccache gdb curl bash-completion vim clang-11 clang-tidy-11 clang-format-11  \
    libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev

