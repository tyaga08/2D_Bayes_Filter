# 2D_Bayes_Filter  
Implementation of a simple 2D Bayes Filter. It can be used to find the probability of 2 dependent events that are mutually exhaustive.  

Description:  
This code is for a generic 2 state problem which are mutually exhaustive and dependent. In this case the state 'x' means 'on the ground' and state 'y' means 'in the air'.  

Initial states  
p(state=x) = 1  
p(state=y) = 0  
p(state=x | prev_state=x, u='take_off') = 0.1  
p(state=y | prev_state=x, u='take_off') = 0.9  
p(state=x | prev_state=y, u='take_off') = 0.01  
p(state=y | prev_state=y, u='take_off') = 0.99  
  
At any time step,  
p(state=x) = normalizer*[p(state=x | prev_state=x, u='take_off')*p(state=x) + p(state=x | prev_state=y, u='take_off')*p(state=y)]  
  
In order to run the code, follow the instructions:  
-> Go to the project folder  
-> Open terminal  
-> Run the following commands:  
	cd build  
	cmake .  
	make  
	./bayes  
-> Then give the inputs - state, number of time steps after which I want to calculate its probability  
  
For eg:  
To calculate the probability of state='on the ground' or state=x at the 10th time step,  
./bayes  
x 10  
