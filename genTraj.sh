#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )" 

NUMFRAMES=`ls ../colourframes/Image*.* | wc -l`
for i in `seq 0 1 $((NUMFRAMES-2))`; do
  echo $i $i $((i+1)) 
  $DIR/build/bin/akaze_match ../colourframes/Image$i.jpg ../colourframes/Image$((i+1)).jpg | grep -A4 Mat:\ H  | tail -n 4
done | tee cv.traj 
