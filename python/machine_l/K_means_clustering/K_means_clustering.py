import random
import numpy as np
import math

def get_data():
	data=open('iris.data')
	irises_lines=data.readlines()
	irises=[]
	for i in irises_lines:
		irises.append(i.split(","))
	irises.pop(-1)
	#print (irises)
	return irises

def rand_means(data,k):
	means = random.sample(data, k)
	#print (means)
	return means
	

#Calculates the distance between two points
def distance(point1, point2):
	for i in range(4):
		temp = float(point1[i])
		point1[i] = temp
		
		temp = float(point2[i])
		point2[i] = temp
	sum_points = 0
	for i in range(4):
		sum_points += (point1[i] - point2[i])**2
	return sum_points
	
def calculate_min_distance(data,means,k):
	min_distance=[]
	for i in range(len(data)):
		calc_distances=[]
		for j in range(k):
			temp_cal_of_dis = distance(data[i],means[j])
			array = [temp_cal_of_dis,j,i]
			calc_distances.append(array)
		min_distance.append(min(calc_distances))
	#print(min_distance)
	return min_distance

def create_array(min_distance):
	sort_array=[[],[],[]]
	for i in range(len(min_distance)):
		temp=min_distance[i][1]
		sort_array[temp].append(min_distance[i])
	#print(sort_array)
	return sort_array
	
def  get_numbers(sort_array,data):
	points_actual=[[],[],[]]
	for j in range(len(sort_array)):
		for i in range(len(sort_array[j])):
			points_actual[j].append(data[sort_array[j][i][-1]])
	#print(points_actual)
	return points_actual
		

def get_central_mass(points_actual):
	central_mass_array=[[],[],[]]
	for j in range(len(points_actual)):
		for w in range(4):
			num=0
			for i in range(len(points_actual[j])):
				num+=points_actual[j][i][w]
			central_mass_array[j].append(num/len(points_actual[j]))
	#print (central_mass_array)
	return(central_mass_array)
	
def calculate_difference(means,points_actual):
	difference=[]
	for j in range(len(means)):
		num=0
		for i in range(len(points_actual[j])):
			num+= distance(means[j],points_actual[j][i])
		difference.append(num)
	#print(sum(difference))
	return sum(difference)

	
data=get_data()
k=3
for i in range(10):
	means=rand_means(data,k)
	check=0
	best_means_array=[]
	best_points_array=[]
	arrays_means=[]
	while check==0:
		min_distance=calculate_min_distance(data,means,k)
		sorted_array=create_array(min_distance)
		numbers=get_numbers(sorted_array,data)
		temp_means=get_central_mass(numbers)
		if temp_means==means:
			check=1
		means=temp_means
		#print(means)
	check=0
	arrays_means=means
	best_means_array.append(calculate_difference(means,numbers))
	best_points_array.append(numbers)
index_num=best_means_array.index(min(best_means_array))
print(min(best_means_array))
print(best_points_array[index_num])
print(arrays_means)
