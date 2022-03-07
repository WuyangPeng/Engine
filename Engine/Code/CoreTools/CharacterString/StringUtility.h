///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/13 14:18)

#ifndef CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H
#define CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H

#include "CoreTools/CoreToolsDll.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE StringUtility final
    {
    public:
        using ClassType = StringUtility;
        using TokensType = std::vector<std::string>;

    public:
        NODISCARD static std::wstring ConvertNarrowToWide(const std::string& input);
        NODISCARD static std::string ConvertWideToNarrow(const std::wstring& input);
        NODISCARD static std::string ToLower(const std::string& input);
        NODISCARD static std::string ToUpper(const std::string& input);
        NODISCARD static TokensType GetTokens(const std::string& input, const std::string& whiteSpace);
        NODISCARD static TokensType GetTextTokens(const std::string& input);
        NODISCARD static TokensType GetAdvancedTextTokens(const std::string& input);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H
