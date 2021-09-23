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
File: python/DmModule/DmInput.py

Created on: 09/21/20
Author: user
"""

import argparse
import ElementsKernel.Logging as log

# --------------------------------------------------------------
# Exercise
# --------------------------------------------------------------
# Import the module which contains the bindings
# Tip: You can just uncomment the line below
#from ST_DataModelBindings.dpd.le3.wl.twodmass.inp.raw.lensmccatalog_stub as lensCat

@staticmethod
    def readFile(in_xml_filename):
        logger = log.getLogger('DmInput')
        logger.info('Getting information from input product XML file ' + in_xml_filename + '...')
        
        # Parse the XML file and create the binding object
        logger.debug('Parsing file ' + in_xml_filename + '...')
        
        #
        # Exercise
        # ------------------------------------------------------
        # Parse the file in_dm_xml_filename in a binding object

        logger.warn('TODO: Parse the file ' + in_xml_filename +
                    ' in a binding object')
        
        #
        # Exercise
        # --------------------------------------------------
        # Log a message with the type of the binding object
        #
        logger.warn('TODO: Log the type of the object')
#
        # Exercise
        # -------------------------------------------------------------
        # Populate the variables catalog_file
        #
        logger.warn('TODO: Populate the variables catalog_file')
        catalog_file = ''

        return DmInput(catalog_file)

  def __init__(self, catalog_file):
        self._catalog_file = catalog_file
    
  def getFitsCatalogFilename(self):
        return self._catalog_file
