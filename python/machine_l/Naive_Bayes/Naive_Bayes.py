import numpy as np
import random
import math
#get uniques for each column
def get_uniques(attributes):
	uniques=[]
	for column in range(len(attributes[0])):
		uniques.append([])
		for line in range(len(attributes)):
			uniques[column].append(attributes[line][column])
		uniques[column] = set(uniques[column])
	return uniques
#split the data into two arrays (attribute and danger)
def split_array(mushroom_data):
	danger = [mushroom_data[i][0] for i in range(len(mushroom_data))] 
	attributes = [mushroom_data[i][1:] for i in range(len(mushroom_data))]
	return danger,attributes
	
#create a dictionary with dictionaries in its entry
def create_dict(uniques):
	mushroom_dict={}
	for i  in range(len(uniques)):
		mushroom_dict[i]={}
		for item in uniques[i]:
			mushroom_dict[i][item]=[0,0]
	return mushroom_dict
	
#Combine the two arrays into a paired array
def pairs_array(danger,attributes):
	data_pairs = []
	array = np.arange(len(attributes))
	for ar in array:
		data_pairs.append([attributes[ar], danger[ar]])
	return data_pairs
	
#For each attribute count the times it appears for poisonous and safe mushrooms 
def count(training_array,mushroom_dict):
	for i in range(len(training_array)) :
		for element in range(len(training_array[0][0])):
			mushroom_dict[element][training_array[i][0][element]][0 if training_array[i][1]=='p' else 1] +=1
	return mushroom_dict
	
#count the ammount of poisounous and safe mushrooms 
def count_all(training_array):
	sum_poisonous = sum_not_poisonous = 0
	for i in range(len(training_array)):
		if training_array[i][1] == 'p':
			sum_poisonous += 1
		else:
			sum_not_poisonous += 1
	return sum_poisonous, sum_not_poisonous
	
#Callculate the probability for each attribute to appear for both types 	
def calculate_probability(final_data,sum_poisonous, sum_not_poisonous,k=0.5):
	probability= [0]*len(final_data)
	for i in final_data:
		probability[i]=[]
		for j,(poisonous, safe) in final_data[i].items():
			probability[i].append((j,(poisonous+k)/(sum_poisonous+2*k), (safe + k)/(sum_not_poisonous + 2*k)))
	print(probability)
	return probability
	
#Calculate the probability of a given mushroom to be either poisonous or safe 
def probability_of_poisonous(calculate_probability, testing_array):
	log_prob_if_poisonous = log_prob_if_not_poisonous = 0.0
	for i in range(len(testing_array)): 
		for attribute, prob_if_poisonous, prob_if_not_poisonous in calculate_probability[i]:
			if attribute in testing_array[i]:
				log_prob_if_poisonous += math.log(prob_if_poisonous)
				log_prob_if_not_poisonous += math.log(prob_if_not_poisonous)
			else:
				log_prob_if_poisonous += math.log(1.0 - prob_if_poisonous)
				log_prob_if_not_poisonous += math.log(1.0 - prob_if_not_poisonous)
	prob_if_poisonous = math.exp(log_prob_if_poisonous)
	prob_if_not_poisonous = math.exp(log_prob_if_not_poisonous)
	poisonous_prob = prob_if_poisonous / (prob_if_poisonous + prob_if_not_poisonous)
	return poisonous_prob	

#Test the function on the testing data
def testing(testing_array, calculate_probability):
	num_poisonous = num_not_poisonous = 0
	for i in range(len(testing_array)):
		probability =probability_of_poisonous(calculate_probability, testing_array[i][0])
		if probability > 0.5 and testing_array[i][1] == 'p':
			num_poisonous += 1
		if probability < 0.5 and testing_array[i][1] == 'e':
			num_not_poisonous += 1
	return num_poisonous, num_not_poisonous
	
def main():
	#Get the data,create the paired array
	mushroom_data= np.loadtxt('agaricus_lepiota.data',usecols = [] ,skiprows = 0 ,dtype = 'str', delimiter = ',')
	print(mushroom_data)
	np.random.shuffle(mushroom_data)
	danger,attributes=split_array(mushroom_data)
	uniques=get_uniques(attributes)
	mushroom_dict=create_dict(uniques)
	data_pair=pairs_array(danger,attributes)
	
	#Divide the array in two
	training_array = data_pair[:int(len(data_pair)*4/5)]
	testing_array = data_pair[int(len(data_pair)*4/5):]
	
	#Run the program on the training array 
	sum_poisonous, sum_not_poisonous = count_all(training_array)
	final_data=count(training_array,mushroom_dict)
	calculate_probability1=calculate_probability(final_data,sum_poisonous, sum_not_poisonous)

	#Run the program on the testing array
	sum_test_poisonous, sum_test_not_poisonous = count_all(testing_array)
	count_poisonous, count_not_poisonous = testing(testing_array, calculate_probability1)
	
	#Calculate the accuracy 
	print("The model is accurate in", count_poisonous, "cases from", sum_test_poisonous, "poisonous mushrooms (",round(100 			*count_poisonous/sum_test_poisonous, 2),"%), and in", count_not_poisonous, "from", sum_test_not_poisonous, "not poisonous (", round(100 *count_not_poisonous/sum_test_not_poisonous, 2),"%)")
	print("The final grade of the model is: ", round(100 *(count_poisonous + count_not_poisonous)/(sum_test_poisonous + 	sum_test_not_poisonous), 2),"%")

if __name__=="__main__":
	main()

