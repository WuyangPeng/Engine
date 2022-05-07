///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/03/30 18:40)

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
        using EnumResourceDataGroup = std::vector<EnumResourceData>;
        using ResourceEnumContainer = std::vector<ResourceEnum>;

    private:
        NODISCARD ResourceEnum GetCurrentResourceEnum() const;

    private:
        EnumResourceDataGroup enumResourceDataGroup;
        ResourceEnumContainer resourceEnum;
        size_t index;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_RESOURCE_ENUM_TESTING_H