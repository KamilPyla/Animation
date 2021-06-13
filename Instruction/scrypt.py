import math

def createLissajous(n,a,b):
	with open(f'Lissa{a}{b}.txt', 'w') as write:
		write.write('800 600 \n')
		path = []
		x, y = 400, 300
		e, f = 100, 100
		cr = 255
		cg = 0
		cb = 0
		# flagy = False
		# flagx = False
		for i in range(1,n+1):

			if cr == 255 and cb == 0:
				cg += 1

			if 0 == cb and cg == 255:
				cr -= 1
			if cr == 0 and cg == 255:
				cb += 1
			if cr == 0 and cb == 255:
				cg -= 1
			if cg == 0 and cb == 255 and cr < 255:
				cr += 1
			if cr == 255 and cg == 0:
				 cb -= 1

			x = 400 + 200*math.sin(i*a/100 + math.pi/2)
			y = 300 + 200*math.sin(i*b/100)

			if len(path) >= 200:
				del path[0] 

			path.append((int(x+e/2),int(y+f/2)))
			write.write(f'{i} {10}\n')
			write.write(f'RP {3}\n')
			write.write(f'KP {0} {0} {0}\n')
			write.write(f'KW {cr} {(cg)} {(cb)}\n')
			write.write(f'EL {(x)} {y} {e} {(f)} 1\n')
			write.write(f'KP {255} {255} {255}\n')
			for el in path:
				write.write(f'PT {el[0]} {el[1]}\n')
			write.write('ST\n')

def createBall(n):
	with open(f'Ins{n}.txt', 'w') as write:
		write.write('800 600 \n')
		x, y = 400, 300
		e, f = 100, 100
		cr = 255
		cg = 0
		cb = 0
		flagy = False
		flagx = False
		for i in range(1,n+1):
			if cr == 255 and cb == 0:
				cg += 1
			if 0 == cb and cg == 255:
				cr -= 1
			if cr == 0 and cg == 255:
				cb += 1
			if cr == 0 and cb == 255:
				cg -= 1
			if cg == 0 and cb == 255 and cr < 255:
				cr += 1
			if cr == 255 and cg == 0:
				 cb -= 1
			if y +  f > 600:
				flagy = True
			elif y < 0 :
				flagy = False
			if x +  e > 800:
				flagx = True
			elif x < 0 :
				flagx = False
			if flagy :
				y += 5
			else:
				y -= 5
			if flagx:
				x -= 5
			else:
				x += 5
		write.write(f'{i} {10}\n')
		write.write(f'RP {3}\n')
		write.write(f'KP {0} {0} {0}\n')
		write.write(f'KW {cr} {(cg)} {(cb)}\n')
		write.write(f'EL {(x)} {y} {e} {(f)} 1\n')
		write.write('ST\n')
	
createLissajous(1000,1,2)
createLissajous(1000,2,3)
createLissajous(1000,3,4)
createLissajous(1000,2,6)
createLissajous(1000,1,8)

