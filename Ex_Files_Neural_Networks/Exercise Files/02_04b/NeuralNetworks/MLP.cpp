#include "MLP.h"

double get_rand(void){
    auto random = rand()%2;
    double val =random/2.0;
    return val;
}

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}

// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(int inputs, double _bias):bias(_bias){
    weights.resize(inputs);
    generate(weights.begin(), weights.end(), get_rand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(vector<double> x){
    double accumlator = bias;
    accumlator=inner_product(weights.begin(),weights.end(),x.begin(),accumlator);
    accumlator=sigmoid(accumlator);
    return accumlator;
}

void Perceptron::set_weights(vector<double> w_init){
    weights=w_init;
}

double Perceptron::sigmoid(double x){
    return 1/(1+exp(-1*x));
}
