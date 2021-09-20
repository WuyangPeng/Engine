// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/02 19:10)

#ifndef RENDERING_TESTING_TESTING_HELPER_H
#define RENDERING_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace CoreTools
{
	class Suite;
}

namespace Rendering
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;			

	private:
                void AddSuites();
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

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // RENDERING_TESTING_TESTING_HELPER_H