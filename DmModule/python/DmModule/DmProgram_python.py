#
# Copyright (C) 2012-2020 Euclid Science Ground Segment
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation; either version 3.0 of the License, or (at your option)
# any later version.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
#


"""
File: python/DmModule/DmProgram_python.py

Created on: 09/21/20
Author: user
"""

import os                                 # for the path tools
import argparse                           # for program options from configuration
import ElementsKernel.Logging as log      # for Elements logging support
from DmModule.DmInput_python import *            # for DmInput
from DmModule.DmOutput_python import *           # for DmOutput
from DmModule.Parameters_python import *         # for parameters
import subprocess

def defineSpecificProgramOptions():
    """
    @brief Allows to define the (command line and configuration file) options
    specific to this program

    @details
        See the Elements documentation for more details.
    @return
        An  ArgumentParser.
    """

    parser = argparse.ArgumentParser()

    parser.add_argument('--in_xml_file', type=str,
                        help='A file containing the input XML product')
    parser.add_argument('--output_xml_file', type=str,
                        help='The file to store the output XML product')
    parser.add_argument('--workdir', type=str,
                        help='The The input parameter file in xml format')
    parser.add_argument('--parameter_file', type=str,
                        help='The root working directory where the data is located')
    return parser

def mainMethod(args):
    """
    @brief The "main" method.
    @details
        This method is the entry point to the program. In this sense, it is
        similar to a main (and it is why it is called mainMethod()).
    """

    logger = log.getLogger('DmProgram')

    logger.info('#')
    logger.info('# Entering DmProgram mainMethod()')
    logger.info('#')

    #
    #  Get the workdir and the data_dir
    #
    workdir = args.workdir
    data_dir = workdir + os.sep + 'data'
    #
    # Check for the existence of the.input XML product file and
    #            throw an Elements exception if it does not exist
    #
    if not os.path.exists(workdir + os.sep + args.in_xml_file):
        raise Exception("Input XML data product " + workdir + os.sep + args.in_xml_file + " not found")
    logger.info('Using file ' + workdir + os.sep + args.in_xml_file + ' as DM input product')

    #
    # Read inputs from the XML file i.e.:
    # 	   the filename of the FITS catalog
    in_xml = DmInput.readFile(workdir + os.sep + args.in_xml_file)
    
    logger.info('Using file ' + data_dir + os.sep + in_xml.getFitsCatalogFilename() + ' as input FITS catalog')
    inputFile = 'data' + os.sep + in_xml.getFitsCatalogFilename();

    #
    # Check for the existence of the input parameter XML file and
    #		throw an Elements exception if it does not exist
    if not os.path.exists(workdir + os.sep + args.parameter_file):
        raise Exception("Input XML data product " + workdir + os.sep + args.parameter_file + " not found")
    logger.info('Using file ' + workdir + os.sep + args.parameter_file + ' as input Parameter product')

    #
    # Read the parameters from the input xml parameter file
    #

    param = Parameters()
    param.readParameterFile(workdir + os.sep + args.parameter_file)

    #
    # Execute the processing function algorithm
    #

    ShearMap = "DevWS_ShearMap.fits"
    args1 = "--workdir=" + workdir
    args2 = "--paramFile=" + args.parameter_file
    args3 = "--input_ShearCatalog=" + inputFile
    args4 = "--outShearMap=" + ShearMap
    commandLine = ["LE3_2D_MASS_WL_CartesianMapMaker", args1, args2, args3, args4]
    subprocess.call(commandLine, shell=False)

    #
    # Generate the output XML product
    #
    DmOutput.createOutputXml(workdir + os.sep + args.output_xml_file, ShearMap)

    logger.info('DM output products created in: ' +
                workdir + os.sep + args.output_xml_file)
      
    logger.info('Done!')

    logger.info('#')
    logger.info('# Exiting DmProgram mainMethod()')
    logger.info('#')
