///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:57)

#ifndef RENDERING_TESTING_TESTING_HELPER_H
#define RENDERING_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Rendering
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
        void AddHelperSuite();
        void AddBaseSuite();
        void AddDataTypesSuite();
        void AddResourcesSuite();
        void AddSceneGraphSuite();
        void AddControllersSuite();
        void AddShaderFloatsSuite();
        void AddDetailSuite();
        void AddShadersSuite();
        void AddGlobalEffectsSuite();
        void AddLocalEffectsSuite();
        void AddCurvesSurfacesSuite();
        void AddIlluminationSuite();
        void AddImageProcessingSuite();
        void AddPictureSuite();
        void AddSortingSuite();
        void AddTerrainSuite();
        void AddVertexSuite();
        void AddTextFontsSuite();
        void AddConsoleGraphSuite();
        void AddOpenGLAPISuite();
        void AddDirectAPISuite();
        void AddRenderersSuite();
        void AddOpenGLRendererSuite();
        void AddDx9RendererSuite();
        void AddAglRendererSuite();
        void AddGlutRendererSuite();
        void AddGlxRendererSuite();
        void AddWglRendererSuite();
        void AddStateSuite();
    };
}

#endif  // RENDERING_TESTING_TESTING_HELPER_H