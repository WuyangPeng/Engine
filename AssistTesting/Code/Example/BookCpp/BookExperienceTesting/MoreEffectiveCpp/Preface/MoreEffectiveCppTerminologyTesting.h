///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/16 21:01)

#ifndef BOOK_EXPERIENCE_MORE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H
#define BOOK_EXPERIENCE_MORE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookExperience
{
    namespace MoreEffectiveCpp
    {
        class MoreEffectiveCppTerminologyTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = MoreEffectiveCppTerminologyTesting;
            using ParentType = UnitTest;

        public:
            explicit MoreEffectiveCppTerminologyTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_EXPERIENCE_MORE_EFFECTIVE_CPP_TERMINOLOGY_TESTING_H