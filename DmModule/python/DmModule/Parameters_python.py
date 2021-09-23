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
File: python/DmModule/Parameters_python.py

Created on: 09/24/20
Author: user
"""

import argparse
import ElementsKernel.Logging as log
import pyxb
import ST_DataModelBindings.dpd.le3.wl.twodmass.inp.raw.paramsconvergencepatch_stub as param
import ST_DataModelBindings.pro.le3.wl.raw.twodmass_stub
import ST_DataModelBindings.pro.le3.raw.wl_stub

class Parameters:

     def readParameterFile(self, parameter_file):
            logger = log.getLogger('Parameters')
            logger.info(
                'Getting information from input parameter XML file ' + parameter_file + '...')

            # Parse the XML file and create the binding object
            logger.debug('Parsing file ' + parameter_file + '...')

            #
            # Exercise
            # ------------------------------------------------------
            # Parse the input parameter_file in a binding object
            with open(parameter_file, "r") as f:
                Param_xml_string = f.read()
            #Param_xml = param.CreateFromDocument(file(parameter_file).read())
            Param_xml = param.CreateFromDocument(Param_xml_string)
            logger.debug('Binding object created successfully')

            #
            # Exercise
            # ------------------------------------------------------
            # Get and log the Parameters from the input parameter file

            self.m_NInpaint = Param_xml.Data.GapsParams.NInpaint
            logger.info('Number of Inpainting iterations : ' + str(self.m_NInpaint))
            self.m_NItReducedShear = Param_xml.Data.ReducedShear.NItReducedShear
            logger.info(
                'Number of iterations for Reduced shear : ' + str(self.m_NItReducedShear))
            self.m_RSsigmaGauss = Param_xml.Data.ReducedShear.GaussSTD

            #
            # Exercise
            # ------------------------------------------------------
            # Check if the optional element ThresholdFDR exists in the XML

            # If an optional element is not present, it is set to None
            if Param_xml.Data.ReducedShear.ThresholdFDR:
               logger.debug('The XML file contains ThresholdFDR for reduced shear')
               self.m_RSthresholdFDR = Param_xml.Data.ReducedShear.ThresholdFDR
               logger.info('ThresholdFDR for reduced shear : ' + str(self.m_RSthresholdFDR))
            # ------------------------------------------------------
            # ------------------------------------------------------

            self.m_EqualVarPerScale = Param_xml.Data.GapsParams.EqualVarPerScale
            logger.info('Equal variance per scale : ' + str(self.m_EqualVarPerScale))
            self.m_ForceBMode = Param_xml.Data.GapsParams.ForceBMode
            logger.info('force B mode : ' + str(self.m_ForceBMode))
            self.m_nbScales = Param_xml.Data.GapsParams.NInpScale
            logger.info('m_nbScales : ' + str(self.m_nbScales))
            self.m_add_borders = Param_xml.Data.GapsParams.AddBorder
            logger.info('add borders : ' + str(self.m_add_borders))
            self.m_sigmaGauss = Param_xml.Data.DenoiseParams.GaussSTD
            logger.info('m_sigmaGauss: ' + str(self.m_sigmaGauss))
            if Param_xml.Data.DenoiseParams.ThresholdFDR:
                 self.m_thresholdFDR = Param_xml.Data.DenoiseParams.ThresholdFDR
                 logger.info('m_thresholdFDR: ' + str(self.m_thresholdFDR))

            # ------------------------------------------------------
            # ------------------------------------------------------
            self.m_nbZBins = Param_xml.Data.RedshiftBins.Nbins
            logger.info('m_nbZBins: ' + str(self.m_nbZBins))
            self.m_balancedBin = Param_xml.Data.RedshiftBins.BalancedBins
            logger.info('m_balancedBin: ' + str(self.m_balancedBin))
            for redshift_bin in Param_xml.Data.RedshiftBins.RedshiftBin:
                self.m_zMax = redshift_bin.ZMax
                self.m_zMin = redshift_bin.ZMin
                logger.info('m_zMax : ' + str(self.m_zMax))
                logger.info('m_zMin : ' + str(self.m_zMin))
            # sometimes parameter can appear more than one time, its corresponding method returns a sequence
            # Iterate over individual records.
            #
            # ------------------------------------------------------
            # Log the values of the elements
            #
            # Tip: The special sequence type is iterable
            #
            for patches in Param_xml.Data.PatchParams:
                self.m_nbPatches = patches.NPatches
                logger.info('m_nbPatches : ' + str(self.m_nbPatches))
                # If an element can appear more than one times, it is represented as a list
                for patchlist in patches.PatchList:
                  self.m_PatchWidth = patchlist.PatchWidth
                  logger.info('PatchWidth : ' + str(self.m_PatchWidth))
                  self.m_PixelSize = patchlist.PixelSize
                  logger.info('PixelSize : ' + str(self.m_PixelSize/60.))
                  self.CenterX = patchlist.ProjCtr.Longitude
                  self.CenterY = patchlist.ProjCtr.Latitude
                  logger.info('CenterX : ' + str(self.CenterX))
                  logger.info('CenterY : ' + str(self.CenterY))

            # ------------------------------------------------------
            # ------------------------------------------------------

     def __init__(self):
          """
          The entry point to create an an Fits keywords object.
          """
          self.m_NInpaint = 100
          self.m_NItReducedShear = 10
          self.m_nbPatches = 1
          self.m_PixelSize = 0.586/60.
          self.m_PatchWidth = 10
          self.mapCenterX = 0
          self.mapCenterY = 0
          self.m_nbZBins = 1
          self.m_zMin = 0
          self.m_zMax = 10
          self.m_balancedBin = 0
          self.m_EqualVarPerScale = 0
          self.m_ForceBMode = 0
          self.m_nbScales = 0
          self.m_add_borders = 0
          self.m_RSsigmaGauss = 0.
          self.m_sigmaGauss = 0.
          self.m_nbSamples = 0
          self.m_RSthresholdFDR = 0
          self.m_thresholdFDR = 0

     def getNInpaint(self):
          return self.m_NInpaint

     def getZMin(self):
          return self.m_zMin

     def getZMax(self):
          return self.m_zMax

     def getPixelsize(self):
          return self.m_PixelSize

     def getSigmaGauss(self):
          return self.m_sigmaGauss

     def getThreshold(self):
          return self.m_thresholdFDR

     def getRSSigmaGauss(self):
          return self.m_RSsigmaGauss

     def getRSThreshold(self):
          return self.m_RSthresholdFDR

     def getnbZBins(self):
          return self.m_nbZBins

     def getnbPatches(self):
          return self.m_nbPatches

     def getNItReducedShear(self):
          return self.m_NItReducedShear

     def getnbScales(self):
          return self.m_nbScales

     def getPatchWidth(self):
          return self.m_PatchWidth

     def getMapCenterX(self):
          return self.mapCenterX

     def getMapCenterY(self):
          return self.mapCenterY

     def getNSamples(self):
          return self.m_nbSamples

     def get_addBorders(self):
          return self.m_add_borders

     def getEqualVarPerScale(self):
          return self.m_EqualVarPerScale

     def getForceBMode(self):
          return self.m_ForceBMode

     def get_BalancedBins(self):
          return self.m_balancedBin
