/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/certify/commands/generate-key.cpp>
 * at 2022-05-06.
 * 
 * This file is part of its_apps.
 *
 * its_apps is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or 
 * any later version.
 * its_apps is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License and 
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * and GNU Lesser General Public License along with its_apps. 
 * If not, see <https://www.gnu.org/licenses/>. 
 */

#include "generate-key.hpp"
#include <boost/program_options.hpp>
#include <cryptopp/eccrypto.h>
#include <cryptopp/files.h>
#include <cryptopp/oids.h>
#include <cryptopp/osrng.h>
#include <cryptopp/queue.h>
#include <cryptopp/sha.h>
#include <iostream>
#include <stdexcept>

namespace po = boost::program_options;
using namespace CryptoPP;

bool GenerateKeyCommand::parse(const std::vector<std::string>& opts)
{
    po::options_description desc("Available options");
    desc.add_options()
        ("help", "Print out available options.")
        ("output", po::value<std::string>(&output)->required(), "Output file.")
    ;

    po::positional_options_description pos;
    pos.add("output", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(opts).options(desc).positional(pos).run(), vm);

    if (vm.count("help")) {
        std::cerr << desc << std::endl;

        return false;
    }

    try {
        po::notify(vm);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl << std::endl << desc << std::endl;

        return false;
    }

    return true;
}

int GenerateKeyCommand::execute()
{
    std::cout << "Generating key..." << std::endl;

    AutoSeededRandomPool rng;
    OID oid(CryptoPP::ASN1::secp256r1());
    ECDSA<ECP, SHA256>::PrivateKey private_key;
    private_key.Initialize(rng, oid);

    if (!private_key.Validate(rng, 3)) {
        throw std::runtime_error("Private key validation failed");
    }

    ByteQueue queue;
    private_key.Save(queue);
    CryptoPP::FileSink file(output.c_str());
    queue.CopyTo(file);
    file.MessageEnd();

    return 0;
}
