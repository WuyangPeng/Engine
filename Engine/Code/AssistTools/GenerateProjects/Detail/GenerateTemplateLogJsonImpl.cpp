///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/29 11:09)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLogJsonImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateLogJsonImpl::extension{ SYSTEM_TEXT(".json"s) };

AssistTools::GenerateTemplateLogJsonImpl::GenerateTemplateLogJsonImpl(const System::String& templateFileName, const System::String& projectName)
    : ParentType{ templateFileName, extension }, projectName{ projectName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateLogJsonImpl)

void AssistTools::GenerateTemplateLogJsonImpl::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { projectName, solutionName } };

    return ParentType::Generate(resourceDirectory, newFileName, newVariable);
}

/*
ʾ��ģ�壺 
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