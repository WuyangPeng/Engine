///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:58)

/// ԭʼ�ļ���SystemTesting�£�SystemWindowsTesting�µ�Ϊ�Զ������ļ��������޸ġ�
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