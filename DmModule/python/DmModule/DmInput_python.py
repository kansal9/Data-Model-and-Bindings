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
File: python/DmModule/DmInput_python.py

Created on: 09/21/20
Author: user
"""

import argparse
import ElementsKernel.Logging as log

import ST_DataModelBindings.dpd.le3.wl.twodmass.inp.raw.lensmccatalog_stub as lensCat

class DmInput:
      @staticmethod
      def readFile(in_xml_filename):
            logger = log.getLogger('DmInput')
            logger.info('Getting information from input product XML file ' + in_xml_filename + '...')
        
            # Parse the XML file and create the binding object
            logger.debug('Parsing file ' + in_xml_filename + '...')
            
            #
            # Exercise
            # ------------------------------------------------------
            # Parse the file in_xml_filename in a binding object
            # Read the xml file as a string
            with open(in_xml_filename, "r") as f:
                xml_string = f.read()
            #in_xml = lensCat.CreateFromDocument(file(in_xml_filename).read())
            in_xml = lensCat.CreateFromDocument(xml_string)
            logger.debug('Binding object created successfully')
            #
            # Exercise
            # --------------------------------------------------
            # Log a message with the type of the binding object
            #
            logger.debug('The type of the binding object is: ' +
                        str(type(in_xml)))

            # Exercise
            # -------------------------------------------------------------
            # Populate the variables catalog_file
            #
            catalog_file = ''

            # Get the name of the FITS file containing the catalog
            catalog_file = in_xml.Data.ShearCatalog.DataContainer.FileName
            logger.debug('Found FITS catalog filename ' + catalog_file + ' in input XML')

            return DmInput(catalog_file)

      def __init__(self, catalog_file):
            self._catalog_file = catalog_file
    
      def getFitsCatalogFilename(self):
            return self._catalog_file
