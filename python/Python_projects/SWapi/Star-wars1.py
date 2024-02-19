import json
from urllib.request import urlopen
#def get_rep(resource,term):	
def search_by_term(resource,term,term1):
	res=[]
	results="results"
	with urlopen(f'https://swapi.dev/api/{resource}') as repo:
		data_repo =json.load(repo)
	for data in data_repo[results]:
		if any(term in d for d in data ):
			if data[term] == term1:
				res.append({data['name']})
	
	return res

def search_for_all(resource,term):
	res=[]
	results="results"
	with urlopen(f'https://swapi.dev/api/{resource}') as repo:
		data_repo =json.load(repo)
	for data in data_repo[results]:
		if any(term in d for d in data ):
			res.append({data['name']:data[term]})
	return res ,data_repo
	
def check_action(action,resource,term,term1):
	if action=='search_by_term':
		temp=search_by_term(resource,term,term1)
	else:
		action=='search_for_all'
		temp=search_for_all(resource,term)
	return temp
	
def search():
	string=input(' <action> <resource> <term> <term1> ')
	str_arr=string.split()
	action=str_arr[0]
	resource=str_arr[1]
	term=str_arr[2]	
	term1=str_arr[3]
	data=check_action(action,resource,term,term1)	
	return data
def get():
	string=input('get-planets <order-field> <acs/desc>')
	str_arr=string.split()
	#get_planets=str_arr[0]
	order_field=str_arr[0]
	acs_desc=str_arr[1]
	data=print_in_order(order_field,acs_desc)
	return data
	
def print_in_order(order_field,acs_desc):
	res=[]
	results="results"
	with urlopen(f'https://swapi.dev/api/planets') as repo:
		data_repo =json.load(repo)
	for data in data_repo[results]:
		if any(order_field in d for d in data ):
			res.append({data['name']: data[order_field]})
	print(res)
	if acs_desc=='acs':
		return sorted(res,key=lambda x: int(list(x.values())[0][0]))
	else: 
		return sorted(res, key=lambda x: int(list(x.values())[0][0]),reverse=True)
	
def main():
	choose=input(' <function> ')
	if choose=='search':
		data=search()
	
	if choose=='get':
		data=get()

	print(data)
	
if __name__=="__main__":
	main()
