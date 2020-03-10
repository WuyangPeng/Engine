// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:06)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_H
#define CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(BaseResourceManagerImpl);

namespace CoreTools
{
	class BaseResource;

	class CORE_TOOLS_DEFAULT_DECLARE BaseResourceManager
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(BaseResourceManager);
		using ResourceType = BaseResource;
		using ResourceSharedPtr = std::shared_ptr<ResourceType>;
		using ResourceWeakPtr = std::weak_ptr<ResourceType>;

	public:
		explicit BaseResourceManager(uint32_t maxSize);

		CLASS_INVARIANT_DECLARE;

		void SetMaximumMemory(uint32_t maxSize);
		uint32_t GetMaximumMemory() const noexcept;

		void GotoBegin();
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
		IMPL_TYPE_DECLARE(BaseResourceManager);
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_H