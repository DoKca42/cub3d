import os

i = 13
a = 3

while i < 40:
	stra = ("ezgif.com-crop-"+str(i)+".png")
	print(stra)
	os.rename(stra, "PPSH_"+str(a)+".png")
	a += 1
	i += 1