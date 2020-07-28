// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:20)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE CopyrightDataImpl  
	{
	public:
		using ClassType = CopyrightDataImpl ;

	public:
		CopyrightDataImpl(int endYear,const System::String& versions, const System::String& projectChineseName);

		CLASS_INVARIANT_DECLARE;

		int GetEndYear() const noexcept;
		const System::String GetVersions() const;
		const System::String GetProjectChineseName() const;

	private:
		int m_EndYear;
		System::String m_Versions;
		System::String m_ProjectChineseName;		
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_COPYRIGHT_DATA_IMPL_H
