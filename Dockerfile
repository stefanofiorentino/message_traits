FROM gcc:7.3.0

ADD . /usr/src/message_traits
RUN apt update
RUN apt install -y cmake
RUN cd /usr/src/message_traits && mkdir -p build && cd build || exit 1
RUN cd /usr/src/message_traits/build && cmake .. -DCMAKE_BUILD_TYPE=Release || exit 1
RUN cd /usr/src/message_traits/build && make || exit 1
RUN cd /usr/src/message_traits/build && ./message_traits || exit 1
