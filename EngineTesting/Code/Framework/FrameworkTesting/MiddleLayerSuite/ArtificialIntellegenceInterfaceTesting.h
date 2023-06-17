///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 20:00)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class ArtificialIntellegenceInterfaceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ArtificialIntellegenceInterfaceTesting;
        using ParentType = UnitTest;

    public:
        explicit ArtificialIntellegenceInterfaceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
        void MiddleLayerTest();
        void SetMiddleLayerTest();

        void SetNetworkManagerTest();
        void SetInputManagerTest();
        void SetObjectLogicManagerExceptionTest();
        void SetPhysicalModellingManagerTest();
        void SetMessageManagerTest();
        void SetEventManagerExceptionTest();
        void SetSystemManagerTest();
        void SetResourceManagerExceptionTest();
        void SetAudioManagerExceptionTest();
        void SetCameraSystemsManagerExceptionTest();
        void SetRenderingManagerExceptionTest();
        void SetGUIManagerExceptionTest();
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H