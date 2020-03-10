// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:14)

#include "CoreTools/CoreToolsExport.h"

#include "Version.h"
#include "System/Helper/PragmaWarning/Format.h" 
#include "System/CharacterString/FormatStringDetail.h"

using boost::format;
using std::string;

string CoreTools::Version
	::GetVersion()
{
	return GetVersion(GetTCREFullVersion());
}

std::string CoreTools::Version
	::GetVersion(int version)
{
	format versionFormat{ "%d.%d.%d.%d" };
	versionFormat % GetMajor(version) % GetMinor(version) % GetBuild(version) % GetRevision(version);

	return versionFormat.str();
}

bool CoreTools::Version
	::IsAtLeast(int major, int minor, int build, int revision) noexcept
{
	return IsAtLeast(GetTCREFullVersion(), major, minor, build, revision);
}

bool CoreTools::Version
	::IsAtLeast(int version, int major, int minor, int build, int revision) noexcept
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

