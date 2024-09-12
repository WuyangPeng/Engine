/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/12 17:40)

#include "CoreTools/CoreToolsExport.h"

#include "Base64Encode.h"

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <sstream>

std::string CoreTools::Base64Encode::Encode(const std::string& input)
{
    using Base64EncodeIterator = boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<std::string::const_iterator, 6, 8>>;

    std::stringstream result{};
    std::copy(Base64EncodeIterator(input.begin()), Base64EncodeIterator(input.end()), std::ostream_iterator<char>(result));

    const auto padding = (3 - input.size() % 3) % 3;
    for (auto i = 0u; i < padding; ++i)
    {
        result.put('=');
    }

    return result.str();
}

std::string CoreTools::Base64Encode::Decode(const std::string& input)
{
    using BinaryIterator = boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<std::string::const_iterator>, 8, 6>;

    std::stringstream result;
    std::copy(BinaryIterator(input.begin()),
              BinaryIterator(input.end()),
              std::ostream_iterator<char>(result));

    std::string decoded = result.str();
    decoded.erase(decoded.find_last_not_of('\0') + 1);

    return decoded;
}