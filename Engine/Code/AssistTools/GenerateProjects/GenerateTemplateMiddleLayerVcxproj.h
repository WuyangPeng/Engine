// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:30)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_EXPORT_SHARED_PTR(GenerateTemplateMiddleLayerVcxprojImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateMiddleLayerVcxproj
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GenerateTemplateMiddleLayerVcxproj);

	public:
		GenerateTemplateMiddleLayerVcxproj(const System::String& templateFileName, const System::String& projectName, const System::String& managerName, const System::String& includeName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName, const System::String& newIncludeName) const;

	private:
		IMPL_TYPE_DECLARE(GenerateTemplateVcxproj);
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_H
