///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:44)

#ifndef BOOK_BOOST_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_PLACEHOLDER_TESTING_H
#define BOOK_BOOST_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_PLACEHOLDER_TESTING_H
 
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookBoost
{
    namespace BoostCppApplicationDevelopmentCookbook 
    {
        class BoostCppApplicationDevelopmentCookbookPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = BoostCppApplicationDevelopmentCookbookPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit BoostCppApplicationDevelopmentCookbookPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_BOOST_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_PLACEHOLDER_TESTING_H