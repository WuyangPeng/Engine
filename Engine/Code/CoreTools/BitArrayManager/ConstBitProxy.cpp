// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:41)

#include "CoreTools/CoreToolsExport.h"

#include "ConstBitProxy.h"
#include "BitArray.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ConstBitProxy
	::ConstBitProxy(const BitArray& bitArray, int position) noexcept
	:m_Array{ bitArray }, m_Position{ position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ConstBitProxy
	::ConstBitProxy(const ConstBitProxy& bitProxy) noexcept
	:m_Array{ bitProxy.m_Array }, m_Position{ bitProxy.m_Position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ConstBitProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ConstBitProxy
	::operator bool() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Array.IsBitSet(m_Position);
}



