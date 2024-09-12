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
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SmtpConfigImpl::SmtpConfigImpl() noexcept
    : smtpHost{ "smtp.qq.com" },
      smtpPort{ 25 },
      ehlo{},
      smtpSslEnable{ false },
      smtpAuth{ true },
      sendUser{},
      password{},
      receiveUser{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SmtpConfigImpl)

std::string CoreTools::SmtpConfigImpl::GetSmtpHost() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return smtpHost;
}

int CoreTools::SmtpConfigImpl::GetSmtpPort() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return smtpPort;
}

std::string CoreTools::SmtpConfigImpl::GetEhlo() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ehlo;
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

std::string CoreTools::SmtpConfigImpl::GetSendUser() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sendUser;
}

std::string CoreTools::SmtpConfigImpl::GetPassword() const
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

    smtpHost = StringConversion::StandardConversionMultiByte(aSmtpHost);
}

void CoreTools::SmtpConfigImpl::SetSmtpPort(int aSmtpPort) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    smtpPort = aSmtpPort;
}

void CoreTools::SmtpConfigImpl::SetEhlo(const String& aEhlo)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ehlo = StringConversion::StandardConversionMultiByte(aEhlo);
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

    sendUser = StringConversion::StandardConversionMultiByte(aSendUser);
}

void CoreTools::SmtpConfigImpl::SetPassword(const String& aPassword)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    password = StringConversion::StandardConversionMultiByte(aPassword);
}

void CoreTools::SmtpConfigImpl::SetReceiveUser(const ReceiveUserType& aReceiveUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    receiveUser = aReceiveUser;
}

void CoreTools::SmtpConfigImpl::AddReceiveUser(const String& aReceiveUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    receiveUser.emplace_back(StringConversion::StandardConversionMultiByte(aReceiveUser));
}