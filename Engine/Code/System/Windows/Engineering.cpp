///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:15)

#include "System/SystemExport.h"

#include "Engineering.h"
#include "System/DynamicLink/LibraryTools.h"

#include <array>

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
    const auto name = GetDynamicLinkFileName(nullptr);

    const auto pos = GetLastSlashPosition(name);

    if (pos == String::npos)
    {
        return String{};
    }

    return name.substr(0, pos + 1);
}

size_t System::GetLastSlashPosition(const String& path)
{
    const auto backSlashPos = path.find_last_of(SYSTEM_TEXT("\\"s));
    const auto forwardSlashPos = path.find_last_of(SYSTEM_TEXT("/"s));

    if (backSlashPos == String::npos)
    {
        return forwardSlashPos;
    }
    else if (forwardSlashPos == String::npos)
    {
        return backSlashPos;
    }
    else
    {
        return std::max(backSlashPos, backSlashPos);
    }
}
