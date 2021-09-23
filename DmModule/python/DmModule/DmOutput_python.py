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
File: python/DmModule/DmOutput_python.py

Created on: 09/24/20
Author: user
"""

import argparse
import os
import numpy
import ElementsKernel.Logging as log
import pyxb

from ST_DM_HeaderProvider.GenericHeaderProvider import GenericHeaderGenerator
import ST_DataModelBindings.dpd.le3.wl.twodmass.out.raw.convergencepatch_stub as out_devws
import ST_DataModelBindings.pro.le3.wl.raw.twodmass_stub as pro_devws
import ST_DataModelBindings.sys.raw.dss_stub as dss_devws


class DmOutput:

  @staticmethod
  def createOutputXml (output_xml_file, fits_filename):
        logger = log.getLogger('DmOutput')
        logger.info('Creating PF output XML product in file '+output_xml_file+'...')
        # For each complexType defined in the XSD files there is a corresponding class
        # with the same name. Each sub-element in the XSD files is represented with a
        # member variable with the same name. The type of the member variable is the one
        # corresponding to the type of the sub-element.
      
        # Note that creating the output binding class has to be done in a bottom-up approach
        # Exercise
        # ---------------------------------------------------------
        # Create a data container pointing to the fits_filename. Assign it to
        # the a variable named "output".
        # The file name of the data
        # container should not include any path and by default all pipelines should set the
        # filestatus to "PROPOSED".
        #

        output = dss_devws.dataContainer.Factory()
        output.FileName = os.path.basename(fits_filename)
        output.filestatus = 'PROPOSED'

        # Create the Generic header of output file

        generator = GenericHeaderGenerator(product_type='DpdTwoDMassConvergencePatch')
        generator.set_tag_value("ProdSDC", "SDC-FR")
        generator.set_tag_value("SoftwareName", "2D-MASS-WL")
        generator.set_tag_value("Curator", "LOCAL")
        header = generator.generate()

        # Exercise
        # ---------------------------------------------------------
        # Create the Output Map element
        NoisyMap = pro_devws.twoDMassConvergencePatch.Factory()
        NoisyMap.DataContainer = output
        NoisyMap.format = 'le3.wl.2dmass.output.patchconvergence'
        NoisyMap.version = '0.1'

        # Exercise
        # ---------------------------------------------------------
        # Create the Data element
        data = pro_devws.twoDMassCollectConvergencePatch.Factory()
        value = 0
        data.NResamples = value

        #
        #  Exercise
        # ---------------------------------------------------------
        # Create the optional output Map element
        #
        data.NoisyConvergence = NoisyMap
        # Exercise
        # ---------------------------------------------------------
        # Create the product XML root element / Create the final object
        product = out_devws.DpdTwoDMassConvergencePatch()
        product.Header = header
        product.Data = data

        #
        # Exercise
        # ---------------------------------------------------------
        # Create the file out_xml_filename with the XML representing the product
        #
        with open(output_xml_file, 'w') as out:
            out.write(product.toDOM().toprettyxml(encoding="utf-8").decode("utf-8"))
        logger.info('Finished creating file '+output_xml_file)



