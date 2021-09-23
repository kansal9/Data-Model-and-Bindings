/**
 * @file src/lib/Parameters.cpp
 * @date 09/22/20
 * @author user
 *
 * @copyright (C) 2012-2020 Euclid Science Ground Segment
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 3.0 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "DmModule/Parameters.h"

static Elements::Logging logger = Elements::Logging::getLogger("Parameters");

namespace DmModule {

 Parameters::Parameters():m_NItReducedShear(10), m_nbPatches(1), m_PixelSize( 0.586/60.), m_PatchWidth(10.),
           mapCenterX(0.), mapCenterY(0.), m_nbZBins(1), m_zMin(0.), m_zMax(10.), m_balancedBin(0),
           m_NInpaint(100), m_EqualVarPerScale(0), m_ForceBMode(1), m_nbScales(0), m_add_borders(0),
           m_sigmaGauss(0.), m_thresholdFDR(0.), m_nbSamples(0), m_RSsigmaGauss(0.), m_RSthresholdFDR(0.)
 { }

 Parameters::Parameters(int NItReducedShear, int NPatches, float PixelSize, float PatchWidth, std::vector<double> mapCenterX,
          std::vector<double> mapCenterY, int nbZBins, std::vector<double> zMin, double zMax, long BalancedBins,
          int NInpaint, long EqualVarPerScale, long ForceBMode, int nbScales, long add_borders, float RSsigmaGauss,
          float sigmaGauss, int nbSamples, float RSthresholdFDR, float thresholdFDR): m_NItReducedShear(NItReducedShear), m_nbPatches(NPatches),
           m_PixelSize(PixelSize/60.), m_PatchWidth(10.), mapCenterX(mapCenterX), mapCenterY(mapCenterY),
           m_nbZBins(nbZBins), m_zMin(zMin), m_zMax(zMax), m_balancedBin(BalancedBins),
           m_NInpaint(NInpaint), m_EqualVarPerScale(EqualVarPerScale), m_ForceBMode(ForceBMode),
           m_nbScales(nbScales), m_add_borders(add_borders), m_RSsigmaGauss(RSsigmaGauss), m_sigmaGauss(sigmaGauss),
           m_thresholdFDR(thresholdFDR), m_RSthresholdFDR(RSthresholdFDR), m_nbSamples(nbSamples) { }

 Parameters Parameters::readParameterFile (const boost::filesystem::path& parameter_file){
  logger.info() << "Getting information from input Parameter XML file " << parameter_file << " ...";
  logger.debug() << "Parsing file " << parameter_file << " ...";

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Parse the file in_xml_filename in a binding object.

  logger.warn() << "TODO: Parse the file " << parameter_file
                << " in a binding object";
   //auto Param_xml = dpd::le3::wl::twodmass::inp::paramsconvergencepatch::DpdTwoDMassParamsConvergencePatch
   //                     (parameter_file, xml_schema::flags::dont_validate);

  // Exercise
  // -------------------------------------------------------
  // Get and log the Parameters from the input parameter file

  logger.warn() << "TODO: Get and log the Parameters from the input parameter file";

  // Exercise
  // -------------------------------------------------------
  // Check if the optional element ThresholdFDR exists in the XML
  logger.warn() << "TODO: Check if the ThresholdFDR element exists";

   if (true) {

    logger.debug() << "The ThresholdFDR element is present";

    logger.warn() << "TODO: Log the value of the ThresholdFDR element";

  }

    // sometimes parameter can appear more than one time, its corresponding method returns a sequence
   // Iterate over individual records.
    //
    //Exercise
    // ------------------------------------------------------
    // Log the values of the elements
    //
    // Tip: The special sequence type is iterable
    //
    logger.warn() << "TODO: Log the values of the elements";

 return Parameters(m_NItReducedShear, m_nbPatches, m_PixelSize, m_PatchWidth, mapCenterX, mapCenterY, m_nbZBins,
            m_zMin, m_zMax, m_balancedBin, m_NInpaint, m_EqualVarPerScale, m_ForceBMode, m_nbScales, m_add_borders,
            m_RSsigmaGauss, m_sigmaGauss, m_nbSamples, m_RSthresholdFDR, m_thresholdFDR);
 }

 std::vector<double> Parameters::getZMin(){ return m_zMin; }
 double Parameters::getZMax(){ return m_zMax; }
 float Parameters::getPixelsize(){ return m_PixelSize; }
 float Parameters::getSigmaGauss(){ return m_sigmaGauss; }
 float Parameters::getThreshold(){return m_thresholdFDR; }
 float Parameters::getRSSigmaGauss(){ return m_RSsigmaGauss; }
 float Parameters::getRSThreshold(){return m_RSthresholdFDR; }
 int Parameters::getnbZBins(){ return m_nbZBins; }
 int Parameters::getnbPatches(){ return m_nbPatches; }
 int Parameters::getNInpaint(){ return m_NInpaint; }
 int Parameters::getNItReducedShear(){ return m_NItReducedShear; }
 int Parameters::getnbScales(){ return m_nbScales; }
 float Parameters::getPatchWidth(){ return m_PatchWidth; }
 std::vector<double> Parameters::getMapCenterX(){ return mapCenterX; }
 std::vector<double> Parameters::getMapCenterY(){ return mapCenterY; }
 int Parameters::getNSamples() { return m_nbSamples;}

 long Parameters::get_addBorders(){
  return m_add_borders;
 }
 long Parameters::getEqualVarPerScale(){
  return m_EqualVarPerScale;
 }
 long Parameters::getForceBMode(){
  return m_ForceBMode;
 }
 long Parameters::get_BalancedBins(){
  return m_balancedBin;
 }

}  // namespace DmModule
