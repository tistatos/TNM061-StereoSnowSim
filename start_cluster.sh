#!/usr/bin/env bash

case "$1" in
    -n )
		./bin/stereosnowsim -config config/single_fisheye.xml
    ;;
	-f )
		./bin/stereosnowsim -config config/single_fisheye_fxaa.xml
	;;
	-m )
		./bin/stereosnowsim -config config/dome/dome_sim.xml
	;;
	-test )
		./bin/stereosnowsim -config config/test_cluster_dome.xml -local 0 &
		./bin/stereosnowsim -config config/test_cluster_dome.xml -local 1 --slave
	;;
	*)
		./bin/stereosnowsim -config config/single.xml
	;;
esac
