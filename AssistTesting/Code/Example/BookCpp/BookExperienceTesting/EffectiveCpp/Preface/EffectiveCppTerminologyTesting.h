///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/16 21:01)

#ifndef BOOK_EXPERIENCE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H
#define BOOK_EXPERIENCE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        class EffectiveCppTerminologyTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = EffectiveCppTerminologyTesting;
            using ParentType = UnitTest;

        public:
            explicit EffectiveCppTerminologyTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_EXPERIENCE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H