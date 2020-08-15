// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:05)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_IMPL_H
#define CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <map>
#include <memory>

namespace CoreTools
{
	class BaseResource;

	class CORE_TOOLS_HIDDEN_DECLARE BaseResourceManagerImpl
	{
	public:
		using ClassType = BaseResourceManagerImpl;
		using ResourceType = BaseResource;
		using ResourceSharedPtr = std::shared_ptr<ResourceType>;
		using ResourceWeakPtr = std::weak_ptr<ResourceType>;

	public:
		explicit BaseResourceManagerImpl(uint32_t maxSize);

#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_DECLARE;
		bool IsCurrentResourceValid() const;
#endif // OPEN_CLASS_INVARIANT

		void SetMaximumMemory(uint32_t maxSize);
		uint32_t GetMaximumMemory() const noexcept;

		// øÿ÷∆CurrentResource
		void GotoBegin() noexcept;
		const ResourceWeakPtr GetCurrentResource() const;
		void GotoNext();

		uint32_t InsertResource(ResourceSharedPtr resource);
		void ModifyResource(uint32_t uniqueID, ResourceSharedPtr resource);

		void RemoveResource(ResourceSharedPtr resource);
		void RemoveResource(uint32_t uniqueID);

		const ResourceWeakPtr GetResource(uint32_t uniqueID);

		const ResourceSharedPtr Lock(uint32_t uniqueID);

		void Unlock(uint32_t uniqueID);
		void Unlock(ResourceSharedPtr resource);

		uint32_t FindResourceHandle(ResourceSharedPtr resource) const;

		bool IsValidResourceHandle(uint32_t uniqueID) const noexcept;

	private:
		using ResourceSharedPtrContainer = std::map<uint32_t, ResourceSharedPtr>;
		typedef ResourceSharedPtrContainer::iterator ResourceSharedPtrContainerIter;

	private:
		void CheckForOverAllocation();

		void AddMemory(uint32_t size);
		void RemoveMemory(uint32_t size) noexcept;
		uint32_t GetNextResourceHandle();

	private:
		static constexpr uint32_t sm_InvalidResourceHandle{ 0xFFFFFFFF };

		uint32_t m_NextResourceHandle;
		uint32_t m_CurrentUsedMemory;
		uint32_t m_MaximumMemory;
		ResourceSharedPtrContainer m_ResourceContainer;
		ResourceSharedPtrContainerIter m_CurrentResource;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_MANAGER_IMPL_H