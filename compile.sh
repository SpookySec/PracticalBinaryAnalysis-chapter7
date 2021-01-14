gcc hijack.c -o hijack.so -fPIC -shared -ldl
export LD_PRELOAD="$(pwd)/hijack.so"
