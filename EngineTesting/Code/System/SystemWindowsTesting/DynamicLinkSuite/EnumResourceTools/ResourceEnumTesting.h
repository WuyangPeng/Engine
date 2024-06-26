/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:22)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_TESTING_H

#include "EnumResourceToolsTestingBase.h"
#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"

namespace System
{
    /// @brief 资源枚举模块的测试。
    /// 这里只测试dllModule参数不为instance的情况。
    /// SystemWindowsTesting有dllModule为instance时的测试。
    class ResourceEnumTesting : public EnumResourceToolsTestingBase
    {
    public:
        using ClassType = ResourceEnumTesting;
        using ParentType = EnumResourceToolsTestingBase;

    public:
        explicit ResourceEnumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD static WindowsBool SYSTEM_CALL_BACK TypeProcess(DynamicLinkModule module,
                                                                  DynamicLinkCharType* type,
                                                                  WindowsLongPtrSizeType lParam);
        NODISCARD static WindowsBool SYSTEM_CALL_BACK NameProcess(DynamicLinkModule module,
                                                                  const DynamicLinkCharType* type,
                                                                  DynamicLinkCharType* name,
                                                                  WindowsLongPtrSizeType lParam);
        NODISCARD static WindowsBool SYSTEM_CALL_BACK LanguageProcess(DynamicLinkModule module,
                                                                      const DynamicLinkCharType* type,
                                                                      const DynamicLinkCharType* name,
                                                                      WindowsWord language,
                                                                      WindowsLongPtrSizeType lParam);

        NODISCARD ResourceEnum GetCurrentResourceEnum() const;

    private:
        using ResourceEnumContainer = std::vector<ResourceEnum>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void EnumResourceTest();
        virtual void DoEnumResourceTest();
        virtual void EnumResourceExistTest(const EnumResourceData& data);

        NODISCARD static ClassType* GetSelf(WindowsLongPtrSizeType lParam) noexcept;

    private:
        ResourceEnumContainer resourceEnum;
        size_t index;
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_TESTING_H