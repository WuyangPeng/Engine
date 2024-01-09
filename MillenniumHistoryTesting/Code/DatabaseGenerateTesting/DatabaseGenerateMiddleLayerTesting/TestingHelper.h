/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:59)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
#define DATABASE_GENERATE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace DatabaseGenerateMiddleLayerTesting
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

        void AddArtificialIntelligenceSuite();
        void AddAudioSuite();
        void AddCameraSystemsSuite();
        void AddEventSuite();
        void AddGUISuite();
        void AddHelperSuite();
        void AddInputSuite();
        void AddMessageSuite();
        void AddNetworkSuite();
        void AddObjectLogicSuite();
        void AddPhysicalModellingSuite();
        void AddRenderingSuite();
        void AddResourceSuite();
        void AddSystemSuite();
    };
}

#endif  //  DATABASE_GENERATE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H