/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:21)

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
