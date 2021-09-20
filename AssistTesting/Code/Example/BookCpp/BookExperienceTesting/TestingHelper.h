///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/16 11:54)

#ifndef BOOK_EXPERIENCE_TESTING_HELPER_H
#define BOOK_EXPERIENCE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookExperience
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddEffectiveCppSuite();

        void AddMoreEffectiveCppSuite();

        void AddEffectiveSTLSuite();

        void AddEffectiveModernCppSuite();

        void AddExceptionalCppSuite();

        void AddMoreExceptionalCppSuite();

        void AddExceptionalCppStyleSuite();

        void AddCppCommonKnowledgeSuite();

        void AddCppCodingStandardsSuite();
    };
}

#endif  // BOOK_EXPERIENCE_TESTING_HELPER_H