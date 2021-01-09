FROM ubuntu:20.10

# Install and setup build tools.
RUN apt-get update && apt-get install -y \
    binutils-mips-linux-gnu \
    python3 \
    git \
    golang \
    curl \
    gnupg

RUN mkdir /go
ENV GOPATH /go
ENV PATH $PATH:/go/bin

# https://gitlab.com/cznic/golex
RUN go get modernc.org/golex
# https://gitlab.com/cznic/goyacc
RUN go get modernc.org/goyacc

# https://docs.bazel.build/versions/3.7.0/install-ubuntu.html
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg \
    && mv bazel.gpg /etc/apt/trusted.gpg.d/
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list

RUN apt-get update && apt-get install bazel -y

# Build and test the game.
RUN mkdir /007
COPY roms /007/roms
COPY src /007/src
COPY tests /007/tests
COPY tools /007/tools
COPY .bazelrc /007
COPY BUILD.bazel /007
COPY WORKSPACE /007

WORKDIR /007
RUN bazel test //...
