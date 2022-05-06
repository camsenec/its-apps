/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/certify/utils.cpp>
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

#include "utils.hpp"
#include <cstdint>
#include <stdexcept>
#include <sstream>

void permission_string_to_buffer(const std::string& in, vanetza::ByteBuffer& out)
{
    if (in.size() / 8 != out.size() - 1 /* version */) {
        std::stringstream ss;
        ss << "Size mismatch, expected " << (out.size() - 1) << " bytes encoded with one bit per byte.";
        throw std::runtime_error(ss.str());
    }

    uint8_t byte = 0;
    int index = 0;

    for (auto it = in.begin(); it < in.end(); ++it) {
        byte <<= 1;

        if (*it == '0') {
            byte &= 0xFE; // clear last bit
        } else if (*it == '1') {
            byte |= 1; // set last bit
        } else {
            throw std::runtime_error("Unexpected character in permissions, expected only '0' and '1'.");
        }

        if ((index + 1) % 8 == 0) {
            out.at(1 /* version */ + (index / 8)) = byte;
            byte = 0;
        }

        ++index;
    }
}
