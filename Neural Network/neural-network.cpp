#include <iostream>
#include <vector>
#include <cmath>

class Neuron {
public:
    double value;
    std::vector<double> weights;

    double activate(double x) {
        return 1 / (1 + exp(-x));
    }

    double feed(std::vector<Neuron> &inputs) {
        double sum = 0;
        for (int i = 0; i < inputs.size(); i++) {
            sum += inputs[i].value * weights[i];
        }
        value = activate(sum);
        return value;
    }
};

class Layer {
public:
    std::vector<Neuron> neurons;

    Layer(int size, int inputSize) {
        for (int i = 0; i < size; i++) {
            Neuron neuron;
            neuron.weights = std::vector<double>(inputSize, 0.5); // Initialize weights to 0.5 for simplicity
            neurons.push_back(neuron);
        }
    }

    std::vector<double> feed(std::vector<Neuron> &inputs) {
        std::vector<double> outputs;
        for (Neuron &neuron : neurons) {
            outputs.push_back(neuron.feed(inputs));
        }
        return outputs;
    }
};

class NeuralNetwork {
public:
    Layer hiddenLayer;
    Layer outputLayer;

    NeuralNetwork(int inputSize, int hiddenSize, int outputSize)
        : hiddenLayer(hiddenSize, inputSize), outputLayer(outputSize, hiddenSize) {}

    std::vector<double> feed(std::vector<Neuron> &inputs) {
        return outputLayer.feed(hiddenLayer.neurons);
    }
};

int main() {
    NeuralNetwork nn(2, 3, 1);
    std::vector<Neuron> inputs(2);
    inputs[0].value = 0.5;
    inputs[1].value = 0.6;
    std::vector<double> outputs = nn.feed(inputs);
    for (double output : outputs) {
        std::cout << output << std::endl;
    }
    return 0;
}
