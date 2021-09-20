///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/11 13:40)

#ifndef BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_TESTING_H
#define BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CleanCppSustainableSoftwareDevelopmentChapter2ServiceTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CleanCppSustainableSoftwareDevelopmentChapter2ServiceTesting;
            using ParentType = UnitTest;

        public:
            explicit CleanCppSustainableSoftwareDevelopmentChapter2ServiceTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void ServiceTest(); 
        };
    }
}

#endif  // BOOK_ADVANCED_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_TESTING_H