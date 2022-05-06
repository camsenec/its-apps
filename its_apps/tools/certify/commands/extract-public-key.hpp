/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/certify/commands/extract-public-key.hpp>
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

#ifndef CERTIFY_COMMANDS_EXTRACT_PUBLIC_KEY_HPP
#define CERTIFY_COMMANDS_EXTRACT_PUBLIC_KEY_HPP

#include "command.hpp"

class ExtractPublicKeyCommand : public Command
{
public:
    bool parse(const std::vector<std::string>&) override;
    int execute() override;

private:
    std::string output;
    std::string certificate_path;
    std::string private_key_path;
};

#endif /* CERTIFY_COMMANDS_EXTRACT_PUBLIC_KEY_HPP */
