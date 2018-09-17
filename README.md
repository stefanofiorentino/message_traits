## Message Traits

Type traits made easy for message dispatching simple (not so simplistic) lib.

## Building

mkdir -p build && cd build || exit 1

cmake .. -DCMAKE_BUILD_TYPE=Release || exit 1

make || exit 1

./message_traits || exit 1
