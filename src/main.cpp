#include "bayes_filter.cpp"

int main(int argc, char const *argv[])
{

	bayes_filter* arn1 = new bayes_filter(1.0, 0, 0.01, 0.9, 0.1, 0.99);
	int iteration;
	string value;
	cin>>value>>iteration;
	float answer = arn1->find_probability(iteration,value);
	cout<<answer<<endl;
	
	delete(arn1);
	return 0;
}