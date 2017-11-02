#-*-coding=utf-8-*-
import time

'''
字符串时间比较
'''

firstStr = '2017-10-16 19:26:02'

secondTime = time.time()

#1.字符串转变成时间数据结构
firstTime = time.strptime(firstStr, '%Y-%m-%d %H:%M:%S')

#2.时间数据结构转换成时间戳
firstTimeInt = time.mktime(firstTime)

print '%s:%s' % (firstTimeInt, secondTime)
print (firstTimeInt - secondTime) > 0

