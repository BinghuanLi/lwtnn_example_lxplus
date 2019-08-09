lwtnn example at lxplus environment
==================================

Introduction
------------------------
1. [lwtnn][lwt] is a set of classes which reconstruct the neural network for application in a C++ production environment
2. lwtnn is now available at lxplus, this example tells you how to use it 

[lwt]:https://github.com/lwtnn/lwtnn

Setting up the code
------------------------
Downloading the project from github
```bash
git clone git@github.com:BinghuanLi/lwtnn_example_lxplus.git
```

Setting up the environment
```bash
source setup.sh
```

Converters
----------------------

lwtnn evaluation scripts takes as input the neural net weight in json format, if you already have it, you can skip this part and go to Evaluations.

This is an example on the usage of converters for sequential model, detailed explanations can be found at [Keras-Converter][kc].

Make sure you saved your arcthitecture in json form and weight file in h5 from Keras.

```bash
./converters/keras2json.py input_models/model_serialised.json input_models/variables_list.json input_models/model_weights.h5 > models/neural_net_example.json
```

Following is a helper to convert variable list and output list into json. 
```bash
python converters/keras_var_2json.py input_models/variables_list.log input_models/classes_list.log > input_models/variables_list.json
```

[kc]:https://github.com/lwtnn/lwtnn/wiki/Keras-Converter

Evaluations
---------------------
For evaluations, a neural network weight in json format `models/neural_net_example.json` is needed

To compile:
```bash
cd Evaluation
g++ -o Evaluation_example.x Evaluation_example.cxx -L/cvmfs/sft.cern.ch/lcg/views/LCG_96python3/x86_64-slc6-gcc8-opt/lib -lboost_thread -llwtnn -lboost_system -I/cvmfs/sft.cern.ch/lcg/views/LCG_96python3/x86_64-slc6-gcc8-opt/include/eigen3
./Evaluation_example.x -input ../models/neural_net_example.json
```

You should see output:
```bash
NN predictions_ttH = 0.104628
NN predictions_ttJ = 0.637788
NN predictions_ttW = 0.056851
NN predictions_ttZ = 0.200734
```

Questions?
---------------
If you have any questions in running this example, please do not hesitate to email me at binghuan.li@cern.ch
