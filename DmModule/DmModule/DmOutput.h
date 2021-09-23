/**
 * @file DmModule/DmOutput.h
 * @date 09/21/20
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

#ifndef _DMMODULE_DMOUTPUT_H
#define _DMMODULE_DMOUTPUT_H

#include <string>
#include <boost/filesystem.hpp>

#include "ElementsKernel/Logging.h"
//==============================================================================================
// EXERCISE
//==============================================================================================
// Include the headers file with the bindings and tools to write output XML file.
// GenericHeader to write header in XML file
//==============================================================================================
// Tip: You can just uncomment the lines below
//==============================================================================================
#include "ST_DataModelBindings/dpd/le3/wl/twodmass/out/euc-test-le3-wl-twodmass-ConvergencePatch.h"

#include "ST_DM_HeaderProvider/GenericHeaderProvider.h"

namespace DmModule {

/**
 * @class DmOutput
 * @brief
 *
 */
class DmOutput {

public:

  /**
   * @brief Destructor
   */
  virtual ~DmOutput() = default;

  static Euclid::DataModel::GenericHeaderGenerator* GetGenericHeader();

  static void createOutputXml(const boost::filesystem::path& out_xml_filename,
      const boost::filesystem::path& fits_out_filename);

private:

};  // End of DmOutput class

}  // namespace DmModule


#endif
