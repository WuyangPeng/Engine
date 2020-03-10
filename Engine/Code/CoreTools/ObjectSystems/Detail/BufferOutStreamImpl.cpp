// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:47)

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
	// �����ָ�������������ԡ�
	m_ObjectRegister.RegisterRoot(ConstObjectInterfaceSmartPointer());

	// ����Ψһ���󼯺��ڶ���ͼ�С�
	// ʹ���ǿ��Դ�������д�뻺������������������ֽ�����ȷ�д�С��
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

	// ��1��ʼ����
	for (auto i = 1; i < m_ObjectRegister.GetOrderedSize(); ++i)
	{
		bufferSize += m_ObjectRegister[i]->GetStreamingSize();
	}

	// ������������С���ǵ��ˡ�Top Level���ַ�����
	auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
	bufferSize += topLevelBytesNumber * m_TopLevel.GetTopLevelSize();

	return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl
	::ResetBufferSize(int bufferSize)
{
	CORE_TOOLS_ASSERTION_0(0 < bufferSize, "��������СС�ڻ����0��");

	// ��������Ҫ��д��Ļ�������
	m_BufferPtr = make_shared<FileBuffer>(bufferSize);
	m_TargetPtr = make_shared<BufferTarget>(m_BufferPtr, m_ObjectRegister);
}

void CoreTools::BufferOutStreamImpl
	::SaveToBuffer()
{
	// �������Ŀ�껺������
	// ��1��ʼ����
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

