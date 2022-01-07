///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.6 (2021/11/24 21:04)

#ifndef BOOK_LINUX_TESTING_HELPER_H
#define BOOK_LINUX_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookLinux
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

        void AddBeginningLinuxProgrammingSuite();

        void AddLinuxCommandLineAndShellScriptingBibleSuite();

        void AddProfessionalLinuxKernelArchitectureSuite();
    };
}

#endif  // BOOK_LINUX_TESTING_HELPER_H