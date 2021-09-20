///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/26 18:58)

#include "CoreTools/CoreToolsExport.h"

#include "Version.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning/Format.h"

using boost::format;
using std::string;

string CoreTools::Version::GetVersion()
{
    return GetVersion(GetTCREFullVersion());
}

std::string CoreTools::Version::GetVersion(int version)
{
    format versionFormat{ "%d.%d.%d.%d" };
    versionFormat % GetMajor(version) % GetMinor(version) % GetBuild(version) % GetRevision(version);

    return versionFormat.str();
}

bool CoreTools::Version::IsAtLeast(int major, int minor, int build, int revision) noexcept
{
    return IsAtLeast(GetTCREFullVersion(), major, minor, build, revision);
}

bool CoreTools::Version::IsAtLeast(int version, int major, int minor, int build, int revision) noexcept
{
    if (GetMajor(version) < major)
        return false;
    else if (major < GetMajor(version))
        return true;
    else if (GetMinor(version) < minor)
        return false;
    else if (minor < GetMinor(version))
        return true;
    else if (GetBuild(version) < build)
        return false;
    else if (build < GetBuild(version))
        return true;
    else if (GetRevision(version) < revision)
        return false;
    else
        return true;
}
