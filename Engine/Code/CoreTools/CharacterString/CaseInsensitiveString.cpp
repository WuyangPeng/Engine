/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "CaseInsensitiveString.h"
#include "StringConversion.h"

#include <iostream>

std::ostream& CoreTools::operator<<(std::ostream& os, const CaseInsensitiveString& str)
{
    return os << std::string{ str.c_str(), str.size() };
}

std::ostream& CoreTools::operator<<(std::ostream& os, const CaseInsensitiveWString& str)
{
    return os << StringConversion::WideCharConversionMultiByte(std::wstring{ str.c_str(), str.size() });
}
