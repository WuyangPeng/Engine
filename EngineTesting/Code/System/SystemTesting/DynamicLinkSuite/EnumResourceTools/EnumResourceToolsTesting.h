///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 12:45)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H

#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

#include <vector>

namespace System
{
    class EnumResourceToolsTesting final : public LoadResourceToolsTesting
    {
    public:
        using ClassType = EnumResourceToolsTesting;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit EnumResourceToolsTesting(const OStreamShared& stream);

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
        using EnumResourceDataGroup = std::vector<EnumResourceData>;

    private:
        EnumResourceDataGroup enumResourceDataGroup;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H