/**
 * @file src/program/DmProgram.cpp
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

#include <map>
#include <string>

#include <boost/program_options.hpp>
#include "ElementsKernel/ProgramHeaders.h"
#include <boost/filesystem.hpp>

#include "DmModule/DmInput.h"
#include "DmModule/DmOutput.h"

#include "DmModule/Parameters.h"

using boost::program_options::options_description;
using boost::program_options::variable_value;
using namespace DmModule;

namespace po = boost::program_options;
namespace fs = boost::filesystem;
using namespace std;

class DmProgram : public Elements::Program {

public:

  options_description defineSpecificProgramOptions() override {
  
    options_description options {};
   options.add_options()
   ("workdir", po::value<string>()->default_value(""), "The root working directory where the data is located");
   options.add_options()
   ("input_xml_file", po::value<string>()->default_value(""), "The input file in xml format");
   options.add_options()
   ("parameter_file", po::value<string>()->default_value(""), "The input parameter file in xml format");
   options.add_options()
   ("output_xml_file", po::value<string>()->default_value(""), "The output file in xml format");

    return options;
  }

  Elements::ExitCode mainMethod(std::map<std::string, variable_value>& args) override {

    Elements::Logging logger = Elements::Logging::getLogger("DmProgram");

    logger.info("#");
    logger.info("# Entering mainMethod()");
    logger.info("#");

    fs::path workdir {args["workdir"].as<string>()};
    fs::path data_dir {workdir / "data"};

    //
    // Check for the existence of the input XML product file and
    //			throw an Elements exception if it does not exist
    //
    fs::path in_xml_file {args["input_xml_file"].as<string>()};
    if (!fs::exists(workdir / in_xml_file)) {
    	throw Elements::Exception() << "Input XML data product " << workdir / in_xml_file << " not found";
    }
    logger.info() << "Using file " << workdir / in_xml_file << " as DM input product";

    // Read inputs from the XML file i.e.:
    // 		the filename of the FITS catalog

    DmInput in_xml = DmInput::readFile(workdir / in_xml_file);

    logger.info() << "Using file " << data_dir / in_xml.getFitsCatalogFilename() << " as FITS input catalog";
    std::string inCatalog = ("data" / in_xml.getFitsCatalogFilename()).string(); 
    //
    // Check for the existence of the input parameter XML file and
    //			throw an Elements exception if it does not exist
    //
    fs::path parameter_file {args["parameter_file"].as<string>()};
    if (!fs::exists(workdir / parameter_file)) {
    	throw Elements::Exception() << "Input XML data product " << workdir / parameter_file << " not found";
    }
    logger.info() << "Using file " << workdir / parameter_file << " as DM input parameter product";

    //
    // Read the parameters from the input xml parameter file
    //
    Parameters param;
    param = param.readParameterFile(workdir / parameter_file);

    //
    // Execute the processing function algorithm
    //
     fs::path out_fits_file = fs::path("DevWS_ShearMap.fits");
     system(("E-Run LE3_2D_MASS_WL_KS 2.4.0 LE3_2D_MASS_WL_CartesianMapMaker --workdir=" + workdir.string() + " --paramFile=" +
           parameter_file.string() + " --input_ShearCatalog=" + inCatalog + " --outShearMap="
           + out_fits_file.string()).c_str());

  // --------------------------------------------------------------
  // Exercise
  // --------------------------------------------------------------
    //
    // Generate the output XML product
    //
    auto out_xml_file = args["output_xml_file"].as<string>();

    DmOutput::createOutputXml(workdir / out_xml_file, out_fits_file);

    logger.info() << "DM output products created in: " << workdir / out_xml_file;

    logger.info("Done!");

    logger.info("#");
    logger.info("# Exiting mainMethod()");
    logger.info("#");

    return Elements::ExitCode::OK;
  }

};

MAIN_FOR(DmProgram)
