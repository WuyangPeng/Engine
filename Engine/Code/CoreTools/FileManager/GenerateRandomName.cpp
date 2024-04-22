/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:51)

#include "CoreTools/CoreToolsExport.h"

#include "GenerateRandomNameDetail.h"

using namespace std::literals;

std::string CoreTools::GenerateRandomName::GetName(int length, const std::string& extensionName)
{
    const auto letters = "abcdefghijklmnopqrstuvwxyz0123456789"s;

    return GetName(length, letters, "." + extensionName);
}

std::wstring CoreTools::GenerateRandomName::GetName(int length, const std::wstring& extensionName)
{
    const auto letters = L"abcdefghijklmnopqrstuvwxyz0123456789"s;

    return GetName(length, letters, L"." + extensionName);
}

System::String CoreTools::GenerateRandomName::GetStandardName(int length, const String& extensionName)
{
    const auto letters = SYSTEM_TEXT("abcdefghijklmnopqrstuvwxyz0123456789"s);

    return GetName(length, letters, SYSTEM_TEXT(".") + extensionName);
}
