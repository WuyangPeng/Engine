// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 17:55)

#include "CoreTools/CoreToolsExport.h"

#include "ReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;

CoreTools::ReportOutput
	::ReportOutput(const OStreamShared& osPtr)
	:m_OsPtr{ osPtr }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ReportOutput
	::~ReportOutput()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReportOutput
	::IsValid() const noexcept
{
 
		return true; 
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::ReportOutput
	::PrintString(const string& characterString)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_OsPtr << characterString;
}

void CoreTools::ReportOutput
	::PrintNewLine()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_OsPtr << '\n';
}

void CoreTools::ReportOutput
	::PrintNumber(int number)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_OsPtr << number;
}

// protected
CoreTools::OStreamShared  CoreTools::ReportOutput
	::GetStream()  
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_OsPtr;
}




