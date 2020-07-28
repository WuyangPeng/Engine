// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:17)

#include "CoreTools/CoreToolsExport.h"

#include "FrameMemorySystemImplDetail.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26490)
using namespace std::literals;
// m_ByteAlignment必须是2的幂。
CoreTools::BaseFrameMemorySystemImpl
	::BaseFrameMemorySystemImpl(int sizeInBytes, int byteAlignment)
	:m_SizeInBytes{ sizeInBytes }, m_ByteAlignment{ byteAlignment }, m_MemoryBlock{ nullptr }, m_FramePointer{}, m_BaseAndCapPointer{}
{
	Init();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BaseFrameMemorySystemImpl
	::~BaseFrameMemorySystemImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	System::FreeMemory(m_MemoryBlock);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BaseFrameMemorySystemImpl
	::IsValid() const noexcept
{
	if (m_SizeInBytes % m_ByteAlignment == 0 && m_MemoryBlock != nullptr &&
		m_BaseAndCapPointer[sm_Lower] <= m_FramePointer[sm_Lower] &&
		m_FramePointer[sm_Lower] < m_FramePointer[sm_Upper] &&
		m_FramePointer[sm_Upper] <= m_BaseAndCapPointer[sm_Upper])
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::BaseFrameMemorySystemImpl
	::AlignUp(int sizeInBytes, int byteAlignment)  
{
	return (boost::numeric_cast<uint32_t>(sizeInBytes) + byteAlignment - 1) & (~(byteAlignment - 1));
}

// 返回一个指针，指向基本的内存块。如果没有足够的内存，则抛出异常。
const CoreTools::FrameMemorySystemPointerShare CoreTools::BaseFrameMemorySystemImpl
	::AllocFrameMemory(int bytes, FrameMemorySystemHeap heapType)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	// 首先，调整所要求的大小：
	bytes = AlignUp(bytes, m_ByteAlignment);

	// 检查可用内存：
	if (m_FramePointer[sm_Upper] < m_FramePointer[sm_Lower] + bytes)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("内存不足"s));
	}

	// 现在执行的内存分配：
	uint8_t* ptr{ nullptr };

	if (heapType == FrameMemorySystemHeap::Upper)
	{
		// 从上堆，下分配：        
		m_FramePointer[sm_Upper] -= bytes;
		ptr = m_FramePointer[sm_Upper];
	}
	else
	{
		// 从下堆，上分配：        
		ptr = m_FramePointer[sm_Lower];
		m_FramePointer[sm_Lower] += bytes;
	}

	return FrameMemorySystemPointerShare{ ptr, bytes, m_FramePointer[sm_Lower],m_FramePointer[sm_Upper],heapType };
}

void CoreTools::BaseFrameMemorySystemImpl
	::ReleaseFrame(FrameMemorySystemPointerShare ptr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	// 检查有效性，如果释放较低的堆：FrameMemorySystemHeapTypeLower
	CORE_TOOLS_ASSERTION_0(ptr.GetFrameMemorySystemHeapType() == FrameMemorySystemHeap::Upper || ptr.GetFramePointer() <= m_FramePointer[sm_Lower], "释放低堆错误！");

	// 检查有效性，如果释放较高的堆：FrameMemorySystemHeapTypeUpper
	CORE_TOOLS_ASSERTION_0(ptr.GetFrameMemorySystemHeapType() == FrameMemorySystemHeap::Lower || m_FramePointer[sm_Upper] <= ptr.GetFramePointer(), "释放高堆错误！");

	// 释放帧：
	m_FramePointer[System::EnumCastUnderlying(ptr.GetFrameMemorySystemHeapType())] = ptr.GetFramePointer();
}

void CoreTools::BaseFrameMemorySystemImpl
	::Init()
{
	// 确保m_SizeInBytes是m_ByteAlignment的倍数：
	m_SizeInBytes = AlignUp(m_SizeInBytes, m_ByteAlignment);

	// 首先我们分配内存块：
	const auto size = m_SizeInBytes + m_ByteAlignment;
	m_MemoryBlock = static_cast<uint8_t*>(System::MallocMemory(size));

	if (m_MemoryBlock == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("没有足够的内存。"s));
	}

	// 设置基指针：
	m_BaseAndCapPointer[sm_Lower] = reinterpret_cast<uint8_t*>(boost::numeric_cast<size_t>(AlignUp(m_MemoryBlock, m_ByteAlignment)));

	// 设置上限指针：
	m_BaseAndCapPointer[sm_Upper] = reinterpret_cast<uint8_t*>(boost::numeric_cast<size_t>(AlignUp(m_MemoryBlock + m_SizeInBytes, m_ByteAlignment)));

	// 最后，初始化上、下帧指针：
	m_FramePointer[sm_Lower] = m_BaseAndCapPointer[sm_Lower];
	m_FramePointer[sm_Upper] = m_BaseAndCapPointer[sm_Upper];
}


#include STSTEM_WARNING_POP