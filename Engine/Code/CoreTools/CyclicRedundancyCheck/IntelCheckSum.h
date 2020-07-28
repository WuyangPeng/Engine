// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE IntelCheckSum
	{
	public:
		using ClassType = IntelCheckSum;

	public:
		IntelCheckSum(const char* data, int length) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetIntelCheckSum() const noexcept;

	private:
		void Calculation(const char* data, int length) noexcept;

	private:
		int m_IntelCheckSum;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_INTEL_CHECK_SUM_H
