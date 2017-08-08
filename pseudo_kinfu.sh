#!/bin/bash

SAMPLES=50
if [ "$1" == "" ] ; then
  SAMPELS=$1
fi

rm 100-0.log
NUMTRAJ=`cat cv.traj  | tail -n 5 | head -n 1 | cut -d' ' -f 3`
NUMPCD=$((NUMTRAJ / SAMPLES))
for i in `seq 0 1 $NUMPCD`; do
S=$((i * SAMPLES))
E=$((S + SAMPLES))
echo Start: $S
echo End: $E
local2Global cv.traj fun$i.traj $S $E;
cat fun$i.traj >> 100-0.log;
rm -rf int$i;
mkdir int$i;
  cd int$i;
  mkdir colourframes
  mkdir depthframes
  for j in `seq $S 1 $E`; do
    ln -s ../../../colourframes/Image$j.jpg ./colourframes/Image$((j-S)).jpg
    ln -s ../../../depthframes/Image$j.png ./depthframes/Image$((j-S)).png
  done;
  cd ..
Integrate --ref_traj fun$i.traj --resolution 12 --oni_file ./int$i/ --save_to cloud_bin_$i.pcd --camera ../cam.param --reduce 4;
done 
wait

