// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:27)

#include "CoreTools/CoreToolsExport.h"

#include "BitProxy.h"
#include "ArrayProxy.h"
#include "BitArray2D.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ArrayProxy
	::ArrayProxy(BitArray2D& arrayProxy, int pos) noexcept
	:m_Array{ arrayProxy }, m_Position{ pos }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ArrayProxy
	::ArrayProxy(const ArrayProxy& rhs) noexcept
	:m_Array{ rhs.m_Array }, m_Position{ rhs.m_Position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ArrayProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::BitProxy	CoreTools::ArrayProxy
	::operator[](int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return BitProxy{ m_Array.GetBitArray(), m_Position * m_Array.GetWidth() + position };
}


