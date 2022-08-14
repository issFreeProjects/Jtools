#!/bin/sh

LIBDIR="/usr/lib"
BINDIR="/usr/bin"

# exit when any command fails
set -e
# echo an error message before exiting
trap 'echo "filed with exit code $?."' EXIT


mkdir build; cd build
echo "create build directory."

cmake ../
echo "make file created, running make..."
make

echo "make is done"

echo "installing libjalali library..."
cp libjalali/liblibjalali.so.* $LIBDIR
unlink $LIBDIR/liblibjalali.so
ln -s $LIBDIR/liblibjalali.so.* $LIBDIR/liblibjalali.so

echo "installing executable binary..."
cp jdate $BINDIR

cd ../
echo "\nDone!"
