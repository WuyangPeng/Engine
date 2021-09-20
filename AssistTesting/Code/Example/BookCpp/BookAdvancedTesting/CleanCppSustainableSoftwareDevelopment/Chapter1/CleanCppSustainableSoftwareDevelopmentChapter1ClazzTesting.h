///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/29 20:20)

#ifndef BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_TESTING_H
#define BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CleanCppSustainableSoftwareDevelopmentChapter1ClazzTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CleanCppSustainableSoftwareDevelopmentChapter1ClazzTesting;
            using ParentType = UnitTest;

        public:
            explicit CleanCppSustainableSoftwareDevelopmentChapter1ClazzTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER1_CLAZZ_TESTING_H