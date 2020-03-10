// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 09:55)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"  

#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE UniqueIDManagerImpl
	{
	public:
		using ClassType = UniqueIDManagerImpl;

	public:
		explicit UniqueIDManagerImpl(int count);

		CLASS_INVARIANT_DECLARE;

	public:
		uint64_t NextUniqueID(int index);

	private:
		using Containers = std::vector<uint64_t>;

	private:
		Containers m_UniqueID;
	};
}

#endif // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_IMPL_H
