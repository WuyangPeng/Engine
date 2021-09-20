///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/27 22:16)

#ifndef BOOK_STANDARD_LIBRARY_STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_TESTING_H
#define BOOK_STANDARD_LIBRARY_STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookStandardLibrary
{
    namespace STLTutorialAndReferenceGuide
    {
        class STLTutorialAndReferenceGuidePrefaceTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = STLTutorialAndReferenceGuidePrefaceTesting;
            using ParentType = UnitTest;

        public:
            explicit STLTutorialAndReferenceGuidePrefaceTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();
        };
    }
}

#endif  // BOOK_STANDARD_LIBRARY_STL_TUTORIAL_AND_REFERENCE_GUIDE_PREFACE_TESTING_H