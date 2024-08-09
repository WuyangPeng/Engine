/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:41)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_IMPL_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE GlobalConfigImpl
    {
    public:
        using ClassType = GlobalConfigImpl;

        using String = System::String;

    public:
        GlobalConfigImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

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

    private:
        String describe;
        String suffix;
        String publicSuffix;
        String domainName;
        String gameSuffix;
        int portShifting;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_GLOBAL_CONFIG_IMPL_H