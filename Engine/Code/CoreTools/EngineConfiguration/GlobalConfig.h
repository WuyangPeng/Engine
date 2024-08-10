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
#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/TextParsing/Json/JsonBase.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(GlobalConfig, GlobalConfigImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE GlobalConfig final : public JsonBase
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GlobalConfig);
        using ParentType = JsonBase;

    public:
        explicit GlobalConfig(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GetDescribe() const;
        NODISCARD String GetSuffix() const;
        NODISCARD String GetPublicSuffix() const;
        NODISCARD String GetDomainName() const;
        NODISCARD String GetGameSuffix() const;
        NODISCARD int GetPortShifting() const noexcept;

        void SetDescribe(const String& describe);
        void SetSuffix(const String& suffix);
        void SetPublicSuffix(const String& publicSuffix);
        void SetDomainName(const String& domainName);
        void SetGameSuffix(const String& gameSuffix);
        void SetPortShifting(int portShifting) noexcept;

        void Load(BasicTree& mainTree) override;

        NODISCARD static JsonBaseSharedPtr Factory(BasicTree& mainTree);

        CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(false);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(GlobalConfig);

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_H