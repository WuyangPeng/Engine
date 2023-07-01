///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/20 16:47)

#ifndef RENDERING_TESTING_TESTING_HELPER_H
#define RENDERING_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Rendering
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
        void AddRendererEngineSuite();
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