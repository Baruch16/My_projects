import json
import matplotlib as plt
from urllib.request import urlopen
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression
import random

def get_git_repo(page_num):
	with urlopen(f'https://api.github.com/search/repositories?q=tetris+language:pyhthon&per_page=100page={page_num}') as repo:
		data_repo =json.load(repo)
	return data_repo.pop("items")

	
def collect_repo_pages(num):
	repositories_list =[]	
	for i in range(num):
		num_page= i + 1
		page =get_git_repo(num_page)
		for repo in page:
			repositories_list.append(repo)
	return repositories_list

def split_repo(repositories_list):
	stars = []
	forks = []
	for repo in repositories_list:
		stars.append(repo.pop('stargazers_count'))
		forks.append(repo.pop('forks_count'))
	return stars , forks




def linear_reg(stars,forks):
	rand_indexes = random.sample(range(len(stars)) , int(len(stars)/3))
	#x = np.array(stars).reshape((-1, 1))
	#y = np.array(forks)
	#print(x,y)
	stars_train=np.delete(stars , rand_indexes).reshape((-1,1))
	forks_train=np.delete(forks, rand_indexes)
	stars_test=np.array([stars[rand] for rand in rand_indexes]).reshape((-1,1))
	forks_test=np.array([forks[rand] for rand in rand_indexes])
	model = LinearRegression().fit(stars_train,forks_train)
	r_sq = model.score(stars_test,forks_test)
	predict_test = model.predict(stars_train)
	print(f"coefficient of determination: {r_sq}")
	return stars_train , forks_train , stars_test, forks_test,predict_test
	
def display(stars_train , forks_train , stars_test, forks_test,predict_test):
	plt.scatter(stars_test,forks_test,color="red")
	plt.scatter(stars_train,forks_train,color="blue")
	plt.plot(stars_train,predict_test, color ="black")
	plt.xticks(())
	plt.yticks(())
	
	plt.show()
	
	
	
def main():
	collected_repo = collect_repo_pages(int(input("enter the number of pages: ")))
	stars,forks = split_repo(collected_repo)
	stars_train , forks_train , stars_test, forks_test,predict_test = linear_reg(stars,forks)
	display (stars_train , forks_train , stars_test, forks_test,predict_test)

if __name__=="__main__":
	main()

