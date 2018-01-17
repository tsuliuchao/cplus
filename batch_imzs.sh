#!/bin/bash

APPLICATION=$HOME/workspace/baidu/wiki/ai
echo $APPLICATION
cd $APPLICATION
#imzs_date=(20180103 20180104 20180105 20180106 20180107 20180108 20180109 20180110 20180111 20180112 20180113 20180114 20180115 20180116)
imzs_date=(20180115 20180116 20180117)
for var in ${imzs_date[*]}
do
	echo $var
	./output/bin/collect_imzs $var
done

score_date=(2018-01-14 2018-01-15 2018-01-16)
for var in ${score_date[*]}
do
	echo $var
	./output/bin/score_star_fans $var
done
