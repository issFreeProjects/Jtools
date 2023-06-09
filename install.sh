#!/bin/bash
#

LIBDIR="/lib/"
BINDIR="/usr/bin/"


# uninstalling
#
if [[ $1 = "--uninstall" ]]
then
    for slink in $(ls $LIBDIR/libjalali.so* $BINDIR/jcal $BINDIR/jdate)
    do
        unlink $slink
    done
    exit 0
fi



# installing libjalali
#
ln -s $PWD/build/libjalali/libjalali.so* $LIBDIR


# installing jdate and jcal
#
ln -s $PWD/build/jdate $BINDIR
ln -s $PWD/build/jcal  $BINDIR
