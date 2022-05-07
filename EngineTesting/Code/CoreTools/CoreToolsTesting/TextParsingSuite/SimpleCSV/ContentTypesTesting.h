///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/13 21:04)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ContentTypesTesting final : public UnitTest
    {
    public:
        using ClassType = ContentTypesTesting;
        using ParentType = UnitTest;

    public:
        explicit ContentTypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ContentTypesTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H