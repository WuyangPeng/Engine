///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/29 17:47)

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
