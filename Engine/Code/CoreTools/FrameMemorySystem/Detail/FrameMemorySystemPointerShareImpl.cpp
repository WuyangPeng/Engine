// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:18)

#include "CoreTools/CoreToolsExport.h"

#include "FrameMemorySystemPointerShareImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using namespace std::literals;

CoreTools::FrameMemorySystemPointerShareImpl
	::FrameMemorySystemPointerShareImpl(uint8_t* ptr, int size, uint8_t*& lowerFramePointer, uint8_t*& upperFramePointer, FrameMemorySystemHeap type) noexcept
	:m_Ptr{ ptr }, m_Size{ size }, m_LowerFramePointer{ lowerFramePointer }, m_UpperFramePointer{ upperFramePointer }, m_Type{ type }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::FrameMemorySystemPointerShareImpl
	::IsValid() const noexcept
{
	if (m_Ptr != nullptr && m_LowerFramePointer != nullptr && m_UpperFramePointer != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint8_t* CoreTools::FrameMemorySystemPointerShareImpl
	::GetFramePointer()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(uint8_t*, GetFramePointer);
}

const uint8_t* CoreTools::FrameMemorySystemPointerShareImpl
	::GetFramePointer() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	if (m_Type == FrameMemorySystemHeap::Lower)
	{
		if (m_Ptr <= m_LowerFramePointer)
		{
			return m_Ptr;
		}
	}
	else
	{
		if (m_UpperFramePointer <= m_Ptr)
		{
			return m_Ptr;
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°÷°÷∏’Î ß∞‹"s));
}

int CoreTools::FrameMemorySystemPointerShareImpl
	::GetPtrSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Size;
}

CoreTools::FrameMemorySystemHeap CoreTools::FrameMemorySystemPointerShareImpl
	::GetFrameMemorySystemHeapType() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Type;
}