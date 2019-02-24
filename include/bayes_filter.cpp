#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class bayes_filter {

private:
	float p_x, p_x_given_y, p_y, p_y_given_x, p_x_given_x, p_y_given_y;

public:
	bayes_filter(float x_ = 0, float y_ = 0, float x_y = 0, float y_x = 0, float x_x = 0, float y_y = 0) {
		p_x_given_y = x_y;
		p_y_given_x = y_x;
		p_x_given_x = x_x;
		p_y_given_y = y_y;
		p_x = x_;
		p_y = y_;
	}

	~bayes_filter() {}

	float find_probability(int iteration, string var);
};

float bayes_filter::find_probability(int iteration, string var) {
	if(var == "x|y") {
		for(int i=0 ;i< iteration; i++) {
			p_y = p_y_given_x*p_x + p_y_given_y*p_y;
			p_x = p_x_given_x*p_x + p_x_given_y*p_y;
			float normalizer = p_x + p_y;
			p_x = p_x/normalizer;
			p_y = p_x/normalizer;
			p_x_given_y = p_y_given_x*p_x/(p_y);
		}
		return p_x_given_y;
	}

	else if(var == "y|x") {
		for(int i=0 ;i< iteration; i++) {
			p_y = p_y_given_x*p_x + p_y_given_y*p_y;
			p_x = p_x_given_x*p_x + p_x_given_y*p_y;
			float normalizer = p_x + p_y;
			p_x = p_x/normalizer;
			p_y = p_x/normalizer;
			p_y_given_x = p_x_given_y*p_y/(p_x);
		}	
		return p_y_given_x;
	}

	else if(var == "y") {
		for(int i=0 ;i< iteration; i++) {
			p_y = p_y_given_x*p_x + p_y_given_y*p_y;
			p_x = p_x_given_x*p_x + p_x_given_y*p_y;
			float normalizer = p_x + p_y;
			p_x = p_x/normalizer;
			p_y = p_y/normalizer;
		}
		return p_y;	
	}

	else if(var == "x") {
		for(int i=0 ;i< iteration; i++) {
			p_y = p_y_given_x*p_x + p_y_given_y*p_y;
			p_x = p_x_given_x*p_x + p_x_given_y*p_y;
			float normalizer = p_x + p_y;
			p_x = p_x/normalizer;
			p_y = p_y/normalizer;	
		}
	
		return p_x;
	}
}