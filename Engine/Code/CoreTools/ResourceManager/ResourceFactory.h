// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:06)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_FACTORY_H
#define CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ResourceManager/Flags/ResourceManagerFlags.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class BaseResourceManager;

	class CORE_TOOLS_DEFAULT_DECLARE ResourceFactory : private boost::noncopyable
	{
	public:
		using ClassType = ResourceFactory;

	public:
		explicit ResourceFactory(BaseResourceManager& resourceManager) noexcept;
		virtual ~ResourceFactory();
		ResourceFactory(const ResourceFactory&) = delete;
		ResourceFactory& operator=(const ResourceFactory&) = delete;
		ResourceFactory(ResourceFactory&&) noexcept = delete;
		ResourceFactory& operator=(ResourceFactory&&) noexcept = delete;
		
		virtual uint32_t CreateResource(PriorityType type, int size);

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	private:
		BaseResourceManager& m_ResourceManager;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_RESOURCE_FACTORY_H