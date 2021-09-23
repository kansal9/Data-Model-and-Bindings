/**
 * @file DmModule/Parameters.h
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

#ifndef _DMMODULE_PARAMETERS_H
#define _DMMODULE_PARAMETERS_H

#include <string>
#include <boost/filesystem.hpp>
#include "ElementsKernel/Logging.h"

//==============================================================================================
// EXERCISE
//==============================================================================================
// Include the headers file with the bindings for the DevwsInput parameter file.
//==============================================================================================
// Tip: You can just uncomment the line below
//==============================================================================================
#include "ST_DataModelBindings/dpd/le3/wl/twodmass/inp/euc-test-le3-wl-twodmass-ParamsConvergencePatch.h"

namespace DmModule {

/**
 * @class Parameters
 * @brief
 *
 */
class Parameters {

public:

  /**
   * @brief   Default empty constructor
   * @return  Empty object of class Parameters
  */
  Parameters();

  /**
   * @brief    Constructor from parameters
   * @param    <NItReducedShear> Number of iterations to perform ReducedShear algorithm [default: 0 (Runs KS)]
   * @param    <nbPatches> number of patches
   * @param    <PixelSize> pixelSize in arcminute
   * @param    <PatchWidth> MapSize/PatchWidth in degrees
   * @param    <mapCenterX> Center of Map at X-axis in degrees
   * @param    <mapCenterY> Center of Map at Y-axis in degrees
   * @param    <nbZBins> number of redshift bins
   * @param    <zMin> zMin
   * @param    <zMax> zMax
   * @param    <BalancedBins> parameter to trigger the equal number of galaxies in a patch
   * @param    <NInpaint> Number of iterations to perform Inpainting algorithm [default: 0 (Runs KS)]
   * @param    <EqualVarPerScale> 1: set variance inside the mask is inforced to be equal to the variance outside
   *            the mask at different scales
   * @param    <ForceBModes> Set 1: to force B-modes to be zero inside the mask
   * @param    <nbScales> number of scales for the sigmaBounded constraint [Inpainting option: default is automatic]
   * @param    <add_borders> Set 0: not to add borders to the map / 1: to add borders to the map
   * @param    <RSsigmaGauss> Reduced shear denoising: Value of Sigma for gaussian filter
   * @param    <sigmaGauss> Final denoising: Value of Sigma for gaussian filter
   * @param    <RSthresholdFDR> Reduced shear denoising: Threshold for MRLens Filter 
   * @param    <thresholdFDR> Final denoising: Threshold for MRLens filtering
   * @param    <nbSamples> Number of samples for error calculations
   * @return   Fully allocated parameters
  */
  Parameters(int NItReducedShear, int NPatches, float PixelSize, float PatchWidth, std::vector<double> mapCenterX,
          std::vector<double> mapCenterY, int nbZBins, std::vector<double> zMin, double zMax, long BalancedBins,
          int NInpaint, long EqualVarPerScale, long ForceBMode, int nbScales, long add_borders, float RSsigmaGauss,
          float sigmaGauss, int nbSamples, float RSthresholdFDR = 0.0, float thresholdFDR = 0.0);

  /**
   * @brief Destructor
   */
  virtual ~Parameters() = default;

  /**
   * @brief   function to read the parameter file in XML wrt dpd
   * @param   <paramfile> input parameter filename
   * @return  parameters from the file
  */
  Parameters readParameterFile (const boost::filesystem::path& parameter_file);

  /**
   * @brief   function to return zMin value
   * @return  Minimum Redshift (Z) value from Parameter file
  */
  std::vector<double> getZMin();

  /**
   * @brief   function to return zMax value
   * @return  Maximum Redshift (Z) value from Parameter file
  */
  double getZMax();

  /**
   * @brief   function to return PixelSize value
   * @return  PixelSize from Parameter file
  */
  float getPixelsize();

  /**
   * @brief   function to return Sigma value for Map from Parameter file
   * @return  Sigma value
  */
  float getSigmaGauss();

  /**
   * @brief   function to return Sigma value for gaussian filtering in case of reduce shear
  */
  float getRSSigmaGauss();

  /**
   * @brief   function to return Threshold from Parameter file
   * @return  Threshold
  */
  float getThreshold();

  /**
   * @brief   function to return threshold for filtering
  */
  float getRSThreshold();

  /**
   * @brief   function to return number of catalogs based on Redshift bins from Parameter file
   * @return  Redshift bins
  */
  int getnbZBins();

  /**
   * @brief   function to return number of catalogs based on number of galaxies from Parameter file
   * @return  number of catalogs based on number of galaxies
  */
  int getnbPatches();

  /**
   * @brief   function to return number of Scales from Parameter file
   * @return  number of scales
  */
  int getnbScales();

  /**
   * @brief   function to return Iteration numbers from Parameter file
   * @return  number of iteration to perform inpainting
  */

  int getNInpaint();

  /**
   * @brief   function to return Iteration numbers from Parameter file
   * @return  number of iteration to perform inpainting
  */
  int getNItReducedShear();

  /**
   * @brief   function to return add borders setting from Parameter file
   * @return  add borders setting to/not to add borders to map
  */
  long get_addBorders();

  /**
   * @brief   function to return sigma bound setting from Parameter file
   * @return  sigma bound setting to force variance inside the mask is to be equal to the variance outside
   *           the mask at different scales
  */
  long getEqualVarPerScale();

  /**
   * @brief   function to return BmodesZeros value from Parameter file
   * @return  SquareMap to/not to force B-modes to be zero inside the mask
  */
  long getForceBMode();

  /**
   * @brief   function to return MapSize/PatchWidth in degrees from Parameter file
   * @return  MapSize in degrees
  */
  float getPatchWidth();

  /**
   * @brief   function to return MapCenter at X-axis (Ra) from Parameter file
   * @return  MapCenter at X-axis
  */
  std::vector<double> getMapCenterX();

  /**
   * @brief   function to return MapCenter at Y-axis (Dec) from Parameter file
   * @return  MapCenter at Y-axis
  */
  std::vector<double> getMapCenterY();

  /**
   * @brief   function to return number of SNR maps needed from Parameter file
   * @return  Number of samples
  */
  int getNSamples();

  /**
   * @brief   function to return balanced number of galaxies
   * @return  1: balanced galaxies needed 0: not needed
  */
  long get_BalancedBins();

private:
double m_zMax;
float m_sigmaGauss, m_thresholdFDR, m_PatchWidth, m_PixelSize;
float m_RSsigmaGauss, m_RSthresholdFDR;
std::vector<double> mapCenterX;
std::vector<double> mapCenterY;
std::vector<double> m_zMin;
//std::vector<double> m_zMax;
int m_nbZBins, m_NInpaint, m_nbScales, m_NItReducedShear, m_nbPatches, m_nbSamples;

long m_add_borders, m_ForceBMode, m_EqualVarPerScale, m_balancedBin;
};  // End of Parameters class

}  // namespace DmModule


#endif
