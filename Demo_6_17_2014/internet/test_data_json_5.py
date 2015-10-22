
'''
Created on 

@author: lenovo
'''
import json
fin=file('flightPriceDouble.json')
js=json.load(fin)
print type(js)
print js

jsdata=json.dumps(js,indent=4)
print jsdata
print type(jsdata)
print js["0KA5367|1KA876"]
