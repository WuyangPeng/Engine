///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/29 17:47)

#include "CoreTools/CoreToolsExport.h"

#include "CaseInsensitiveString.h"
#include "StringConversion.h"

#include <iostream>

using std::ostream;
using std::string;
using std::wstring;

std::ostream& CoreTools::operator<<(std::ostream& os, const CaseInsensitiveString& str)
{
    return os << string{ str.c_str(), str.size() };
}

std::ostream& CoreTools::operator<<(std::ostream& os, const CaseInsensitiveWString& str)
{
    return os << StringConversion::WideCharConversionMultiByte(wstring{ str.c_str(), str.size() });
}
