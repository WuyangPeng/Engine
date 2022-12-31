///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 11:21)

/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。
#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_H

#include "EnumResourceToolsTestingBase.h"

namespace System
{
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