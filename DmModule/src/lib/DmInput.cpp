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

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Parse the file in_xml_filename in a binding object.

  logger.warn() << "TODO: Parse the file " << in_xml_filename
                << " in a binding object";

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Log a message with the type of the binding object

  logger.warn() << "TODO: Log the type of the object";

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
  // Populate the variables catalog_file
  logger.warn() << "TODO: Populate the variables catalog_file";
  fs::path catalog_file;
  return DmInput(catalog_file);
}

 DmInput::DmInput(const fs::path& catalog_file)
      : m_catalog_file{catalog_file} {
 }

 fs::path DmInput::getFitsCatalogFilename() const {
  return m_catalog_file;
 }
}  // namespace DmModule
