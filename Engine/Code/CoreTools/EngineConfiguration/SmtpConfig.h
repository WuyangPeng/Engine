/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 15:31)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_H

#include "GlobalConfig.h"
#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/TextParsing/Json/JsonBase.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(SmtpConfig, SmtpConfigImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SmtpConfig final : public JsonBase
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SmtpConfig);
        using ParentType = JsonBase;

        using ReceiveUserType = std::vector<std::string>;

    public:
        explicit SmtpConfig(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::string GetSmtpHost() const;
        NODISCARD int GetSmtpPort() const noexcept;
        NODISCARD std::string GetEhlo() const;
        NODISCARD bool GetSmtpSslEnable() const noexcept;
        NODISCARD bool GetSmtpAuth() const noexcept;
        NODISCARD std::string GetSendUser() const;
        NODISCARD std::string GetPassword() const;
        NODISCARD ReceiveUserType GetReceiveUser() const;
        NODISCARD int GetTimeout() const noexcept;

        void SetSmtpHost(const String& smtpHost);
        void SetSmtpPort(int smtpPort) noexcept;
        void SetEhlo(const String& ehlo);
        void SetSmtpSslEnable(bool smtpSslEnable) noexcept;
        void SetSmtpAuth(bool smtpAuth) noexcept;
        void SetSendUser(const String& sendUser);
        void SetPassword(const String& password);
        void SetReceiveUser(const ReceiveUserType& receiveUser);
        void SetTimeout(int timeout) noexcept;

        void Load(BasicTree& mainTree) override;

        NODISCARD static JsonBaseSharedPtr Factory(BasicTree& mainTree);

        CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(false);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SmtpConfig);

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_SMTP_CONFIG_H