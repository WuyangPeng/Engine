///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:44)

#ifndef BOOK_TEMPLATE_CPP_TEMPLATES_PLACEHOLDER_TESTING_H
#define BOOK_TEMPLATE_CPP_TEMPLATES_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookTemplate
{
    namespace CppTemplates
    {
        class CppTemplatesPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppTemplatesPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit CppTemplatesPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_TEMPLATE_CPP_TEMPLATES_PLACEHOLDER_TESTING_H