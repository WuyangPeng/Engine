// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:05)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_PRIIORITY_QUEUE_H
#define CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_PRIIORITY_QUEUE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TemplateTools/PtrCompare.h"

#include <map>
#include <queue>
#include <vector>
#include <memory>

namespace CoreTools
{
	class BaseResource;

	class CORE_TOOLS_HIDDEN_DECLARE ResourceManagerPriorityQueue
	{
	public:
		using ClassType = ResourceManagerPriorityQueue;
		using ResourceType = BaseResource;
		using ResourceSharedPtr = std::shared_ptr<ResourceType>;
		using ResourceAssociatedContainer = std::map<uint32_t, ResourceSharedPtr>;
		using ResourceAssociatedContainerValueType = ResourceAssociatedContainer::value_type;

	public:
		ResourceManagerPriorityQueue();

		CLASS_INVARIANT_DECLARE;

		void Insert(const ResourceAssociatedContainerValueType& resource);
		uint32_t Dispose();
		bool IsEmpty() const;

	private:
		using ResourceSequentialContainer = std::vector<ResourceSharedPtr>;
		using ResourceCompare = PtrGreater<ResourceSharedPtr>;
		using PriorityQueue = std::priority_queue<ResourceSharedPtr, ResourceSequentialContainer, ResourceCompare>;

	private:
		PriorityQueue m_PriorityQueue;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_PRIIORITY_QUEUE_H