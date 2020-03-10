// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:47)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/Stream.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_pair;
using std::make_shared;

CoreTools::BufferOutStreamImpl
	::BufferOutStreamImpl(const OutTopLevel& topLevel)
	:m_TopLevel{ topLevel }, m_ObjectRegister{}, m_BufferPtr{}, m_TargetPtr{}
{
	GenerateBuffer();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BufferOutStreamImpl
	::GenerateBuffer()
{
	Register();

	auto bufferSize = GetBufferSize();

	if (0 < bufferSize)
	{
		ResetBufferSize(bufferSize);
		SaveToBuffer();
	}
}

// private
void CoreTools::BufferOutStreamImpl
	::Register()
{
	// 插入空指针和零索引的配对。
	m_ObjectRegister.RegisterRoot(ConstObjectInterfaceSmartPointer());

	// 创建唯一对象集合在对象图中。
	// 使我们可以创建用于写入缓冲区所需的数据流的字节数的确切大小。
	for (auto index = 0; index < m_TopLevel.GetTopLevelSize(); ++index)
	{
		auto uniqueID = m_TopLevel[index]->Register(m_ObjectRegister);
		m_TopLevel.SetUniqueID(index, uniqueID);
	}
}

// private
int CoreTools::BufferOutStreamImpl
	::GetBufferSize()
{
	auto bufferSize = 0;

	// 从1开始计数
	for (auto i = 1; i < m_ObjectRegister.GetOrderedSize(); ++i)
	{
		bufferSize += m_ObjectRegister[i]->GetStreamingSize();
	}

	// 调整缓冲区大小考虑到了“Top Level”字符串。
	auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
	bufferSize += topLevelBytesNumber * m_TopLevel.GetTopLevelSize();

	return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl
	::ResetBufferSize(int bufferSize)
{
	CORE_TOOLS_ASSERTION_0(0 < bufferSize, "缓冲区大小小于或等于0！");

	// 创建对象将要被写入的缓冲区。
	m_BufferPtr = make_shared<FileBuffer>(bufferSize);
	m_TargetPtr = make_shared<BufferTarget>(m_BufferPtr, m_ObjectRegister);
}

void CoreTools::BufferOutStreamImpl
	::SaveToBuffer()
{
	// 保存对象到目标缓冲区。
	// 从1开始计数
	for (auto i = 1; i < m_ObjectRegister.GetOrderedSize(); ++i)
	{
		if (m_TopLevel.IsTopLevel(m_ObjectRegister[i]->GetUniqueID()))
		{
			m_TargetPtr->WriteString(TopLevel::GetTopLevelDescription());
		}
		m_ObjectRegister[i]->Save(*m_TargetPtr);
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferOutStreamImpl
	::IsValid() const noexcept
{
	if (m_BufferPtr != nullptr && m_TargetPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::BufferOutStreamImpl::FileBufferPtr CoreTools::BufferOutStreamImpl
	::GetBufferOutStreamInformation() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_BufferPtr;
}

