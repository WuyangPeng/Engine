// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:38)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateEngineImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTestingTemplateEngineImpl
	::GenerateTestingTemplateEngineImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
	:ParentType(templateFileName, extension, replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateEngineImpl)

void AssistTools::GenerateTestingTemplateEngineImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
	             const System::String& solutionName, const System::String& managerName,
				 const System::String& projectCapital, const System::String& managerCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerName), managerName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital)); 

	return ParentType::Generate (resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫ 

Testing.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%TESTING_H
#define %ProjectCapital%_%ManagerCapital%TESTING_H

#endif // %ProjectCapital%_%ManagerCapital%TESTING_H

TestingHelper.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%TESTING_TESTING_HELPER_H
#define %ProjectCapital%_%ManagerCapital%TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"



namespace CoreTools
{
	class Suite;
}

namespace %SolutionName%Testing
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_DECLARE(TestingHelper);
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;

	private:
        virtual int DoRun();

		void AddSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // %ProjectCapital%_%ManagerCapital%TESTING_TESTING_HELPER_H

TestingHelper.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_DEFINE(%SolutionName%Testing, TestingHelper)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(%SolutionName%Testing, TestingHelper)

UNIT_TEST_DO_RUN_DEFINE(%SolutionName%Testing,TestingHelper, "%ProjectChineseName%")

void %SolutionName%Testing::TestingHelper
	::AddSuite()
{

}

TestingLib.cpp(lib)

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)
 
#include "ThreadingCoreRenderEngine/ThreadingCoreRenderEngineLib.h"
#include "ThreadingCoreRenderEngineGame/ThreadingCoreRenderEngineGameLib.h"

#include "%SolutionName%/%SolutionName%%ManagerName%/%SolutionName%%ManagerName%Lib.h"

TestingLib.cpp(exe)

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)
 
#include "ThreadingCoreRenderEngine/ThreadingCoreRenderEngineLib.h"
#include "ThreadingCoreRenderEngineGame/ThreadingCoreRenderEngineGameLib.h"
 
TestingMain.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "TestingHelper.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <vld.h>

MAIN_FUNCTION(%SolutionName%Testing, TestingHelper)
*/