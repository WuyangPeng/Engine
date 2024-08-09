/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:52)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/Json/JsonBase.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(GlobalConfig, GlobalConfigImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE GlobalConfig : public JsonBase
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GlobalConfig);

    public:
        explicit GlobalConfig(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GetDescribe() const;
        NODISCARD String GetSuffix() const;
        NODISCARD String GetPublicSuffix() const;
        NODISCARD String GetDomainName() const;
        NODISCARD String GetGameSuffix() const;
        NODISCARD int GetPortShifting() const noexcept;

        void SetDescribe(const String& aDescribe);
        void SetSuffix(const String& aSuffix);
        void SetPublicSuffix(const String& aPublicSuffix);
        void SetDomainName(const String& aDomainName);
        void SetGameSuffix(const String& aGameSuffix);
        void SetPortShifting(int aPortShifting) noexcept;

        void Load(BasicTree& mainTree) override;

        NODISCARD static JsonBaseSharedPtr Factory(BasicTree& mainTree);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_H