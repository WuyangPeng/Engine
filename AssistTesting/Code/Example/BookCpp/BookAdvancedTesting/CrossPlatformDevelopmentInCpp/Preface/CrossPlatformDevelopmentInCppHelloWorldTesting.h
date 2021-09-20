///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:23)

#ifndef BOOK_ADVANCED_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_HELLO_WORLD_TESTING_H
#define BOOK_ADVANCED_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_HELLO_WORLD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace CrossPlatformDevelopmentInCpp
    {
        class CrossPlatformDevelopmentInCppHelloWorldTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = CrossPlatformDevelopmentInCppHelloWorldTesting;
            using ParentType = UnitTest;

        public:
            explicit CrossPlatformDevelopmentInCppHelloWorldTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest(); 
        };
    }
}

#endif  // BOOK_ADVANCED_CROSS_PLATFORM_DEVELOPMENT_IN_CPP_HELLO_WORLD_TESTING_H