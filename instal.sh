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
cp libjalali/libjalali.so.* $LIBDIR
if [[ -f $LIBDIR/libjalali.so ]]; then
    unlink $LIBDIR/libjalali.so
fi
ln -s $LIBDIR/libjalali.so.* $LIBDIR/libjalali.so

echo "installing executable binary..."
cp jdate $BINDIR
cp jcal $BINDIR

cd ../
echo "\nDone!"
