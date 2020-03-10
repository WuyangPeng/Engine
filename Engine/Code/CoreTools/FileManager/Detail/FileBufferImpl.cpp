// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 15:22)

#include "CoreTools/CoreToolsExport.h"

#include "FileBufferImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::FileBufferImpl
	::FileBufferImpl(size_t count)
	:m_Buffer(count)
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::FileBufferImpl
	::IsValid() const noexcept
{
	if (0u < m_Buffer.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const char* CoreTools::FileBufferImpl
	::GetBufferBegin() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Buffer.data();
}

size_t CoreTools::FileBufferImpl
	::GetSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Buffer.size();
}

char* CoreTools::FileBufferImpl
	::GetBufferBegin() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetBufferBegin);
}

