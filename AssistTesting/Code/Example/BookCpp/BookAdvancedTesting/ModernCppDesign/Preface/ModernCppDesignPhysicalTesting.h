///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 12:22)

#ifndef BOOK_ADVANCED_MODERN_CPP_DESIGN_PHYSICAL_TESTING_H
#define BOOK_ADVANCED_MODERN_CPP_DESIGN_PHYSICAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace ModernCppDesign
    {
        class ModernCppDesignPhysicalTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ModernCppDesignPhysicalTesting;
            using ParentType = UnitTest;

        public:
            explicit ModernCppDesignPhysicalTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();           
        };
    }
}

#endif  // BOOK_ADVANCED_MODERN_CPP_DESIGN_PHYSICAL_TESTING_H