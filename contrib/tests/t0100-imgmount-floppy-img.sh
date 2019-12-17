#!/bin/bash

set -e
set -x

# Check if DOSBox won't hang when unmounting a floppy drive.

rm -f floppy.img
mkfs.msdos -C floppy.img 1440
file floppy.img
timeout 15s xvfb-run ./src/dosbox \
	-c 'IMGMOUNT A floppy.img -t floppy' \
	-c 'MOUNT -u A' \
	-c 'EXIT'
echo $?
rm -f floppy.img
