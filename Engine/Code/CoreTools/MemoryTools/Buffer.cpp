// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:33)

#include "CoreTools/CoreToolsExport.h"

#include "BufferPool.h"
#include "Buffer.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::Buffer
	::Buffer()
	:m_MemoryLength{ GetMaxSize() }, m_Memory{ NEW1<uint8_t>(m_MemoryLength) }
{
	ResetData();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Buffer
	::Buffer(int minSize)
	:m_MemoryLength{ minSize }, m_Memory{ NEW1<uint8_t>(m_MemoryLength) }
{
	ResetData();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Buffer
	::~Buffer() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26477)
		DELETE1<uint8_t>(m_Memory);
	#include STSTEM_WARNING_POP
	}
	EXCEPTION_ALL_CATCH(CoreTools)	
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::Buffer
	::IsValid() const noexcept
{
	if (0 < m_MemoryLength && m_MemoryLength <= GetMaxSize() && m_Memory != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::Buffer
	::GetMaxSize() noexcept
{
	return sm_MaxSize;
}

int CoreTools::Buffer
	::GetSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_MemoryLength;
}

void CoreTools::Buffer
	::ResetData() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

#ifdef _DEBUG
	System::MemorySet(m_Memory, 0xFE, m_MemoryLength);
#else // !_DEBUG
	System::MemorySet(m_Memory, 0, m_MemoryLength);
#endif // _DEBUG
}

uint8_t* CoreTools::Buffer
	::GetMemory() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(uint8_t*, GetMemory);
}

const uint8_t* CoreTools::Buffer
	::GetMemory() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Memory;
}

#include STSTEM_WARNING_POP