import json
fin=open('testdata.txt')
line=fin.read()
fin.close()
str_js=line.strip('(').strip(')')
js=json.loads(str_js)
out_js=json.dumps(js,indent=4,ensure_ascii=False)
# print out_js
# print out_js
print type(out_js)
fin=open('result.json','w')
fin.write(out_js.encode('utf-8'))