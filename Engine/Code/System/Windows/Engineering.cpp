///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 13:05)

#include "System/SystemExport.h"

#include "Engineering.h"
#include "System/DynamicLink/LibraryTools.h"

#include <array>

using std::array;
using namespace std::literals;

System::String System::GetEngineeringSuffix()
{
    auto suffix = SYSTEM_TEXT(""s);

#ifdef BUILDING_SYSTEM_STATIC
    suffix += SYSTEM_TEXT("Static"s);
#endif  // BUILDING_SYSTEM_STATIC

#ifdef _DEBUG
    suffix += SYSTEM_TEXT("D"s);
#endif  // _DEBUG

    return suffix;
}

System::String System::GetEngineeringTypesSuffix()
{
    auto suffix = SYSTEM_TEXT(""s);

#ifdef BUILDING_SYSTEM_STATIC
    suffix += SYSTEM_TEXT("Static"s);
#endif  // BUILDING_SYSTEM_STATIC

#ifdef _DEBUG
    suffix += SYSTEM_TEXT("D"s);
#endif  // _DEBUG

#ifdef _WIN64
    suffix += SYSTEM_TEXT("X"s);
#endif  // _WIN64

    return suffix;
}

System::String System::GetEngineeringExeSuffix()
{
#ifdef SYSTEM_PLATFORM_WIN32
    return SYSTEM_TEXT(".exe"s);
#else  // !SYSTEM_PLATFORM_WIN32
    return SYSTEM_TEXT(""s);
#endif  // BUILDING_SYSTEM_STATIC
}

System::String System::GetEngineeringDirectory()
{
    array<DynamicLinkCharType, gMaxPath> moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(nullptr, moduleFileName.data(), gMaxPath);

    if (maxFileNameLength == 0)
    {
        return String{};
    }

    String name{ moduleFileName.data() };

    const auto pos = name.find_last_of(SYSTEM_TEXT("\\"s));
    if (pos == String::npos)
    {
        return String{};
    }

    return name.substr(0, pos + 1);
}
