// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:35)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLogJsonImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateLogJsonImpl
	::sm_Extension(SYSTEM_TEXT(".json"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateLogJsonImpl
	::GenerateTemplateLogJsonImpl(const System::String& templateFileName, const System::String& projectName)
	:ParentType(templateFileName, sm_Extension), m_ProjectName(projectName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateLogJsonImpl)

void AssistTools::GenerateTemplateLogJsonImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable;
	newVariable.insert(make_pair(m_ProjectName, solutionName));

	return ParentType::Generate (resourceDirectory, newFileName, newVariable);
}
 

/*
 æ¿˝ƒ£∞Â£∫ 
{
   "Logger":
   {
      "System": 1,
      "CoreTools": 1,
      "Network": 1,
      "Database": 1,
      "Script": 1,
	  "Mathematics": 1,	  
	  "SoundEffect": 1,
	  "InputOutput": 1,
	  "ResourceManager": 1,
	  "Rendering": 1,
	  "Physics": 1,
      "Imagics": 1,
      "Animation": 1,
	  "ArtificialIntellegence": 1,
	  "UserInterface": 1,
	  "AssistTools": 1,
      "Framework": 1
   },

   "Appender":
   {
      "Console": 	      
      {
	    "Flags": 15,
		"Level": 1
	  },       
      
	  "File":
	  {
		  "Directory": "Log", 
		  "FileName": "%ProjectName%",
		  "Flags": 15, 
		  "Level": 1,
		  "MaxFileSize":1000000,
		  "Backup": true,
		  "Extension":"log"
	  },
	  
      "Default":
	  {
          "Directory": "Log",  
		  "Flags": 15, 
		  "Level": 1,
		  "MaxFileSize":1000000,
		  "Backup": true,
		  "Extension":"log"
	  }
   }
}
*/