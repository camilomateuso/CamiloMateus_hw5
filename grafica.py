import matplotlib.pyplot as plt

from matplotlib.backends.backend_pdf import PdfPages
i=0
lines= open('data1.dat').readlines()

x= []
y=[]
while(i<len(lines)):
    a = lines[i].split(' ')
    x.append(float(a[0].rstrip('\n')))
    y.append(float(a[1].rstrip('\n')))
    i+=1
    
plt.hist(x)
pp = PdfPages('logM.pdf')
plt.savefig(pp, format='pdf')
pp.close()

plt.hist(y)
pp = PdfPages('exponente.pdf')
plt.savefig(pp, format='pdf')
pp.close()
