// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 17:55)

#include "CoreTools/CoreToolsExport.h"

#include "EquilongReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;

CoreTools::EquilongReportOutputImpl
	::EquilongReportOutputImpl(int borderLineLength, const OStreamShared& osPtr) noexcept
	:ParentType{ osPtr }, m_BorderLineLength{ borderLineLength }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 
#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::EquilongReportOutputImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 < m_BorderLineLength)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::EquilongReportOutputImpl
	::PrintBorderLine(char character)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	string borderLine(m_BorderLineLength, character);

	PrintString(borderLine);
}

// protected
int CoreTools::EquilongReportOutputImpl
	::GetBorderLineLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BorderLineLength;
}
