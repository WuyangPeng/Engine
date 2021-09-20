///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:44)

#ifndef BOOK_STANDARD_LIBRARY_CPP_STL_PLACEHOLDER_TESTING_H
#define BOOK_STANDARD_LIBRARY_CPP_STL_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookStandardLibrary
{
    namespace CppSTL
    {
        class CppSTLPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CppSTLPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit CppSTLPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_STANDARD_LIBRARY_CPP_STL_PLACEHOLDER_TESTING_H