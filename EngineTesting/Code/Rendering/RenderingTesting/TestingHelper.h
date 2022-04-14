// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/02 19:10)

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