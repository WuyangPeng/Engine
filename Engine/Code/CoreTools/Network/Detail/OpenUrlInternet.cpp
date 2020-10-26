//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 15:01)

#include "CoreTools/CoreToolsExport.h"

#include "OpenUrlInternet.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Network/Flags/WindowsInternetFlags.h"
#include "System/Network/WindowsInternet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/gsl_util>
#include <array>
#include <vector>

using std::array;
using std::vector;
using namespace std::literals;

CoreTools::OpenUrlInternet ::OpenUrlInternet(InternetHandle internet, const String& url, const String& header)
    : m_UrlInternet{ System::GetInternetOpenUrl(internet, url.c_str(), (header.empty() ? nullptr : header.c_str()), gsl::narrow_cast<System::WindowDWord>(-1), System::InternetType::NoCacheWrite, 0) }
{
    if (m_UrlInternet == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�޷���url��"s));
    }

    CheckHttpVersionsOK();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::OpenUrlInternet::~OpenUrlInternet() noexcept
{
    [[maybe_unused]] const auto result = System::InternetCloseHandle(m_UrlInternet);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OpenUrlInternet::IsValid() const noexcept
{
    if (m_UrlInternet != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::OpenUrlInternet::InternetHandle CoreTools::OpenUrlInternet::GetInternet() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_UrlInternet;
}

// private
void CoreTools::OpenUrlInternet::CheckHttpVersionsOK()
{
    constexpr auto bufferSize = 80;
    array<System::TChar, bufferSize> buffer{};
    System::WindowDWord bufferLength{ 79 };

    if (!System::GetHttpQueryInfo(m_UrlInternet, System::QueryInfo::Version, buffer.data(), &bufferLength, nullptr))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡurl�汾ʧ�ܡ�"s));
    }

    String queryInfo{ buffer.data() };
    vector<String> majorVersion;

    split(majorVersion, queryInfo, boost::is_any_of(SYSTEM_TEXT("/"s)), boost::token_compress_on);

    if (majorVersion.size() <= 1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡurl���汾��ʧ�ܡ�"s));
    }

    vector<String> minorVersion;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    split(minorVersion, majorVersion[1], boost::is_any_of(SYSTEM_TEXT("."s)), boost::token_compress_on);
#include STSTEM_WARNING_POP

    if (minorVersion.size() <= 1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡurl�ΰ汾��ʧ�ܡ�"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    const auto minorVersionNum = std::stoi(minorVersion[1]);
#include STSTEM_WARNING_POP

    if (minorVersionNum <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("url�ΰ汾����Ч��"s));
    }
}
