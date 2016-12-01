
# coding: utf-8

# In[1]:
import numpy as np
import matplotlib.pyplot as plt
import corner
import numpy as np

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

    
import corner
import numpy as np

ndim, nsamples = 2, 200000
samples = np.vstack([np.array(x), np.array(y)]).reshape([nsamples,ndim])
figure = corner.corner(samples)

pp = PdfPages('sismo.pdf')
plt.savefig(pp, format='pdf')
pp.close()


# In[ ]:



