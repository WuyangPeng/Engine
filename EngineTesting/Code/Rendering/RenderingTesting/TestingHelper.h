///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 17:48)

#ifndef RENDERING_TESTING_TESTING_HELPER_H
#define RENDERING_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
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
        void AddMacroSuite();
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
        void AddLib3dsSuite();
        void AddAbuseSuite();
        void AddDemoglSuite();
        void AddDevILSuite();
        void AddFBXSuite();
        void AddJPEGSuite();
        void AddTIFFSuite();
        void AddOpenvidiaSuite();
        void AddNethackSuite();
        void AddWingSuite();
        void AddWargamerSuite();
        void AddNvtoolkitSuite();
    };
}

#endif  // RENDERING_TESTING_TESTING_HELPER_H