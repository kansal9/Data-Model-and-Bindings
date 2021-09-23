/**
 * @file src/lib/DmInput.cpp
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

#include "DmModule/DmInput.h"

namespace fs = boost::filesystem;
static Elements::Logging logger = Elements::Logging::getLogger("DmInput");

namespace DmModule {

DmInput DmInput::readFile(const boost::filesystem::path& in_xml_filename) {
  logger.info() << "Getting information from input product XML file " << in_xml_filename << " ...";
  // Parse the XML file and create the binding object
  logger.debug() << "Parsing file " << in_xml_filename << " ...";

  //
  // Exercise
  // --------------------------------------------------------------
  // Parse the file in_xml_filename in a binding object.

  auto in_xml = dpd::le3::wl::twodmass::inp::lensmccatalog::DpdTwoDMassLensMCCatalog
                       (in_xml_filename.string(), xml_schema::flags::dont_validate);
  logger.debug("Binding object created successfully");

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Log a message with the type of the binding object
  logger.debug() << "The type of the binding object is: " 
                 << typeid(in_xml).name();

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Populate the variables catalog_file
  // Define Variable to store Catalog filename
  fs::path catalog_file {};
  // Get the name of the FITS file containing the catalog
  catalog_file = in_xml->Data().ShearCatalog().DataContainer().FileName();
  logger.debug() << "Found FITS catalog filename " << catalog_file << " in input XML";
 // logger.info()<< "Found FITS catalog filename: " << in_xml->Data().ShearCatalog().DataContainer().FileName();
  return DmInput(catalog_file);
}

 DmInput::DmInput(const fs::path& catalog_file)
      : m_catalog_file{catalog_file} {
 }

 fs::path DmInput::getFitsCatalogFilename() const {
  return m_catalog_file;
 }

}  // namespace DmModule
