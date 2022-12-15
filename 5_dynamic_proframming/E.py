n=int(input())
a=[0]*1000
b=[0]*1000
c=[0]*1000
a[1]=b[1]=c[1]=1

for i in range(2,n+1):
    a[i]=b[i-1]+c[i-1]
    b[i]=a[i-1]+b[i-1]+c[i-1]
    c[i]=a[i-1]+b[i-1]+c[i-1]
print(a[n]+b[n]+c[n])