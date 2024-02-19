
import requests
import re

idx = 55274
base_url = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing="

for i in range(400):
    response = requests.get(base_url + str(idx))
    contents = response.content.decode('utf-8')
    print("Contents:", contents)
    res = re.search('and the next nothing is ', contents)
    if res:
        res = res.start()
        idx = contents[res +24:res+29]
    else:
        print("Stopping")
        break



