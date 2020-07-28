// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:27)

#include "CoreTools/CoreToolsExport.h"

#include "BitProxy.h"
#include "BitArray.h"
#include "ConstBitProxy.h"
#include "System/Helper/PragmaWarning.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26481)
using std::swap;

CoreTools::BitArray
	::BitArray(int size)
	:m_Store{ nullptr }, m_SingleWord{ 0 }, m_Length{ 0 }, m_NumBits{ size }
{
	Init();

	// 清除最后位
	Trim();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BitArray
	::Init()
{
	if (m_NumBits == 0)
	{
		m_Length = 0;
	}
	else
	{
		m_Length = 1 + GetIndex(m_NumBits - 1);
	}

	// 如果长度为1，避免分配（通常情况下）
	if (m_Length <= 1)
	{
		m_Store = &m_SingleWord;
	}
	else
	{
		m_Store = NEW1<uint32_t>(m_Length);
	}
}

// private
void CoreTools::BitArray
	::Trim() noexcept
{
	const auto extraBits = m_NumBits % sm_CellSize;
	if (0 < m_Length && extraBits != 0)
	{
		
#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26481)
		m_Store[m_Length - 1] &= ~((~uint32_t(0)) << extraBits);

#include STSTEM_WARNING_POP
	}
}

CoreTools::BitArray
	::BitArray(const BitArray& rhs)
	:m_Store{ nullptr }, m_SingleWord{ rhs.m_SingleWord },
	 m_Length{ rhs.m_Length }, m_NumBits{ rhs.m_NumBits }
{
	Init();

	System::MemoryCopy(m_Store, rhs.m_Store, m_Length * sizeof(uint32_t));

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BitArray
	::~BitArray() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
 
#include STSTEM_WARNING_PUSH
	
#include SYSTEM_WARNING_DISABLE(26447)

	EXCEPTION_TRY
	{
		if(1 < m_Length)
		{
			DELETE1(m_Store);
		}
	}
	EXCEPTION_ALL_CATCH(CoreTools)		
		
#include STSTEM_WARNING_POP
}

CoreTools::BitArray& CoreTools::BitArray
	::operator=(const BitArray& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	BitArray temp{ rhs };

	Swap(temp);

	return *this;
}

// private
void CoreTools::BitArray
	::Swap(BitArray& rhs) noexcept
{
	swap(m_SingleWord, rhs.m_SingleWord);
	swap(m_Length, rhs.m_Length);
	swap(m_NumBits, rhs.m_NumBits);

	if (m_Length <= 1)
	{
		m_Store = &m_SingleWord;
		rhs.m_Store = &rhs.m_SingleWord;
	}
	else
	{
		swap(m_Store, rhs.m_Store);
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BitArray
	::IsValid() const noexcept
{
	if (0 < m_Length && 0 < m_NumBits)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::BitProxy	CoreTools::BitArray
	::operator[](int position)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");

	return BitProxy{ *this, position };
}

CoreTools::ConstBitProxy CoreTools::BitArray
	::operator[](int position) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");

	return ConstBitProxy{ *this, position };
}

CoreTools::BitArray& CoreTools::BitArray
	::operator&=(const BitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(m_NumBits == rhs.m_NumBits, "位数不相等");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	for (auto i = 0; i < m_Length; i++)
	{
		m_Store[i] &= rhs.m_Store[i];
	}

	return *this;
}

CoreTools::BitArray& CoreTools::BitArray
	::operator|=(const BitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(m_NumBits == rhs.m_NumBits, "位数不相等");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	for (auto i = 0; i < m_Length; i++)
	{			
		m_Store[i] |= rhs.m_Store[i];
	}

	return *this;
}

CoreTools::BitArray& CoreTools::BitArray
	::operator^=(const BitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(m_NumBits == rhs.m_NumBits, "位数不相等");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	for (auto i = 0; i < m_Length; i++)
	{
		m_Store[i] ^= rhs.m_Store[i];
	}

	return *this;
}

const CoreTools::BitArray CoreTools::BitArray
	::operator~() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	BitArray bitArray{ *this };
	bitArray.FlipAllBits();

	return bitArray;
}

void CoreTools::BitArray
	::Clear() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	System::MemorySet(m_Store, 0, m_Length * sizeof(uint32_t));
}

void CoreTools::BitArray
	::SetBit(int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	m_Store[GetIndex(position)] |= (1 << GetOffset(position));
}

void CoreTools::BitArray
	::ClearBit(int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	m_Store[GetIndex(position)] &= ~(1 << GetOffset(position));
}

void CoreTools::BitArray
	::FlipBit(int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	m_Store[GetIndex(position)] ^= (1 << GetOffset(position));
}

void CoreTools::BitArray
	::Set(int position, bool value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	value ? SetBit(position) : ClearBit(position);
}

bool CoreTools::BitArray
	::IsBitSet(int position) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_0(0 <= position && position < m_NumBits, "索引错误");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return (m_Store[GetIndex(position)] & (1 << GetOffset(position))) != 0;
}

bool CoreTools::BitArray
	::AllBitsFalse() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	for (auto i = 0; i < m_Length; ++i)
	{
		if (m_Store[i] != 0)
			return false;
	}
	return true;
}

void CoreTools::BitArray
	::FlipAllBits() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	for (auto i = 0; i < m_Length; ++i)
	{
		m_Store[i] = ~m_Store[i];
	}

	Trim();
}

int CoreTools::BitArray
	::GetNumBits() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_NumBits;
}

int CoreTools::BitArray
	::GetLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Length;
}

bool CoreTools
	::operator==(const BitArray& lhs, const BitArray& rhs) noexcept
{
	const auto lhsNumBits = lhs.GetNumBits();
	const auto rhsNumBits = rhs.GetNumBits();

	if (lhsNumBits != rhsNumBits)
	{
		return false;
	}

	for (auto i = 0; i < lhsNumBits; i++)
	{
		if (lhs.IsBitSet(i) != rhs.IsBitSet(i))
			return false;
	}

	return true;
}


#include STSTEM_WARNING_POP
