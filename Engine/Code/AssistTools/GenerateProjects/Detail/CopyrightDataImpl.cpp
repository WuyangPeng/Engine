// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:32)

#include "AssistTools/AssistToolsExport.h"

#include "CopyrightDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  

AssistTools::CopyrightDataImpl
	::CopyrightDataImpl(int endYear, const System::String& versions, const System::String& projectChineseName)
	:m_EndYear(endYear), m_Versions(versions), m_ProjectChineseName(projectChineseName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools,CopyrightDataImpl)

int AssistTools::CopyrightDataImpl
	::GetEndYear() const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_EndYear;
}

const System::String AssistTools::CopyrightDataImpl
	::GetVersions() const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Versions;
}

const System::String AssistTools::CopyrightDataImpl
	::GetProjectChineseName() const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_ProjectChineseName;
}
