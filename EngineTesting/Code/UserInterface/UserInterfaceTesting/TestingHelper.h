///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 19:19)

#ifndef USER_INTERFACE_TESTING_TESTING_HELPER_H
#define USER_INTERFACE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace UserInterface
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddConfigurationSuite();
        void AddInterfaceSuite();
        void AddWxWidgetsSuite();
        void AddFLTKSuite();
        void AddOpenGLSuite();
        void AddDirectXSuite();
    };
}

#endif  // USER_INTERFACE_TESTING_TESTING_HELPER_H