/**
 * @file src/lib/DmOutput.cpp
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

#include "DmModule/DmOutput.h"

namespace fs = boost::filesystem;

// DM Output namespace and classes
//==============================================================================================
// Tip: Be careful with nested namespace
//==============================================================================================
using namespace dpd::le3::wl::twodmass::out::convergencepatch;
using Euclid::DataModel::GenericHeaderGenerator;

static Elements::Logging logger = Elements::Logging::getLogger("DmOutput");

namespace DmModule {

 Euclid::DataModel::GenericHeaderGenerator* DmOutput::GetGenericHeader() {
    const std::string productType = "DevWSProduct";

	GenericHeaderGenerator* generator = new GenericHeaderGenerator("DevWSProduct");
    generator->setTagValue("ProdSDC", "SDC-FR");
    generator->setTagValue("SoftwareName", "2D-MASS-WL");
    generator->setTagValue("Curator", "LOCAL");

    return generator;
 }

void DmOutput::createOutputXml(const boost::filesystem::path& out_xml_filename,
                               const boost::filesystem::path& fits_out_filename) {
  logger.info() << "Creating PF output XML product in file " << out_xml_filename << "...";

  //
  // Exercise
  // ---------------------------------------------------------
  // Create a data container pointing to the fits_out_filename. Assign it to
  // the a variable named "output".
    logger.warn() << "Create a data container pointing to the" << fits_out_filename << "......";
    boost::filesystem::path fits_file {fits_out_filename};
    sys::dss::dataContainer output (fits_file.filename().string(), "PROPOSED");

  // Create the Generic header of output file
     GenericHeaderGenerator* generator = GetGenericHeader();
     generator->changeProductType("DpdTwoDMassConvergencePatch");
     sys::genericHeader *header = generator->generate();

  // Exercise
  // ---------------------------------------------------------
  // Create the Output Map element (which is optional)
     pro::le3::wl::twodmass::twoDMassConvergencePatch NoisyMap(output, "le3.wl.2dmass.output.patchconvergence",
                                                              "0.1");

  // Exercise
  // ---------------------------------------------------------
  // Create the Data element
     pro::le3::wl::twodmass::twoDMassCollectConvergencePatch data(0);//NreSamples not needed

  // Exercise
  // ---------------------------------------------------------
  // Create the product XML root element / Create the final object
     dpd::le3::wl::twodmass::out::convergencepatch::dpdTwoDMassConvergencePatch product(*header, data);

  //
  // Exercise
  // ---------------------------------------------------------
  // Create the optional output Map element
  //
     product.Data().NoisyConvergence(pro::le3::wl::twodmass::twoDMassCollectConvergencePatch::NoisyConvergence_type{NoisyMap});
     auto& noisemaplist = product.Data().NoisyConvergence().get().DataContainer();
     noisemaplist.FileName(fits_out_filename.string());

  //
  // Exercise
  // ---------------------------------------------------------
  // Create the file out_xml_filename with the XML representing the product
  //
     std::ofstream out;
     out.open (out_xml_filename.string());
     dpd::le3::wl::twodmass::out::convergencepatch::DpdTwoDMassConvergencePatch(out, product);

  logger.info() << "Finished creating file " << out_xml_filename;
}

}  // namespace DmModule



