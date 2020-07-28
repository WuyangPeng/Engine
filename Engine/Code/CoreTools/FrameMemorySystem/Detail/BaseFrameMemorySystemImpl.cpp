// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:17)

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
// m_ByteAlignment������2���ݡ�
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

// ����һ��ָ�룬ָ��������ڴ�顣���û���㹻���ڴ棬���׳��쳣��
const CoreTools::FrameMemorySystemPointerShare CoreTools::BaseFrameMemorySystemImpl
	::AllocFrameMemory(int bytes, FrameMemorySystemHeap heapType)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	// ���ȣ�������Ҫ��Ĵ�С��
	bytes = AlignUp(bytes, m_ByteAlignment);

	// �������ڴ棺
	if (m_FramePointer[sm_Upper] < m_FramePointer[sm_Lower] + bytes)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�ڴ治��"s));
	}

	// ����ִ�е��ڴ���䣺
	uint8_t* ptr{ nullptr };

	if (heapType == FrameMemorySystemHeap::Upper)
	{
		// ���϶ѣ��·��䣺        
		m_FramePointer[sm_Upper] -= bytes;
		ptr = m_FramePointer[sm_Upper];
	}
	else
	{
		// ���¶ѣ��Ϸ��䣺        
		ptr = m_FramePointer[sm_Lower];
		m_FramePointer[sm_Lower] += bytes;
	}

	return FrameMemorySystemPointerShare{ ptr, bytes, m_FramePointer[sm_Lower],m_FramePointer[sm_Upper],heapType };
}

void CoreTools::BaseFrameMemorySystemImpl
	::ReleaseFrame(FrameMemorySystemPointerShare ptr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	// �����Ч�ԣ�����ͷŽϵ͵Ķѣ�FrameMemorySystemHeapTypeLower
	CORE_TOOLS_ASSERTION_0(ptr.GetFrameMemorySystemHeapType() == FrameMemorySystemHeap::Upper || ptr.GetFramePointer() <= m_FramePointer[sm_Lower], "�ͷŵͶѴ���");

	// �����Ч�ԣ�����ͷŽϸߵĶѣ�FrameMemorySystemHeapTypeUpper
	CORE_TOOLS_ASSERTION_0(ptr.GetFrameMemorySystemHeapType() == FrameMemorySystemHeap::Lower || m_FramePointer[sm_Upper] <= ptr.GetFramePointer(), "�ͷŸ߶Ѵ���");

	// �ͷ�֡��
	m_FramePointer[System::EnumCastUnderlying(ptr.GetFrameMemorySystemHeapType())] = ptr.GetFramePointer();
}

void CoreTools::BaseFrameMemorySystemImpl
	::Init()
{
	// ȷ��m_SizeInBytes��m_ByteAlignment�ı�����
	m_SizeInBytes = AlignUp(m_SizeInBytes, m_ByteAlignment);

	// �������Ƿ����ڴ�飺
	const auto size = m_SizeInBytes + m_ByteAlignment;
	m_MemoryBlock = static_cast<uint8_t*>(System::MallocMemory(size));

	if (m_MemoryBlock == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("û���㹻���ڴ档"s));
	}

	// ���û�ָ�룺
	m_BaseAndCapPointer[sm_Lower] = reinterpret_cast<uint8_t*>(boost::numeric_cast<size_t>(AlignUp(m_MemoryBlock, m_ByteAlignment)));

	// ��������ָ�룺
	m_BaseAndCapPointer[sm_Upper] = reinterpret_cast<uint8_t*>(boost::numeric_cast<size_t>(AlignUp(m_MemoryBlock + m_SizeInBytes, m_ByteAlignment)));

	// ��󣬳�ʼ���ϡ���ָ֡�룺
	m_FramePointer[sm_Lower] = m_BaseAndCapPointer[sm_Lower];
	m_FramePointer[sm_Upper] = m_BaseAndCapPointer[sm_Upper];
}


#include STSTEM_WARNING_POP