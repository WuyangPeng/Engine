///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/27 0:10)

#ifndef BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H
#define BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        class AppliedCppChapter2MainTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = AppliedCppChapter2MainTesting;
            using ParentType = UnitTest;

        public:
            explicit AppliedCppChapter2MainTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H