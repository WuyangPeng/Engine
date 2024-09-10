/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 14:57)

#include "CoreTools/CoreToolsExport.h"

#include "SmtpConfigImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SmtpConfigImpl::SmtpConfigImpl() noexcept
    : smtpHost{ SYSTEM_TEXT("smtp.qq.com") },
      smtpSslEnable{ false },
      smtpAuth{ true },
      sendUser{},
      password{},
      receiveUser{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SmtpConfigImpl)

System::String CoreTools::SmtpConfigImpl::GetSmtpHost() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return smtpHost;
}

bool CoreTools::SmtpConfigImpl::GetSmtpSslEnable() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return smtpSslEnable;
}

bool CoreTools::SmtpConfigImpl::GetSmtpAuth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return smtpAuth;
}

System::String CoreTools::SmtpConfigImpl::GetSendUser() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sendUser;
}

System::String CoreTools::SmtpConfigImpl::GetPassword() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return password;
}

CoreTools::SmtpConfigImpl::ReceiveUserType CoreTools::SmtpConfigImpl::GetReceiveUser() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return receiveUser;
}

void CoreTools::SmtpConfigImpl::SetSmtpHost(const String& aSmtpHost)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    smtpHost = aSmtpHost;
}

void CoreTools::SmtpConfigImpl::SetSmtpSslEnable(bool aSmtpSslEnable) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    smtpSslEnable = aSmtpSslEnable;
}

void CoreTools::SmtpConfigImpl::SetSmtpAuth(bool aSmtpAuth) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    smtpAuth = aSmtpAuth;
}

void CoreTools::SmtpConfigImpl::SetSendUser(const String& aSendUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    sendUser = aSendUser;
}

void CoreTools::SmtpConfigImpl::SetPassword(const String& aPassword)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    password = aPassword;
}

void CoreTools::SmtpConfigImpl::SetReceiveUser(const ReceiveUserType& aReceiveUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    receiveUser = aReceiveUser;
}

void CoreTools::SmtpConfigImpl::AddReceiveUser(const String& aReceiveUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    receiveUser.emplace_back(aReceiveUser);
}