//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:00)

#include "CoreTools/CoreToolsExport.h"

#include "InternetConnection.h"
#include "System/Network/Flags/WindowsInternetFlags.h"
#include "System/Network/WindowsInternet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::InternetConnection::InternetConnection(const String& agent)
    : m_Internet{ System::GetInternetOpenHandle(agent.c_str(), System::InternetOpenType::Direct, nullptr, nullptr, System::InternetType::Zero) }
{
    if (m_Internet == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法打开连接。"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::InternetConnection::~InternetConnection() noexcept
{
    [[maybe_unused]] const auto result = System::InternetCloseHandle(m_Internet);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::InternetConnection::IsValid() const noexcept
{
    if (m_Internet != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::InternetConnection::InternetHandle CoreTools::InternetConnection::GetInternet() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Internet;
}
