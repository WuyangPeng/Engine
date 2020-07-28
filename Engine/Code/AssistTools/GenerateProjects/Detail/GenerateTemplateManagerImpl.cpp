// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:36)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateManagerImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateManagerImpl
	::sm_Extension(SYSTEM_TEXT(".h"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateManagerImpl
	::GenerateTemplateManagerImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateManagerImpl)

void AssistTools::GenerateTemplateManagerImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital,const System::String& managerCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital));

	return ParentType::Generate (resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫
.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_H
#define %ProjectCapital%_%ManagerCapital%_H
 
#include "Macro/Macro.h" 
#include "Engine/Engine.h"

#endif // %ProjectCapital%_%ManagerCapital%_H 

dll.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_DLL_H
#define %ProjectCapital%_%ManagerCapital%_DLL_H

#include "System/Helper/ExportMacro.h"
#include "Macro/UserMacro.h"

#if defined(BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT) || defined(BUILDING_%ProjectCapital%_%ManagerCapital%_STATIC)

  #define %ProjectCapital%_%ManagerCapital%_DEFAULT_DECLARE
  #define %ProjectCapital%_%ManagerCapital%_HIDDEN_DECLARE 
  #define %ProjectCapital%_%ManagerCapital%_VISIBLE

#else // !defined(BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT) && !defined(BUILDING_%ProjectCapital%_%ManagerCapital%_STATIC)
 
   #if defined(BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT)
 
        #define %ProjectCapital%_%ManagerCapital%_DEFAULT_DECLARE TCRE_SYMBOL_EXPORT
        #define %ProjectCapital%_%ManagerCapital%_HIDDEN_DECLARE TCRE_SYMBOL_NO_EXPORT

   #else // !defined(BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT)

		#define %ProjectCapital%_%ManagerCapital%_DEFAULT_DECLARE TCRE_SYMBOL_IMPORT
        #define %ProjectCapital%_%ManagerCapital%_HIDDEN_DECLARE TCRE_SYMBOL_NO_IMPORT

   #endif // BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT

#define %ProjectCapital%_%ManagerCapital%_VISIBLE TCRE_SYMBOL_VISIBLE

#endif // defined(BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT) || defined(BUILDING_%ProjectCapital%_%ManagerCapital%_STATIC)
 
#endif // %ProjectCapital%_%ManagerCapital%_DLL_H

export.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_EXPORT_H
#define %ProjectCapital%_%ManagerCapital%_EXPORT_H

#include "Macro/UserMacro.h"

#ifndef BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT
  #define BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT
#endif // BUILDING_%ProjectCapital%_%ManagerCapital%_EXPORT

#endif // %ProjectCapital%_%ManagerCapital%_EXPORT_H

fwd.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_FWD_H
#define %ProjectCapital%_%ManagerCapital%_FWD_H

#include "Macro/MacroFwd.h" 
#include "Engine/EngineFwd.h"

#endif // %ProjectCapital%_%ManagerCapital%_FWD_H

import.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_IMPORT_H
#define %ProjectCapital%_%ManagerCapital%_IMPORT_H

#include "Macro/UserMacro.h"

#ifndef BUILDING_%ProjectCapital%_%ManagerCapital%_IMPORT
  #define BUILDING_%ProjectCapital%_%ManagerCapital%_IMPORT
#endif // BUILDING_%ProjectCapital%_%ManagerCapital%_IMPORT

#endif // %ProjectCapital%_%ManagerCapital%_IMPORT_H

no_import.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_NO_IMPORT_H
#define %ProjectCapital%_%ManagerCapital%_NO_IMPORT_H

#include "Macro/UserMacro.h"

#ifndef BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT
  #define BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT
#endif // BUILDING_%ProjectCapital%_%ManagerCapital%_NO_IMPORT

#endif // %ProjectCapital%_%ManagerCapital%_NO_IMPORT_H

MiddleLayer.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_H
#define %ProjectCapital%_%ManagerCapital%_H
 
#include "Macro/Macro.h" 
#include "ArtificialIntellegence/ArtificialIntellegence.h"
#include "Audio/Audio.h"
#include "CameraSystems/CameraSystems.h"
#include "Event/Event.h"
#include "GUI/GUI.h"
#include "Input/Input.h"
#include "Message/Message.h"
#include "Network/Network.h"
#include "ObjectLogic/ObjectLogic.h"
#include "PhysicalModelling/PhysicalModelling.h"
#include "Rendering/Rendering.h"
#include "Resource/Resource.h"
#include "System/System.h"

#endif // %ProjectCapital%_%ManagerCapital%_H 

MiddleLayerFwd.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_FWD_H
#define %ProjectCapital%_%ManagerCapital%_FWD_H

#include "Macro/MacroFwd.h" 
#include "ArtificialIntellegence/ArtificialIntellegenceFwd.h"
#include "Audio/AudioFwd.h"
#include "CameraSystems/CameraSystemsFwd.h"
#include "Event/EventFwd.h"
#include "GUI/GUIFwd.h"
#include "Input/InputFwd.h"
#include "Message/MessageFwd.h"
#include "Network/NetworkFwd.h"
#include "ObjectLogic/ObjectLogicFwd.h"
#include "PhysicalModelling/PhysicalModellingFwd.h"
#include "Rendering/RenderingFwd.h"
#include "Resource/ResourceFwd.h"
#include "System/SystemFwd.h"

#endif // %ProjectCapital%_%ManagerCapital%_FWD_H

*/