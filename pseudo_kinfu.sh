rm 100-0.log
NUMPCD=`cat cv.traj  | tail -n 5 | head -n 1 | cut -d' ' -f 3`
for i in `seq 0 1 $NUMPCD`; do
S=$((i*50))
E=$((S+50))
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
Integrate --ref_traj fun$i.traj --resolution 12 --oni_file ./int$i/ --save_to cloud_bin_$i.pcd --camera ../cam.param ;
done 
wait

