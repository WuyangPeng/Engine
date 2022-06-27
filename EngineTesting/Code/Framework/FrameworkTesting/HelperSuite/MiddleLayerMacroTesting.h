///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:05)

#ifndef FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class MiddleLayerMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MiddleLayerMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MiddleLayerMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void HelperManagerSuccessTest();
        void ChildHelperManagerSuccessTest();

        void HelperManagerNetworkExceptionTest();
        void HelperManagerPhysicalModellingExceptionTest();
        void HelperManagerSystemExceptionTest();
        void HelperManagerGUIExceptionTest();

        void ChildHelperManagerNetworkExceptionTest();
        void ChildHelperManagerPhysicalModellingExceptionTest();
        void ChildHelperManagerSystemExceptionTest();
        void ChildHelperManagerGUIExceptionTest();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MIDDLE_LAYER_MACRO_TESTING_H