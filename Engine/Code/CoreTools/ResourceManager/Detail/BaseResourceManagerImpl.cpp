// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:07)

#include "CoreTools/CoreToolsExport.h"

#include "BaseResourceManagerImpl.h"
#include "ResourceManagerPriorityQueue.h"
#include "BaseResourceLockManager.h"
#include "CoreTools/ResourceManager/BaseResource.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::bind;
using std::ref;
using std::for_each;
using std::placeholders::_1;

CoreTools::BaseResourceManagerImpl
	::BaseResourceManagerImpl(uint32_t maxSize)
	:m_CurrentUsedMemory{ 0 }, m_MaximumMemory{ maxSize }, m_ResourceContainer{}, m_CurrentResource{ m_ResourceContainer.end() }, m_NextResourceHandle{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_2;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BaseResourceManagerImpl
	::IsValid() const noexcept
{
	try
	{
		if (m_CurrentUsedMemory <= m_MaximumMemory && IsCurrentResourceValid())
			return true;
		else
			return false;
	}
	catch (...)
	{
		return false;
	}
}

bool CoreTools::BaseResourceManagerImpl
	::IsCurrentResourceValid() const
{
	if (m_CurrentResource == m_ResourceContainer.cend())
		return true;

	auto iter = m_ResourceContainer.find(m_CurrentResource->first);

	if (iter != m_ResourceContainer.cend() && iter == m_CurrentResource)
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

void CoreTools::BaseResourceManagerImpl
	::SetMaximumMemory(uint32_t maxSize)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	m_MaximumMemory = maxSize;

	CheckForOverAllocation();
}

// private
void CoreTools::BaseResourceManagerImpl
	::CheckForOverAllocation()
{
	if (m_MaximumMemory < m_CurrentUsedMemory)
	{
		// ���Դ���Դ��������ɾ��memoryToPurge�ֽ�
		auto memoryToPurge = m_CurrentUsedMemory - m_MaximumMemory;

		// ������ʱ�����ȼ��������洢������
		ResourceManagerPriorityQueue priorityQueue{};

		// ����������Դָ��Ŀ��������ȼ������У�
		// ����������Щ��ǰδʹ�û���������Դ
		for_each(m_ResourceContainer.begin(), m_ResourceContainer.end(), bind(&ResourceManagerPriorityQueue::Insert, ref(priorityQueue), _1));

		while ((!priorityQueue.IsEmpty()) && (m_MaximumMemory < m_CurrentUsedMemory) && (0 < memoryToPurge))
		{
			auto disposalSize = priorityQueue.Dispose();

			RemoveMemory(disposalSize);
			memoryToPurge -= disposalSize;
		}

		// �����Դ����Ϊ�գ����ǻ���̫����ڴ�Ҫ���䣬��ô���Ǿʹ���һ�����ԡ�����ܷ����ڹ������Դ��������
		// ���߲�����Դ����Ҫ�������ڴ�����޸ĸ�����ڴ�����Ӧ�����
		if (priorityQueue.IsEmpty() && (m_MaximumMemory < m_CurrentUsedMemory))
		{
			m_MaximumMemory = m_CurrentUsedMemory;
			CORE_TOOLS_ASSERTION_2(false, "������ڴ治�㣡");
		}
	}
}

uint32_t CoreTools::BaseResourceManagerImpl
	::GetMaximumMemory() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_2;

	return m_MaximumMemory;
}

void CoreTools::BaseResourceManagerImpl
	::GotoBegin()
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	m_CurrentResource = m_ResourceContainer.begin();
}

const CoreTools::BaseResourceManagerImpl::ResourceWeakPtr CoreTools::BaseResourceManagerImpl
	::GetCurrentResource() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_2;

	if (m_CurrentResource != m_ResourceContainer.end())
	{
		return m_CurrentResource->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ȡ��ǰ��Դ����"));
	}
}

void CoreTools::BaseResourceManagerImpl
	::GotoNext()
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	if (m_CurrentResource != m_ResourceContainer.end())
	{
		++m_CurrentResource;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ǰ��Դ�ѵ�����ĩ��"));
	}
}

