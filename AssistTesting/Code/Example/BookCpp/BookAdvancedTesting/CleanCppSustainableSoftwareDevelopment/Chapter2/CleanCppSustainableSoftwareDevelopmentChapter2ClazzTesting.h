///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/04/11 13:40)

#ifndef BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CLAZZ_TESTING_H
#define BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CLAZZ_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting;
            using ParentType = UnitTest;

        public:
            explicit CleanCppSustainableSoftwareDevelopmentChapter2ClazzTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CLAZZ_TESTING_H