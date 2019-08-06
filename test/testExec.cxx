// Include the headers needed for sequential model
#include "lwtnn/NNLayerConfig.hh"
#include "lwtnn/LightweightNeuralNetwork.hh"
#include "lwtnn/parse_json.hh"
#include "lwtnn/Stack.hh" 
#include <fstream> 
#include <iostream>

int main() {

   // Define some variables, often in a header file
   float output_value;
   lwt::JSONConfig network_file;
   // The map for the variables
   std::map<std::string,double> inputs;
   // The actual NN instance
   lwt::LightweightNeuralNetwork *nn_instance;
   // Read in the network file
   std::string in_file_name("test_NN.json");
   std::ifstream in_file(in_file_name);
   network_file = lwt::parse_json(in_file);
   // Create a new lwtn netowrk instance
   nn_instance = new lwt::LightweightNeuralNetwork(network_file.inputs, 
        network_file.layers, network_file.outputs);
   // Set the variables used in training
   inputs["y_Reta"] = 1.2;
   inputs["y_Rphi"] = 1.2;
   inputs["y_Rhad"] = 1.2;
   inputs["y_weta1"] = 1.2;
   inputs["y_fracs1"] = 1.2;
   inputs["y_weta2"] = 1.2;
   // Calculate the output value of the NN based on the inputs given
   auto out_vals = nn_instance->compute(inputs);
   for (const auto& out: out_vals) {
     output_value = out.second;
    }
   // Eye candy
   std::cout<<"NN output = " << output_value << std::endl;
   return 0;
}

