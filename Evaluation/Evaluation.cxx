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
   std::string in_file_name("../models/neural_net_sync.json");
   std::ifstream in_file(in_file_name);
   network_file = lwt::parse_json(in_file);
   // Create a new lwtn netowrk instance
   nn_instance = new lwt::LightweightNeuralNetwork(network_file.inputs, 
        network_file.layers, network_file.outputs);
   // Set the variables used in training
   inputs["variable_0"] = 115.83694;
   inputs["variable_1"] = -1.8762726;
   inputs["variable_2"] = -2.0628693;
   inputs["variable_3"] = 127.26464;
   inputs["variable_4"] = 459.64105;
   inputs["variable_5"] = 156.83456;
   inputs["variable_6"] = 111.11824;
   inputs["variable_7"] = 0.9964719;
   inputs["variable_8"] = -1.3943541;
   inputs["variable_9"] = 53.14766;
   inputs["variable_10"] = 107.182755;
   inputs["variable_11"] = 246.63837;
   inputs["variable_12"] = 0.2766842;
   inputs["variable_13"] = -1.2781172;
   inputs["variable_14"] = 387.1906;
   inputs["variable_15"] = 6.0;
   inputs["variable_16"] = 56.71256;
   inputs["variable_17"] = 1.0;
   inputs["variable_18"] = 4.512807;
   inputs["variable_19"] = 0.76473796;
   inputs["variable_20"] = 1.6448803;
   inputs["variable_21"] = 3.0;
   inputs["variable_22"] = 43.634937;
   inputs["variable_23"] = 1.0;
   inputs["variable_24"] = 0.5866425;
   inputs["variable_25"] = 70.65949;
   inputs["variable_26"] = 1.4254931;
   inputs["variable_27"] = -2.4915662;
   inputs["variable_28"] = -0.5601357;
   inputs["variable_29"] = 153.49431;
   inputs["variable_30"] = 275.43036;
   inputs["variable_31"] = -0.7349299;
   inputs["variable_32"] = 2.0;
   inputs["variable_33"] = -0.38391635;
   inputs["variable_34"] = 2.0;
   inputs["variable_35"] = 56.546318;
   inputs["variable_36"] = 102.46797;
   inputs["variable_37"] = -2.2543252;
   inputs["variable_38"] = 2.0628693;
   inputs["variable_39"] = 1.0;
   inputs["variable_40"] = -1.7373651;
   inputs["variable_41"] = 61.70563;
   // Calculate the output value of the NN based on the inputs given
   auto out_vals = nn_instance->compute(inputs);
   for (const auto& out: out_vals) {
     output_value = out.second;
     std::cout<<"NN " << out.first << " = " << output_value << std::endl;
   }
   // Eye candy
   return 0;
}

