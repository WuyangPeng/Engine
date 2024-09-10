/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:52)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_TEST_CONFIG_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_TEST_CONFIG_H

#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/TextParsing/Json/JsonBase.h"

namespace CoreTools
{
    class TestConfig final : public JsonBase
    {
    public:
        using ClassType = TestConfig;
        using ParentType = JsonBase;

    public:
        explicit TestConfig(int portShifting) noexcept;

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

        CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(false);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        String describe;
        String suffix;
        String publicSuffix;
        String domainName;
        String gameSuffix;
        int portShifting;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TestConfig);

#include SYSTEM_WARNING_POP
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_TEST_CONFIG_H