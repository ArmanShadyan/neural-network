# Simple Feed-Forward Neural Network in C++

This project is a basic implementation of a feed-forward neural network in C++. It's designed to serve as a starting point for those interested in understanding how neural networks work.

## Project Structure

The project consists of three main classes:

- `Neuron`: Represents a single neuron in the neural network. Each neuron has a value and a set of weights. The `activate` function applies the sigmoid activation function to a given input, and the `feed` function calculates the weighted sum of its inputs and applies the activation function to it.

- `Layer`: Represents a layer of neurons in the neural network. It contains a vector of neurons and a `feed` function that feeds the inputs through all the neurons in the layer.

- `NeuralNetwork`: Represents the neural network itself. It contains a hidden layer and an output layer, and a `feed` function that feeds the inputs through the hidden layer and then the output layer.

## Usage

To run the program, compile and execute the main.cpp file. The `main` function creates a neural network with 2 input neurons, 3 hidden neurons, and 1 output neuron. It then feeds two inputs (0.5 and 0.6) through the network and prints the output.

## License

This project is licensed under the MIT License.
