///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:41)

#include "CoreTools/CoreToolsExport.h"

#include "GenerateRandomName.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <random>

using namespace std::literals;

template <typename T>
T CoreTools::GenerateRandomName::GetName(int length, const T& letters, const T& extensionName)
{
    static_assert(std::is_same_v<T, std::string> || std::is_same_v<T, std::wstring>);

    std::random_device randomDevice{};
    std::default_random_engine generator{ randomDevice() };
    const std::uniform_int_distribution<int> distribution{ 0, boost::numeric_cast<int>(letters.size() - 1) };

    T result{};
    for (auto i = 0; i < length; ++i)
    {
        result += letters.at(distribution(generator));
    }

    return result + extensionName;
}

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
