// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:05)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_MANAGER_H
#define CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class BaseResource;

	class CORE_TOOLS_HIDDEN_DECLARE BaseResourceLockManager : boost::noncopyable
	{
	public:
		using ClassType = BaseResourceLockManager;

	public:
		explicit BaseResourceLockManager(BaseResource& manager);
		~BaseResourceLockManager();

		CLASS_INVARIANT_DECLARE;

	private:
		BaseResource& m_Manager;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_MANAGER_H