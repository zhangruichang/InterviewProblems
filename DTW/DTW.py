# -*- coding: utf-8 -*-
"""
Created on Mon Apr 27 14:11:43 2015

@author: zhou.zhang
"""

import pickle
import math
#import pandas as pd
#import numpy as np
import sys
ticker_id_list = [63, 823, 600050, 600198, 600289, 600345, 600405, 600485, 600487, \
600498, 600522, 600776, 2017, 2052, 2089, 2093, 2115, 2148, 2194, 2231, 2261, 2281, \
2289, 300002, 2446, 300353, 2313, 2316, 300025, 300038, 2364, 300047, 300050, 300098, \
2417, 300077, 300134, 300136, 2547, 300166, 2544, 300366, 300250, 300252, 300288, 300292, \
300310, 300312, 300299, 300322]
#dic = pickle.load(open('them1pickle5rise.txt'))
'''
sim_dic = {}
new_tid = []
for i in ticker_id_list:#获取有数据的tid
    if len(dic[i]):
        new_tid.append(i)
#print new_tid
arr_cos = np.zeros((len(new_tid),len(new_tid)))
arr_dtw = np.zeros((len(new_tid),len(new_tid)))
'''
def cos_sim(l1,l2): #两个向量的余弦相似度
    ll1 = len(l1)
    ll2 = len(l2)
    l = min(ll1,ll2)
    l1 = l1[:l]
    l2 = l2[:l]
    num = 0
    for i in range(l):
        num += l1[i]*l2[i]
    s1 = 0
    s2 = 0
    for i in l1[:l]:
        s1 += i*i
    for j in l2[:l]:
        s2 += j*j
    if math.sqrt(s1)*math.sqrt(s2) == 0:
        return 0
    return num/(math.sqrt(s1)*math.sqrt(s2))

#length = len(new_tid)
def distance(a,b):
    return (a-b)**2
def dtw(X, Y):
     #X = normalize(X)
     #Y = normalize(Y)
     M=[[distance(X[i],Y[j]) for i in range(len(X))] for j in range(len(Y))]

     l1=len(X)
     l2=len(Y) 
     D=[[0 for i in range(l1+1)] for i in range(l2+1)]
     D[0][0]=0 
     for i in range(1,l1+1):
         D[0][i]=sys.maxint
     for j in range(1,l2+1):
         D[j][0]=sys.maxint
     for i in range(1,l1+1):
        for j in range(1,l2+1):
             D[i][j]=M[j-1][i-1]+min(D[j-1][i],D[j][i-1],D[j-1][i-1])
     return D[l2][l1]
def dtw_constraint1(X, Y):
     #X = normalize(X)
     #Y = normalize(Y)
     l1=len(X)
     l2=len(Y)
     M=[[distance(X[i],Y[j]) for j in range(l2)] for i in range(l1)]
     Path=[[0 for i in range(l2+1)] for j in range(l1+1)]
     D=[[0 for j in range(l2+1)] for i in range(l1+1)]
     D[0][0]=0 
     for i in range(1,l1+1):
         D[i][0]=sys.maxint
     for j in range(1,l2+1):
         D[0][j]=sys.maxint
     for i in range(1,l1+1):
        for j in range(1,l2+1):
             D[i][j]=M[i-1][j-1]+min(D[i-1][j],D[i][j-1],D[i-1][j-1])
             if D[i][j]== M[i-1][j-1]+D[i-1][j]:
                 Path[i][j]=0
             elif D[i][j]== M[i-1][j-1]+D[i][j-1]:
                 Path[i][j]=1
             else:
                 Path[i][j]=2
     #print X, Y
     i=l1
     j=l2
     while not (i==0  and j==0):
         print i, j
         if Path[i][j]==0:
             i-=1
         elif Path[i][j]==1:
             j-=1
         else:
             i-=1
             j-=1
     print i, j
     return D[l1][l2]
#print cos_sim(dic[new_tid[length-1]],dic[new_tid[2]])
def normalize(a=[1.0,2.0,3,4,5]):
    pass
    '''
    pa = pd.DataFrame(a)
    mean = float(pa.mean())
    std = float(pa.std())
    if std == 0:
        return a
    for i in range(len(pa)):
        pa[0][i] = float((pa[0][i]-mean))/float(std)
    return list(pa[0])
    '''
if __name__ == '__main__':   
    print dtw_constraint1([1,2,3,4],[1,2,3,4,5])
    '''
    for i in range(length):
        for j in range(length):
            arr_cos[i][j] = cos_sim(dic[new_tid[i]],dic[new_tid[j]])
            arr_dtw[i][j] = dtw(normalize(dic[new_tid[i]]),normalize(dic[new_tid[j]]))
    print arr_dtw
    print arr_cos
'''
    