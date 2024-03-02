/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/26 12:56)

#include "System/SystemExport.h"

#include "Engineering.h"
#include "System/DynamicLink/LibraryTools.h"

using namespace std::literals;

System::String System::GetEngineeringSuffix()
{
    auto suffix = SYSTEM_TEXT(""s);

#ifdef BUILDING_SYSTEM_STATIC

    suffix += SYSTEM_TEXT("Static");

#endif  // BUILDING_SYSTEM_STATIC

#ifdef _DEBUG

    suffix += SYSTEM_TEXT("D");

#endif  // _DEBUG

    return suffix;
}

System::String System::GetEngineeringTypesSuffix()
{
    auto suffix = SYSTEM_TEXT(""s);

#ifdef BUILDING_SYSTEM_STATIC

    suffix += SYSTEM_TEXT("Static");

#endif  // BUILDING_SYSTEM_STATIC

#ifdef _DEBUG

    suffix += SYSTEM_TEXT("D");

#endif  // _DEBUG

#if defined(TCRE_ARCHITECTURE_TYPE_64)

    suffix += SYSTEM_TEXT("X");

#endif  // defined(TCRE_ARCHITECTURE_TYPE_64)

    return suffix;
}

System::String System::GetEngineeringExeSuffix()
{
#ifdef SYSTEM_PLATFORM_WIN32

    return SYSTEM_TEXT(".exe");

#else  // !SYSTEM_PLATFORM_WIN32

    return String{};

#endif  // BUILDING_SYSTEM_STATIC
}

System::String System::GetEngineeringDirectory()
{
    const auto name = GetDynamicLinkFileName(nullptr);

    const auto position = GetLastSlashPosition(name);

    if (position == String::npos)
    {
        return name;
    }

    return name.substr(0, position + 1);
}

size_t System::GetLastSlashPosition(const String& path) noexcept
{
    const auto backSlashPos = path.find_last_of(SYSTEM_TEXT("\\"));
    const auto forwardSlashPos = path.find_last_of(SYSTEM_TEXT("/"));

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
        return std::max(backSlashPos, forwardSlashPos);
    }
}
