// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_EXPORT_SHARED_PTR(CopyrightDataImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE CopyrightData
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(CopyrightData);

	public:
		CopyrightData(int endYear, const System::String& versions, const System::String& projectChineseName);

		CLASS_INVARIANT_DECLARE;

		int GetEndYear() const;
		const System::String GetVersions() const;
		const System::String GetProjectChineseName() const;

	private:
		IMPL_TYPE_DECLARE(CopyrightData);
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
