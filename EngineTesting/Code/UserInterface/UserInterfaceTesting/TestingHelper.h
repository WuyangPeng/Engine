///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/21 18:03)

#ifndef USER_INTERFACE_TESTING_TESTING_HELPER_H
#define USER_INTERFACE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace UserInterface
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddMacroSuite();
        void AddConfigurationSuite();
        void AddInterfaceSuite();
        void AddWxWidgetsSuite();
        void AddFLTKSuite();
        void AddTrixulSuite();
        void AddXFree86Suite();
    };
}

#endif  // USER_INTERFACE_TESTING_TESTING_HELPER_H