// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:29)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Flags/GenerateTemplateReplaceFlags.h"

#include <string>
#include <map>

ASSIST_TOOLS_EXPORT_SHARED_PTR(GenerateTemplateLibImpl);

namespace AssistTools
{ 
	class CopyrightData;

	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateLib
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GenerateTemplateLib);
		typedef std::map<GenerateTemplateReplace, System::String> Replace;

	public:
		GenerateTemplateLib(const System::String& templateFileName,   const Replace& replace);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName) const;

	private:
		IMPL_TYPE_DECLARE(GenerateTemplateLib);
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_H
