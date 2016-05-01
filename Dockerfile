FROM centos:7
MAINTAINER Robert Anderson <r-anderson.9@onu.edu>

COPY ./src /src
RUN curl -SL https://github.com/google/googletest/archive/release-1.7.0.tar.gz \
    | tar -zxvC /usr/local/include \
    && mv /usr/local/include/googletest-release-1.7.0 /usr/local/include/gtest
RUN yum install -y gcc gcc-c++ make
