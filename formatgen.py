import json

idk = open('./words.txt', 'r')
formatted = open('./formattedwords.txt', 'w')

for word in idk:
    formatted.write(json.dumps(word.strip()))
    formatted.write("\n, ")

idk.close()