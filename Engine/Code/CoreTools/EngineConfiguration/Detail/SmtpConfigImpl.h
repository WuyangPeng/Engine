/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 14:57)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_IMPL_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SmtpConfigImpl
    {
    public:
        using ClassType = SmtpConfigImpl;

        using String = System::String;
        using ReceiveUserType = std::vector<String>;

    public:
        SmtpConfigImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetSmtpHost() const;
        NODISCARD int GetSmtpPort() const;
        NODISCARD String GetEhlo() const;
        NODISCARD bool GetSmtpSslEnable() const noexcept;
        NODISCARD bool GetSmtpAuth() const noexcept;
        NODISCARD String GetSendUser() const;
        NODISCARD String GetPassword() const;
        NODISCARD ReceiveUserType GetReceiveUser() const;

        void SetSmtpHost(const String& aSmtpHost);
        void SetSmtpPort(int aSmtpPort) noexcept;
        void SetEhlo(const String& aEhlo);
        void SetSmtpSslEnable(bool aSmtpSslEnable) noexcept;
        void SetSmtpAuth(bool aSmtpAuth) noexcept;
        void SetSendUser(const String& aSendUser);
        void SetPassword(const String& aPassword);
        void SetReceiveUser(const ReceiveUserType& aReceiveUser);
        void AddReceiveUser(const String& aReceiveUser);

    private:
        String smtpHost;
        int smtpPort;
        String ehlo;
        bool smtpSslEnable;
        bool smtpAuth;
        String sendUser;
        String password;
        ReceiveUserType receiveUser;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_IMPL_H