#!/usr/bin/env python
import twitter
from twython import Twython
import sys
# import datetime
# import time
CONSUMER_KEY = 'TfnPJZfQO9FHXjMgY2wPUCbAu'
CONSUMER_SECRET =  'cdwpNh2cJYQMpleuwkHUo95jSp3tT3PMx4VKHzr5JE7ei2IgnN'
ACCESS_KEY = '790008748681158656-vM47jCnCvSppfoM7KzYeIsRL3fl9mv6'
ACCESS_SECRET =  'i8zemYNWYSrJygwtPDN2arSYfpJsvdKL2GmSEkv1Pikyc'

api = twitter.Api(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET)


twythonapi = Twython(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET) 
twythonapi.update_status(status=sys.argv[1])

# api.PostUpdate(sys.argv[0])

# for xyz in range(0,2):
# 	a = api.PostUpdate("The time is: " + str(datetime.datetime.now()))

# 	time.sleep(10)