uint32_t CoreTools::BaseResourceManagerImpl
	::InsertResource(ResourceSharedPtr resource)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	// ��ȡ��������һ��Ψһ��ID
	auto uniqueID = GetNextResourceHandle();

	// ���뽫��Դ����ǰ����map
	m_ResourceContainer.insert(make_pair(uniqueID, resource));

	// �õ��ڴ棬��������ӵ������������Ҫע����ǣ�������Ҫ����ڴ���ȷ��䡣
	AddMemory(resource->GetSize());

	return uniqueID;
}

// private
uint32_t CoreTools::BaseResourceManagerImpl
	::GetNextResourceHandle() noexcept
{
	return UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Resource) % sm_InvalidResourceHandle;
}

// private
void CoreTools::BaseResourceManagerImpl
	::AddMemory(uint32_t size)
{
	m_CurrentUsedMemory += size;

	CheckForOverAllocation();
}

void CoreTools::BaseResourceManagerImpl
	::ModifyResource(uint32_t uniqueID, ResourceSharedPtr resource)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.end())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID�����ڣ�"));
	}

	auto originalSize = iter->second->GetSize();

	// �޸���Դ����ǰ����map��
	iter->second = resource;

	auto nowSize = resource->GetSize();

	if (originalSize < nowSize)
	{
		AddMemory(nowSize - originalSize);
	}
	else
	{
		RemoveMemory(originalSize - nowSize);
	}
}

void CoreTools::BaseResourceManagerImpl
	::RemoveResource(ResourceSharedPtr resource)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	auto uniqueID = FindResourceHandle(resource);

	RemoveResource(uniqueID);
}

// private
void CoreTools::BaseResourceManagerImpl
	::RemoveMemory(uint32_t size) noexcept
{
	m_CurrentUsedMemory -= size;
}

uint32_t CoreTools::BaseResourceManagerImpl
	::FindResourceHandle(ResourceSharedPtr resource) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_2;

	// ��ͼ�ҵ�ָ������Դ
	for (const auto& value : m_ResourceContainer)
	{
		if (value.second == resource)
		{
			return value.first;
		}
	}

	return sm_InvalidResourceHandle;
}

bool CoreTools::BaseResourceManagerImpl
	::IsValidResourceHandle(uint32_t uniqueID) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_2;

	if (uniqueID != sm_InvalidResourceHandle)
		return true;
	else
		return false;
}

void CoreTools::BaseResourceManagerImpl
	::RemoveResource(uint32_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	if (!IsValidResourceHandle(uniqueID))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID������Ч�ġ�"));
	}

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�޷��ҵ�Ҫɾ������Դ��"));
	}

	auto resource = iter->second;

	// �����Դ���ҵ�����鿴����û�б�����
	if (resource->IsLocked())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�޷�ɾ������ס����Դ��"));
	}

	if (m_CurrentResource != m_ResourceContainer.end() && iter == m_CurrentResource)
	{
		m_CurrentResource = m_ResourceContainer.end();
	}

	// ��ȡ�ڴ棬���ӹ�����������ȥ����
	RemoveMemory(resource->GetSize());

	m_ResourceContainer.erase(iter);
}

const CoreTools::BaseResourceManagerImpl::ResourceWeakPtr CoreTools::BaseResourceManagerImpl
	::GetResource(uint32_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_2;

	auto iter = m_ResourceContainer.find(uniqueID);

	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��Դδ�ҵ���"));
	}

	auto resource = iter->second;

	resource->SetCurrentTime();

	if (resource->IsDisposed())
	{
		resource->Recreate();
		AddMemory(resource->GetSize());

		BaseResourceLockManager manager{ *resource };

		CheckForOverAllocation();
	}

	return resource;
}

const CoreTools::BaseResourceManagerImpl::ResourceSharedPtr CoreTools::BaseResourceManagerImpl
	::Lock(uint32_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��Դδ�ҵ���"));
	}

	auto resource = iter->second;

	resource->Lock();

	if (resource->IsDisposed())
	{
		resource->Recreate();
		AddMemory(resource->GetSize());
		CheckForOverAllocation();
	}

	return resource;
}

void CoreTools::BaseResourceManagerImpl
	::Unlock(uint32_t uniqueID)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	if (!IsValidResourceHandle(uniqueID))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID��Ч��"));
	}

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��Դδ�ҵ���"));
	}

	auto resource = iter->second;

	resource->Unlock();
}

void CoreTools::BaseResourceManagerImpl
	::Unlock(ResourceSharedPtr resource)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	auto uniqueID = FindResourceHandle(resource);

	Unlock(uniqueID);
}








