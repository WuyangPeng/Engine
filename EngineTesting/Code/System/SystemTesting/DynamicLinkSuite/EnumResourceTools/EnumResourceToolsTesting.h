/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:22)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H

#include "EnumResourceToolsTestingBase.h"

namespace System
{
    /// @brief 枚举资源工具模块的测试。
    /// 这里只测试dllModule参数不为instance的情况。
    /// SystemWindowsTesting有dllModule为instance时的测试。
    class EnumResourceToolsTesting : public EnumResourceToolsTestingBase
    {
    public:
        using ClassType = EnumResourceToolsTesting;
        using ParentType = EnumResourceToolsTestingBase;

    public:
        explicit EnumResourceToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD static WindowsBool SYSTEM_CALL_BACK TypeProcess(DynamicLinkModule module,
                                                                  DynamicLinkCharType* type,
                                                                  WindowsLongPtrSizeType lParam) noexcept;
        NODISCARD static WindowsBool SYSTEM_CALL_BACK NameProcess(DynamicLinkModule module,
                                                                  const DynamicLinkCharType* type,
                                                                  DynamicLinkCharType* name,
                                                                  WindowsLongPtrSizeType lParam) noexcept;
        NODISCARD static WindowsBool SYSTEM_CALL_BACK LanguageProcess(DynamicLinkModule module,
                                                                      const DynamicLinkCharType* type,
                                                                      const DynamicLinkCharType* name,
                                                                      WindowsWord language,
                                                                      WindowsLongPtrSizeType lParam);

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        virtual void EnumResourceTest();
        virtual void EnumResourceExistTest(const EnumResourceData& data);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H