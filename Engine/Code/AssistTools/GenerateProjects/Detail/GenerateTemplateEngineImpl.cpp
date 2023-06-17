///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê∞Ê±æ£∫0.9.0.12 (2022/04/29 11:04)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateEngineImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AssistTools::GenerateTemplateEngineImpl::GenerateTemplateEngineImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateEngineImpl)

void AssistTools::GenerateTemplateEngineImpl::GenerateTo(const System::String& resourceDirectory,
                                                         const System::String& newProjectName,
                                                         const CopyrightData& copyrightData,
                                                         const System::String& solutionName,
                                                         const System::String& managerName,
                                                         const System::String& interfaceName,
                                                         const System::String& projectCapital,
                                                         const System::String& managerCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerName), managerName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::InterfaceName), interfaceName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫ 

EngineFwd.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_FWD_H
#define %ProjectCapital%_%ManagerCapital%_FWD_H


#endif // %ProjectCapital%_%ManagerCapital%_FWD_H

Engine.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_H
#define %ProjectCapital%_%ManagerCapital%_H

#include "%ManagerName%.h"

#endif // %ProjectCapital%_%ManagerCapital%_H

InputManagerEngineFwd.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_ENGINE_FWD_H
#define %ProjectCapital%_%ManagerCapital%_ENGINE_FWD_H

namespace %SolutionName%MiddleLayer
{
	template <typename ApplicationTrait>
	class %ManagerName%;
}

#endif // %ProjectCapital%_%ManagerCapital%_ENGINE_FWD_H

InputManagerEngine.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_ENGINE_H
#define %ProjectCapital%_%ManagerCapital%_ENGINE_H

#include "%ManagerName%Detail.h"

#endif // %ProjectCapital%_%ManagerCapital%_ENGINE_H

Placeholder.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_ENGINE_PLACEHOLDER_H
#define %ProjectCapital%_%ManagerCapital%_ENGINE_PLACEHOLDER_H

#include "%SolutionName%/%SolutionName%%ManagerName%/%SolutionName%%ManagerName%Dll.h"

#include "%SolutionName%/%SolutionName%%ManagerName%/Macro/ExportMacro.h"

namespace %SolutionName%%ManagerName%
{
	class %ProjectCapital%_%ManagerCapital%_DEFAULT_DECLARE Placeholder
	{
	public:
		typedef Placeholder ClassType;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // %ProjectCapital%_%ManagerCapital%_ENGINE_PLACEHOLDER_H

Placeholder.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%/%SolutionName%%ManagerName%/%SolutionName%%ManagerName%Export.h"

#include "%SolutionName%/%SolutionName%%ManagerName%/Macro/%SolutionName%%ManagerName%ClassInvariantMacro.h"
#include "Placeholder.h"

%SolutionName%%ManagerName%::Placeholder
	::Placeholder()
{
	%ProjectCapital%_%ManagerCapital%_CLASS_IS_VALID_CONST_9;
}

OtherManager.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_%ManagerCapital%_H
#define %ProjectCapital%_%ManagerCapital%_%ManagerCapital%_H

#include "%SolutionName%/%SolutionName%MiddleLayer/%SolutionName%MiddleLayerDll.h"

#include "%SolutionName%/%SolutionName%MiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/%InterfaceName%.h" 

namespace %SolutionName%MiddleLayer
{
	class %ProjectCapital%_MIDDLE_LAYER_DEFAULT_DECLARE %ManagerName% : public Framework::%InterfaceName%
	{
	public:
		typedef %ManagerName% ClassType;
		typedef Framework::%InterfaceName% ParentType;
		
	public:
		%ManagerName%();
		virtual ~%ManagerName%();

		CLASS_INVARIANT_VIRTUAL_DECLARE; 
	};
}

#endif // %ProjectCapital%_%ManagerCapital%_%ManagerCapital%_H

OtherManager.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%/%SolutionName%MiddleLayer/%SolutionName%MiddleLayerExport.h"

#include "%ManagerName%.h" 
#include "%SolutionName%/%SolutionName%MiddleLayer/Macro/%SolutionName%MiddleLayerClassInvariantMacro.h"

%SolutionName%MiddleLayer::%ManagerName%
	::%ManagerName%()
	:ParentType{}
{
	%ProjectCapital%_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

%SolutionName%MiddleLayer::%ManagerName%
	::~%ManagerName%()
{
	%ProjectCapital%_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(%SolutionName%MiddleLayer, %ManagerName%)

InputManager.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_H
#define %ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_H

#include "%SolutionName%/%SolutionName%MiddleLayer/%SolutionName%MiddleLayerDll.h"

#include "%SolutionName%/%SolutionName%MiddleLayer/Macro/ExportMacro.h" 
#include "Framework/Application/ApplicationTrait.h"
#include "Framework/MiddleLayer/%ManagerName%.h"

namespace %SolutionName%MiddleLayer
{
	template <typename ApplicationTrait>
	class %ManagerName% : public Framework::%ManagerName%<ApplicationTrait>
	{
	public:
		typedef %ManagerName%<ApplicationTrait> ClassType;
		typedef Framework::%ManagerName%<ApplicationTrait> ParentType;
		
	public:
		%ManagerName%();
		virtual ~%ManagerName%();

		CLASS_INVARIANT_VIRTUAL_DECLARE; 
	};
}

#endif // %ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_H

InputManager.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_DETAIL_H
#define %ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_DETAIL_H

#include "%ManagerName%.h" 
#include "%SolutionName%/%SolutionName%MiddleLayer/Macro/%SolutionName%MiddleLayerClassInvariantMacro.h"
#include "Framework/MiddleLayer/%ManagerName%Detail.h"

template <typename ApplicationTrait>
%SolutionName%MiddleLayer::%ManagerName%<ApplicationTrait>
	::%ManagerName%()
	:ParentType{}
{
	%ProjectCapital%_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

template <typename ApplicationTrait>
%SolutionName%MiddleLayer::%ManagerName%<ApplicationTrait>
	::~%ManagerName%()
{
	%ProjectCapital%_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool %SolutionName%MiddleLayer::%ManagerName%<ApplicationTrait>
	::IsValid() const
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

#endif / /%ProjectCapital%_%ManagerCapital%_ENGINE_%ManagerCapital%_DETAIL_H 
*/