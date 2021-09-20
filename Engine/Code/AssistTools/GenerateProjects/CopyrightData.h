// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CopyrightDataImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE CopyrightData
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(CopyrightData);

	public:
		CopyrightData(int endYear, const System::String& versions, const System::String& projectChineseName);

		CLASS_INVARIANT_DECLARE;

		int GetEndYear() const noexcept;
		const System::String GetVersions() const;
		const System::String GetProjectChineseName() const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_H
