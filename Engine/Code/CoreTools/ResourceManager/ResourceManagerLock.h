// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:06)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_H
#define CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);
CORE_TOOLS_EXPORT_SHARED_PTR(ResourceManagerLockImpl);

namespace CoreTools
{
	class BaseResource;
	class BaseResourceManager;

	class CORE_TOOLS_DEFAULT_DECLARE ResourceManagerLock : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ResourceManagerLock);
		using ResourceType = BaseResource;
		using ResourceSharedPtr = std::shared_ptr<ResourceType>;

	public:
		explicit ResourceManagerLock(BaseResourceManager& manager, uint32_t uniqueID);

		CLASS_INVARIANT_DECLARE;

		const ResourceSharedPtr GetResourceSharedPtr() const noexcept;

	private:
		IMPL_TYPE_DECLARE(ResourceManagerLock);
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BRESOURCE_MANAGER_LOCK_H