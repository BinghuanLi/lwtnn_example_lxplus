// Include the headers needed for sequential model
#include "lwtnn/NNLayerConfig.hh"
#include "lwtnn/LightweightNeuralNetwork.hh"
#include "lwtnn/parse_json.hh"
#include "lwtnn/Stack.hh" 
#include <fstream> 
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv){ 

   std::string input_json_file="";
   for (int i = 1; i < argc; ++i) {
    cout<<"Command line parameter "<<i<<" is "<<argv[i]<<endl;
    if (!strcmp(argv[i], "-input")){
      input_json_file =std::string(argv[i+1]);
      cout << " use input nn json file : " << input_json_file  << endl;
    }
   }
   if(input_json_file.empty()){
      cout << " use default nn json file : " << input_json_file  << endl;
      input_json_file = "../models/neural_net_sync.json";
    }
   // Define some variables, often in a header file
   float output_value;
   lwt::JSONConfig network_file;
   // The map for the variables
   std::map<std::string,double> inputs;
   // The actual NN instance
   lwt::LightweightNeuralNetwork *nn_instance;
   // Read in the network file
   //std::string in_file_name("../models/neural_net_sync.json");
   cout << " load nn json file : " << input_json_file  << endl;
   std::string in_file_name(input_json_file);
   std::ifstream in_file(in_file_name);
   network_file = lwt::parse_json(in_file);
   // Create a new lwtn netowrk instance
   nn_instance = new lwt::LightweightNeuralNetwork(network_file.inputs, 
        network_file.layers, network_file.outputs);
   // Set the variables used in training
   inputs["jet3_pt"] = 115.83694;
   inputs["jet3_eta"] = -1.8762726;
   inputs["lep1_eta"] = -2.0628693;
   inputs["jet2_pt"] = 127.26464;
   inputs["jet1_E"] = 459.64105;
   inputs["jet1_pt"] = 156.83456;
   inputs["mT_lep1"] = 111.11824;
   inputs["resTop_BDT"] = 0.9964719;
   inputs["jet4_phi"] = -1.3943541;
   inputs["lep2_conePt"] = 53.14766;
   inputs["massL"] = 107.182755;
   inputs["jet2_E"] = 246.63837;
   inputs["jet1_phi"] = 0.2766842;
   inputs["jet2_eta"] = -1.2781172;
   inputs["jet3_E"] = 387.1906;
   inputs["n_presel_jet"] = 6.0;
   inputs["jet4_E"] = 56.71256;
   inputs["lep1_charge"] = 1.0;
   inputs["avg_dr_jet"] = 4.512807;
   inputs["lep1_phi"] = 0.76473796;
   inputs["mindr_lep2_jet"] = 1.6448803;
   inputs["nBJetLoose"] = 3.0;
   inputs["jet4_pt"] = 43.634937;
   inputs["n_presel_mu"] = 1.0;
   inputs["mindr_lep1_jet"] = 0.5866425;
   inputs["lep1_conePt"] = 70.65949;
   inputs["lep2_phi"] = 1.4254931;
   inputs["jet2_phi"] = -2.4915662;
   inputs["lep2_eta"] = -0.5601357;
   inputs["mbb"] = 153.49431;
   inputs["lep1_E"] = 275.43036;
   inputs["jet4_eta"] = -0.7349299;
   inputs["nBJetMedium"] = 2.0;
   inputs["Hj_tagger_resTop"] = -0.38391635;
   inputs["Dilep_pdgId"] = 2.0;
   inputs["mT_lep2"] = 56.546318;
   inputs["metLD"] = 102.46797;
   inputs["jet3_phi"] = -2.2543252;
   inputs["maxeta"] = 2.0628693;
   inputs["n_presel_ele"] = 1.0;
   inputs["jet1_eta"] = -1.7373651;
   inputs["lep2_E"] = 61.70563;
   // Calculate the output value of the NN based on the inputs given
   auto out_vals = nn_instance->compute(inputs);
   for (const auto& out: out_vals) {
     output_value = out.second;
     std::cout<<"NN " << out.first << " = " << output_value << std::endl;
   }
   // Eye candy
   return 0;
}

