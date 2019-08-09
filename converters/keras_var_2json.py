#!/usr/bin/env python3
#
# Converter from list of Varaible and output of NN to JSON
import json
import argparse

"""
must provide two files:
variables_file:
['var_0','var_1',...,'var_n']
classes_file:
['prediction_1',...,'prediction_n']
"""

def _get_args():
    parser = argparse.ArgumentParser(
        description="Converter from Variable.log to Variable.JSON",
        epilog=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('variables_file', help='list of variable names in list')
    parser.add_argument('classes_file', help='list of predicted variables names in list')
    parser.add_argument('--mean', help='mean value to offset the input', default=0, type=int)
    parser.add_argument('--scale', help='scale the input', default=1,type=int)
    return parser.parse_args()


def _run():
    """Top level routine"""
    args = _get_args()

    inVars=[]
    with open(args.variables_file,'r') as filehandle:
        for line in filehandle:
            currentPlace = line
            var_lines =  currentPlace.replace("['","").replace("']","").replace("','"," ")
            inVars = list(var_lines.split())
    
    outVars=[]
    with open(args.classes_file,'r') as outhandle:
        for line in outhandle:
            currentPlace = line
            var_lines =  currentPlace.replace("['","").replace("']","").replace("','"," ")
            outVars = list(var_lines.split())
    
    inputs = build_inputs(inVars, args.mean, args.scale)
    out_dict = {
        'inputs': inputs, 
        'class_labels':outVars
    }

    print(json.dumps(out_dict,indent=2))

def build_inputs(input_items, mean, scale):
    inputs=[]
    for inVar in input_items:
        the_input = {
            'name':inVar,
            'offset':mean,
            'scale':scale
        }
        inputs.append(the_input)
    return inputs



if __name__ == '__main__':
    _run()
