#!/bin/bash

cd "$(git rev-parse --show-toplevel)"

set -e
set -x

# Check if dosbox won't hang on exit after mounting a floppy image.

rm -f floppy.img
mkfs.msdos -C floppy.img 1440
file floppy.img

timeout 5s xvfb-run ./src/dosbox 
	-c 'IMGMOUNT A floppy.img -t floppy' \
	-c 'EXIT'
rm -f floppy.img
