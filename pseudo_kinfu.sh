rm 100-0.log
for i in {0..500..50}; do
local2Global cv.traj fun$i.traj $i $((i+50));
cat fun$i.traj >> 100-0.log;
Integrate --ref_traj fun$i.traj --resolution 12 --oni_file ../ --save_to fun$i.pcd --camera ../cam.param & 
done
wait

