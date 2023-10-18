#!/usr/bin/env bash

export ARCH=aarch64
export CROSS_COMPILE=aarch64-linux-gnu-
export DEVICE_TREE="ax3000-evk"

#Configure Axiado U-BOOT
make distclean && make ax3000_evk_defconfig

#Build Axiado U-BOOT
make -j16
