// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:46)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::BufferInStreamImpl
	::BufferInStreamImpl(const FileBufferPtr& bufferInformation, int startPoint)
	:m_StartPoint{ startPoint }, m_TopLevel{}, m_Source{ bufferInformation }, m_ObjectLink{}
{
	AnalysisBuffer();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BufferInStreamImpl
	::AnalysisBuffer()
{
	IncrementBytesProcessed();

	// ���ؼ����е�Ψһ����
	while (m_Source.GetBytesRead() < m_Source.GetBytesTotal())
	{
		ReadObject();
	}

	m_ObjectLink.Sort();

	Link();
	PostLink();
}

// private
void CoreTools::BufferInStreamImpl
	::IncrementBytesProcessed()
{
	if (0 < m_StartPoint)
	{
		m_Source.IncrementBytesProcessed(m_StartPoint);
	}
}

// private
void CoreTools::BufferInStreamImpl
	::ReadObject()
{
	// ��ȡ"Top Level"����RTTI����
	auto name = m_Source.ReadString();
	auto isTopLevel = (name == TopLevel::GetTopLevelDescription());
	if (isTopLevel)
	{
		// ��ȡRTTI����
		name = m_Source.ReadString();
	}

	CreateObject(isTopLevel, name);
}

// private
void CoreTools::BufferInStreamImpl
	::CreateObject(bool isTopLevel, const string& name)
{
	// �õ���Ҫ����ȡ�����͵Ĺ����������������Object::Find(name)ʧ�ܣ���ȷ��������ʹ���������֮ǰ
	// ��'main' �� 'WinMain'�е���InitTerm::ExecuteInitializers() ,��ʼ������乤��map�ͶԹ�������������䡣
	try
	{
		DoCreateObject(isTopLevel, name);
	}
	catch (Error& error)
	{
		// ��ȷ�����Ѿ����CORE_TOOLS_REGISTER_STREAM(someclass)��ÿһ��'someclass'��ͷ�ļ��С��������ÿ����ע�Ṥ��������
		LOG_SINGLETON_ENGINE_APPENDER(Fatal, CoreTools)
			<< error << SYSTEM_TEXT("��") << name << SYSTEM_TEXT("��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

// private
void CoreTools::BufferInStreamImpl
	::DoCreateObject(bool isTopLevel, const string& name)
{
	auto factory = OBJECT_MANAGER_SINGLETON.Find(name);

	// ��Դ���������ظö���
	auto object = (*factory)(m_Source);
	m_ObjectLink.Insert(object->GetUniqueID(), object);

	// ��������Ӧ�ó���ʹ�õĶ������
	if (isTopLevel)
	{
		m_TopLevel.Insert(object);
	}
}

// private
void CoreTools::BufferInStreamImpl
	::Link()
{
	// ���Ӷ�����������ȡ���洢������Object*�����ݳ�Ա�ľɵ�ַ��
	// �µ�ַ���ڵ�ǰ���ó�������ʱ������
	auto orderedSize = m_ObjectLink.GetOrderedSize();

	for (auto i = 0; i < orderedSize; ++i)
	{
		m_ObjectLink[i]->Link(m_ObjectLink);
	}
}

// private
void CoreTools::BufferInStreamImpl
	::PostLink()
{
	// �������ִ�����Ӻ�����塣�ڶ�ȡ�������ӵ�ģʽ�У�
	// Ĭ�Ϲ��캯�����ڴ���һ���������е������ټ��ء����������Ӵ����Ķ���
	// �����Ӻ�����Ӧ�ó�������ʱ��������ʱ������һЩ��Ĭ�Ϲ��캯�������Ĺ�����
	auto orderedSize = m_ObjectLink.GetOrderedSize();

	for (auto i = 0; i < orderedSize; ++i)
	{
		m_ObjectLink[i]->PostLink();
	}
}

CoreTools::BufferInStreamImpl
	::~BufferInStreamImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferInStreamImpl
	::IsValid() const noexcept
{
	if (0 <= m_StartPoint)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const CoreTools::InTopLevel CoreTools::BufferInStreamImpl
	::GetTopLevel() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_TopLevel;
}

