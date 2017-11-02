# -*- coding: utf-8 -*-
d = {
	'Adam': 95, #key : value
	'Lisa': 85,
	'Bart': 59
}
print d
if 'Adam' in d:
	print d['Adam']

if 'Lion' not in d:
	print 'Not found'
	d['Lion'] = 30

if 'Lion' in d:
	print d['Lion']

