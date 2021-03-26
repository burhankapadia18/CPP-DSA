def distinct_l(lt1,lt2):
    ans=len(set(lt1+lt2))
    return ans
for t in range(int(input())):
    n=int(input())
    lt=input().split()
    body={}
    for i in lt:
        p=i[1:]
        if p in body:
            body[p].append(i[0])
        else:
            body[p]=[i[0]]
    body1=list(body.keys())
    ans=0
    for i in range (len(body)):
        for j in range(i+1,len(body)):
            temp=distinct_l(body[body1[i]],body[body1[j]])
            ans+=(temp-len(body[body1[i]]))*(temp-len(body[body1[j]]))
    print(2*ans)
