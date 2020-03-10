// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:48)

#include "CoreTools/CoreToolsExport.h"

#include "OpenUrlInternet.h" 
#include "System/Network/WindowsInternet.h"
#include "System/Network/Flags/WindowsInternetFlags.h" 
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"  

#include <vector>
#include <array>

using std::vector;
using std::array;

CoreTools::OpenUrlInternet
	::OpenUrlInternet(InternetHandle internet, const System::String& url, const System::String& header)
	:m_UrlInternet{ System::GetInternetOpenUrl(internet, url.c_str(),(header.empty() ? nullptr : header.c_str()), static_cast<System::WindowDWord>(-1), System::InternetType::NoCacheWrite, 0) }
{
	if (m_UrlInternet == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无法打开url。"));
	}

	CheckHttpVersionsOK();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::OpenUrlInternet
	::~OpenUrlInternet()
{
	System::InternetCloseHandle(m_UrlInternet);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OpenUrlInternet
	::IsValid() const noexcept
{
	if (m_UrlInternet != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::OpenUrlInternet::InternetHandle CoreTools::OpenUrlInternet
	::GetInternet() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_UrlInternet;
}

// private
void CoreTools::OpenUrlInternet
	::CheckHttpVersionsOK()
{
	constexpr auto bufferSize = 80;
	array<System::TChar, bufferSize> buffer{ };
	System::WindowDWord bufferLength{ 79 };

	if (!System::GetHttpQueryInfo(m_UrlInternet, System::QueryInfo::Version, buffer.data(), &bufferLength, nullptr))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取url版本失败。"));
	}

	System::String queryInfo{ buffer.data() };
	vector<System::String> majorVersion;

	split(majorVersion, queryInfo, boost::is_any_of(SYSTEM_TEXT("/")), boost::token_compress_on);

	if (majorVersion.size() <= 1)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取url主版本号失败。"));
	}

	vector<System::String> minorVersion;

	split(minorVersion, majorVersion[1], boost::is_any_of(SYSTEM_TEXT(".")), boost::token_compress_on);

	if (minorVersion.size() <= 1)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取url次版本号失败。"));
	}

	auto minorVersionNum = std::stoi(minorVersion[1]);

	if (minorVersionNum <= 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("url次版本号无效。"));
	}
}

