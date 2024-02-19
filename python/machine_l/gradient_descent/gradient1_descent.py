import numpy as np
import matplotlib.pyplot as plt

#The model of gradiebt descent for linear regression
def gradient_descent(X_array, Y_array, y_predict,weights):
	partial_derivative_n = sum(weights * (y_predict - Y_array)) 
	partial_derivative_m = sum(weights * X_array * (y_predict - Y_array))
	return partial_derivative_n, partial_derivative_m
	
#The model for linear regression using the GD model 
def linear_regression(X_array, Y_array,weights):
	theta_1 = 10
	theta_2 = 10
	alpha= 0.0001
	epsilon = 1
	i=0
	while i<1 and epsilon > alpha: 
		y_predict = (theta_2 * X_array) + theta_1
		partial_derivative_n, partial_derivative_m = gradient_descent	(X_array, Y_array, y_predict,weights)
		
		theta_1 = theta_1 - alpha * partial_derivative_n
		theta_2 = theta_2 - alpha * partial_derivative_m
		
		cost_error = cost(Y_array, y_predict,weights)
		epsilon = max(abs(partial_derivative_n), abs(partial_derivative_m))
		i+=1
	print(cost_error)
	print( epsilon)
		
		
	return theta_1, theta_2
# A function to calculate the cost for the 	
def cost(Y_array, y_predict,weights):
	cost = np.sum(weights*(y_predict - Y_array)**2)
	return cost
	
#A function to display the results on a graph
def display(X_array,Y_array, x_points, y_points):
	plt.plot(x_points ,y_points)
	plt.scatter(X_array, Y_array, color="red")
	plt.show()
	
# A utility function to get the points to be displayed
def return_result(x_points, theta_1, theta_2):
	result = theta_1 + theta_2 * x_points
	return result
	
# A utility function to weigh the points 
def weigh(X_array):
	median = np.median(X_array)
	max_distance=max(abs(median-max(X_array)),abs(median-min(X_array)))
	weights=-(X_array - median)**2 + max_distance**2 +0.001
	sum_weights=sum(weights)
	print ("the sum is:",sum_weights,"the median is:", median)
	weights/=sum_weights
	plt.scatter(X_array, weights, color="black")
	plt.show
	return weights
	
		
def main():
	data = np.load('XYdata.npz')
	X_array, Y_array = data['array_1'], data['array_2']
	x_points = np.linspace(-1, 11, 50)
	
	weights=weigh(X_array)
	theta_1, theta_2 = linear_regression(X_array, Y_array, weights)
	print("theta 1:", theta_1, "theta 2:", theta_2)
	y_points = return_result(x_points, theta_1, theta_2)
	display(X_array, Y_array, x_points ,y_points)
	
	
if __name__ == "__main__":
    main()

