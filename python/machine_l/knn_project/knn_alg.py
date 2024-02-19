from matplotlib import pyplot as plt
import numpy as np
import random
import math

def p_distance(point,point_ref):
	dist=(sum(point - point_ref)**2)**0.5
	return dist
	
def distance_array(irises_array_train):
	array= []
	for point in range(len(irises_array_test)):
		array.append(p_distance(irises_array_train[point],irises_array_test[point]))
	return (array)
	
def find_k_neighbors(point, irises_array,irises_names,k):
	distance=distance_array(irises_array_train)
	ind=np.argpartition(distance,k)
	min_k=ind[:k]
	print(min_k)
	return(min_k)


	
def determine_n_type( irises_array,irises_names,min_k,k,i):
	concatenated_ko = []
	for point in range(k):
		concatenated_ko.append(irises_names_1[point])
	print(max(set(concatenated_ko), key = concatenated_ko.count))
	if max(set(concatenated_ko), key = concatenated_ko.count)==irises_names_train[i]:
		print (True)
	else: print(False)
	print(concatenated_ko)

#def main()
irises_array=np.loadtxt("iris.data.csv",dtype ="float",usecols=[0,1,2,3],skiprows=1 ,delimiter=",")
irises_names=np.loadtxt("iris.data.csv",dtype ="str",usecols=[4],skiprows=1,delimiter=",")
shuffle=np.random.permutation(len(irises_array))
irises_array_1=irises_array[shuffle]
irises_names_1=irises_names[shuffle]

irises_names_1[irises_names_1=="Iris-setosa"]=1
irises_names_1[irises_names_1=="Iris-versicolor"]=2
irises_names_1[irises_names_1=="Iris-virginica"]=3

four_fifth= int(len(irises_array)*4/5)
irises_array_train = irises_array_1[:four_fifth]
irises_names_train = irises_names_1[:four_fifth]
irises_array_test = irises_array_1[four_fifth:]
irises_names_test = irises_names_1[four_fifth:]
print(irises_names_train)
distance_array(irises_array_train)
k=int(input("please enter the number of neighbors"))
i=int(input("please enter the point index"))
min_k=find_k_neighbors(irises_array_train[i], irises_array,irises_names,k)
determine_n_type( irises_array,irises_names,min_k,k,i)
for i in range(len(irises_array_test)):
	print(f'{i}:{irises_array_test[i]}:{irises_names_test[i]}')




