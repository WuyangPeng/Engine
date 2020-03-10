// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:07)

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
		// 尝试从资源管理器中删除memoryToPurge字节
		auto memoryToPurge = m_CurrentUsedMemory - m_MaximumMemory;

		// 创建临时的优先级队列来存储管理项
		ResourceManagerPriorityQueue priorityQueue{};

		// 插入所有资源指针的拷贝到优先级队列中，
		// 但不包括那些当前未使用或被锁定的资源
		for_each(m_ResourceContainer.begin(), m_ResourceContainer.end(), bind(&ResourceManagerPriorityQueue::Insert, ref(priorityQueue), _1));

		while ((!priorityQueue.IsEmpty()) && (m_MaximumMemory < m_CurrentUsedMemory) && (0 < memoryToPurge))
		{
			auto disposalSize = priorityQueue.Dispose();

			RemoveMemory(disposalSize);
			memoryToPurge -= disposalSize;
		}

		// 如果资源队列为空，我们还有太多的内存要分配，那么我们就触发一个断言。这可能发生在过多的资源被锁定，
		// 或者插入资源比所要求的最大内存更大，修改更大的内存以适应情况。
		if (priorityQueue.IsEmpty() && (m_MaximumMemory < m_CurrentUsedMemory))
		{
			m_MaximumMemory = m_CurrentUsedMemory;
			CORE_TOOLS_ASSERTION_2(false, "分配的内存不足！");
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
		THROW_EXCEPTION(SYSTEM_TEXT("提取当前资源错误！"));
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
		THROW_EXCEPTION(SYSTEM_TEXT("当前资源已到数组末！"));
	}
}

uint32_t CoreTools::BaseResourceManagerImpl
	::InsertResource(ResourceSharedPtr resource)
{
	CORE_TOOLS_CLASS_IS_VALID_2;

	// 获取这个类别下一个唯一的ID
	auto uniqueID = GetNextResourceHandle();

	// 插入将资源到当前类别的map
	m_ResourceContainer.insert(make_pair(uniqueID, resource));

	// 得到内存，并把它添加到类别总数。需要注意的是，我们需要检查内存过度分配。
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
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID不存在！"));
	}

	auto originalSize = iter->second->GetSize();

	// 修改资源到当前类别的map。
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

	// 试图找到指定的资源
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
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID不是有效的。"));
	}

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无法找到要删除的资源。"));
	}

	auto resource = iter->second;

	// 如果资源被找到，检查看它有没有被锁定
	if (resource->IsLocked())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无法删除被锁住的资源。"));
	}

	if (m_CurrentResource != m_ResourceContainer.end() && iter == m_CurrentResource)
	{
		m_CurrentResource = m_ResourceContainer.end();
	}

	// 获取内存，并从管理器总数减去它。
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
		THROW_EXCEPTION(SYSTEM_TEXT("资源未找到！"));
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
		THROW_EXCEPTION(SYSTEM_TEXT("资源未找到！"));
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
		THROW_EXCEPTION(SYSTEM_TEXT("uniqueID无效！"));
	}

	auto iter = m_ResourceContainer.find(uniqueID);
	if (iter == m_ResourceContainer.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("资源未找到！"));
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








