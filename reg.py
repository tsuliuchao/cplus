# -*- coding: utf-8 -*-
import re
str = "douban://douban.com/tv/26611088/interest/1258190902"

print re.findall(r"tv/([0-9]+)/interest", str)[0]
#输出['123']#?控制只匹配0或1个,所以只会输出和最近的b之间的匹配情况

