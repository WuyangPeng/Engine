///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/10 19:56)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_TESTING_H

#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

#include <vector>

namespace System
{
    class ResourceEnumTesting final : public LoadResourceToolsTesting
    {
    public:
        using ClassType = ResourceEnumTesting;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit ResourceEnumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();
        void AddEnumResourceData(const EnumResourceData& data);

    private:
        void EnumResourceTest();

    private:
        NODISCARD static WindowsBool SYSTEM_CALL_BACK TypeProcess(DynamicLinkModule module,
                                                                  DynamicLinkCharType* type,
                                                                  WindowsPtrLong lParam);
        NODISCARD static WindowsBool SYSTEM_CALL_BACK NameProcess(DynamicLinkModule module,
                                                                  const DynamicLinkCharType* type,
                                                                  DynamicLinkCharType* name,
                                                                  WindowsPtrLong lParam);
        NODISCARD static WindowsBool SYSTEM_CALL_BACK LanguageProcess(DynamicLinkModule module,
                                                                      const DynamicLinkCharType* type,
                                                                      const DynamicLinkCharType* name,
                                                                      WindowsWord language,
                                                                      WindowsPtrLong lParam);

    private:
        using EnumResourceDataContainer = std::vector<EnumResourceData>;
        using ResourceEnumContainer = std::vector<ResourceEnum>;

    private:
        NODISCARD ResourceEnum GetCurrentResourceEnum() const;

    private:
        EnumResourceDataContainer enumResourceDataContainer;
        ResourceEnumContainer resourceEnum;
        size_t index;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_TESTING_H