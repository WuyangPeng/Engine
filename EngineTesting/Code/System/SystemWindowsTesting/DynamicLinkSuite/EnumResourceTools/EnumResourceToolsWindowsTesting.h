///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 22:23)
#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H

#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class EnumResourceToolsWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumResourceToolsWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

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
                                                                  WindowsPtrLong lParam) noexcept;
        NODISCARD static WindowsBool SYSTEM_CALL_BACK NameProcess(DynamicLinkModule module,
                                                                  const DynamicLinkCharType* type,
                                                                  DynamicLinkCharType* name,
                                                                  WindowsPtrLong lParam) noexcept;
        NODISCARD static WindowsBool SYSTEM_CALL_BACK LanguageProcess(DynamicLinkModule module,
                                                                      const DynamicLinkCharType* type,
                                                                      const DynamicLinkCharType* name,
                                                                      WindowsWord language,
                                                                      WindowsPtrLong lParam);

    private:
        using EnumResourceDataContainer = std::vector<EnumResourceData>;

    private:
        EnumResourceDataContainer enumResourceDataContainer;
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H