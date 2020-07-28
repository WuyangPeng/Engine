// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:41)

#include "CoreTools/CoreToolsExport.h"

#include "ConstTwoBitProxy.h"
#include "TwoBitArray.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ConstTwoBitProxy
	::ConstTwoBitProxy(const TwoBitArray& array, int position) noexcept
	:m_Array{ array }, m_Position{ position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ConstTwoBitProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ConstTwoBitProxy
	::operator uint32_t() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Array.Get(m_Position);
}
