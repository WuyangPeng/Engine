///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:55)

#ifndef BOOK_WINDOWS_API_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_PLACEHOLDER_TESTING_H
#define BOOK_WINDOWS_API_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookWindowsAPI
{
    namespace IvorHortonsBeginningVisualCpp
    {
        class IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_WINDOWS_API_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_PLACEHOLDER_TESTING_H