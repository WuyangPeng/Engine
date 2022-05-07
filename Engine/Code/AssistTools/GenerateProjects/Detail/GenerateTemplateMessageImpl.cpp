///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê∞Ê±æ£∫0.8.0.7 (2022/04/29 11:13)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMessageImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AssistTools::GenerateTemplateMessageImpl::GenerateTemplateMessageImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMessageImpl)

void AssistTools::GenerateTemplateMessageImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& solutionName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫

.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ProjectCapital%_MESSAGE_H
#define %ProjectCapital%_%ProjectCapital%_MESSAGE_H

#include "%SolutionName%/%SolutionName%MiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/Audio/AudioManager.h"												 
#include "%SolutionName%/%SolutionName%MiddleLayer/CameraSystems/CameraSystemsManager.h"	
#include "%SolutionName%/%SolutionName%MiddleLayer/Event/EventManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/GUI/GUIManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/Input/InputManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/Message/MessageManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/Network/NetworkManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "%SolutionName%/%SolutionName%MiddleLayer/Rendering/RenderingManager.h"												 
#include "%SolutionName%/%SolutionName%MiddleLayer/Resource/ResourceManager.h"	
#include "%SolutionName%/%SolutionName%MiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "Framework/Application/ApplicationTrait.h" 
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace %SolutionName%
{
	typedef Framework::ObjectLogicManager<%SolutionName%MiddleLayer::ObjectLogicManager, %SolutionName%MiddleLayer::ArtificialIntellegenceManager> ObjectLogicManager;
	typedef Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
										          %SolutionName%MiddleLayer::InputManager,
		                                          %SolutionName%MiddleLayer::NetworkManager,
												  ObjectLogicManager,
												  %SolutionName%MiddleLayer::PhysicalModellingManager,
												  %SolutionName%MiddleLayer::MessageManager,		
												  %SolutionName%MiddleLayer::EventManager, 
												  %SolutionName%MiddleLayer::SystemManager,
												  %SolutionName%MiddleLayer::ResourceManager,
												  %SolutionName%MiddleLayer::AudioManager,
												  %SolutionName%MiddleLayer::CameraSystemsManager,
												  %SolutionName%MiddleLayer::RenderingManager,
												  %SolutionName%MiddleLayer::GUIManager>

			MiddleLayerType;
	typedef Framework::WindowMessage<MiddleLayerType> MessageType;

	class %SolutionName%Message : public MessageType
	{
	public:
		typedef %SolutionName%Message ClassType;
		typedef MessageType ParentType;

	public:
		%SolutionName%Message();
		virtual ~%SolutionName%Message();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	private:
		CoreTools::ConsoleAlloc m_Alloc;
	};

	typedef Framework::WindowProcessHandle<%SolutionName%Message> %SolutionName%MessageWindowProcessHandle;
}

#endif // %ProjectCapital%_%ProjectCapital%_MESSAGE_H

.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%/%SolutionName%MiddleLayer/Input/InputManagerDetail.h"
#include "%SolutionName%Message.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/MemoryTools/SubclassSharedPtrDetail.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterfaceDetail.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h" 

%SolutionName%::%SolutionName%Message
	::%SolutionName%Message()
	:ParentType{}, m_Alloc()
{ 
	SELF_CLASS_IS_VALID_1;
}

%SolutionName%::%SolutionName%Message
	::~%SolutionName%Message()
{
	SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(%SolutionName%, %SolutionName%Message) 
*/