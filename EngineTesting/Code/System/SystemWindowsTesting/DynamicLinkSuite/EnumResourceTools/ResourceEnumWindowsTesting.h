///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 22:24)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H

#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ResourceEnumWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ResourceEnumWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit ResourceEnumWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

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
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H