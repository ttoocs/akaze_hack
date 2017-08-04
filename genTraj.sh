
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )" 
for i in {0..500}; do
echo $i $i $((i+1)) 
$DIR/build/bin/akaze_match ../colourframes/Image$i.jpg ../colourframes/Image$((i+1)).jpg | grep -A4 Mat:\ H  | tail -n 4
done | tee cv.traj 
