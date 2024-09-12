/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/12 16:15)

#ifndef CORE_TOOLS_CHARACTER_STRING_BASE64_H
#define CORE_TOOLS_CHARACTER_STRING_BASE64_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Base64
    {
    public:
        using ClassType = Base64;

    public:
        NODISCARD static std::string Encode(const std::string& input);
        NODISCARD static std::string Decode(const std::string& input);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_BASE64_H