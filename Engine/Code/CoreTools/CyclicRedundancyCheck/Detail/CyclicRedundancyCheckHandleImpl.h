// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:48)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CyclicRedundancyCheckCCITTTable.h"
#include "CyclicRedundancyCheck16Table.h"
#include "CyclicRedundancyCheck32Table.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckHandleImpl
	{
	public:
		using ClassType = CyclicRedundancyCheckHandleImpl;

	public:
		CyclicRedundancyCheckHandleImpl();

		CLASS_INVARIANT_DECLARE;

		uint16_t GetCCITT(int index) const;
		uint16_t Get16Table(int index) const;
		uint32_t Get32Table(int index) const;

	private:
		CyclicRedundancyCheckCCITTTable m_CCITT;
		CyclicRedundancyCheck16Table m_Table16;
		CyclicRedundancyCheck32Table m_Table32;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_IMPL_H
