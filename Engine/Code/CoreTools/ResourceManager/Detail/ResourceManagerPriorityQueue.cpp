// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:08)

#include "CoreTools/CoreToolsExport.h"

#include "ResourceManagerPriorityQueue.h"
#include "CoreTools/ResourceManager/BaseResource.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"      

CoreTools::ResourceManagerPriorityQueue
	::ResourceManagerPriorityQueue() noexcept
	:m_PriorityQueue{} 
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ResourceManagerPriorityQueue)

void CoreTools::ResourceManagerPriorityQueue
	::Insert(const ResourceAssociatedContainerValueType& resource)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto resourcePtr = resource.second;

	if (!resourcePtr->IsDisposed() && !resourcePtr->IsLocked())
	{
		m_PriorityQueue.push(resourcePtr);
	}
}

bool CoreTools::ResourceManagerPriorityQueue
	::IsEmpty() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_PriorityQueue.empty();
}

uint32_t CoreTools::ResourceManagerPriorityQueue
	::Dispose()
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;
	CORE_TOOLS_ASSERTION_0(!m_PriorityQueue.empty(), "集合是空的！");

	const auto disposalSize = m_PriorityQueue.top()->GetSize();

	m_PriorityQueue.top()->Dispose();
	m_PriorityQueue.pop();

	return disposalSize;
}
