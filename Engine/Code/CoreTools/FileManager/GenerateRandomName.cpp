///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/12 12:28)

#include "CoreTools/CoreToolsExport.h"

#include "GenerateRandomName.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <random>

using std::string;
using std::wstring;
using namespace std::literals;

template <typename T>
T CoreTools::GenerateRandomName::GetName(int length, const T& letters, const T& extensionName)
{
    static_assert(std::is_same_v<T, string> || std::is_same_v<T, wstring>);

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

string CoreTools::GenerateRandomName::GetName(int length, const string& extensionName)
{
    const auto letters = "abcdefghijklmnopqrstuvwxyz0123456789"s;

    return GetName(length, letters, "." + extensionName);
}

wstring CoreTools::GenerateRandomName::GetName(int length, const wstring& extensionName)
{
    const auto letters = L"abcdefghijklmnopqrstuvwxyz0123456789"s;

    return GetName(length, letters, L"." + extensionName);
}

System::String CoreTools::GenerateRandomName::GetStandardName(int length, const String& extensionName)
{
    const auto letters = SYSTEM_TEXT("abcdefghijklmnopqrstuvwxyz0123456789"s);

    return GetName(length, letters, SYSTEM_TEXT(".") + extensionName);
}
