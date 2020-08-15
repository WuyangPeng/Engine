// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:05)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_IMPL_H
#define CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp> 
#include <memory>

namespace CoreTools
{
	class BaseResource;
	class BaseResourceManager;

	class CORE_TOOLS_HIDDEN_DECLARE ResourceManagerLockImpl : private boost::noncopyable
	{
	public:
		using ClassType = ResourceManagerLockImpl;
		using ResourceType = BaseResource;
		using ResourceSharedPtr = std::shared_ptr<ResourceType>;

	public:
		ResourceManagerLockImpl(BaseResourceManager& manager, uint32_t uniqueID);
		~ResourceManagerLockImpl() noexcept;
		ResourceManagerLockImpl(const ResourceManagerLockImpl&) = delete;
		ResourceManagerLockImpl& operator=(const ResourceManagerLockImpl&) = delete;
		ResourceManagerLockImpl(ResourceManagerLockImpl&&) noexcept = delete;
		ResourceManagerLockImpl& operator=(ResourceManagerLockImpl&&) noexcept = delete;
		
		CLASS_INVARIANT_DECLARE;

		const ResourceSharedPtr GetResourceSharedPtr() const noexcept;

	private:
		BaseResourceManager& m_ResourceManager;
		uint32_t m_UniqueID;
		ResourceSharedPtr m_ResourceSharedPtr;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_IMPL_H