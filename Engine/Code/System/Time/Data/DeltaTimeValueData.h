// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 13:20)

#ifndef SYSTEM_TIME_DELTA_TIME_VALUE_H
#define SYSTEM_TIME_DELTA_TIME_VALUE_H

#include "System/SystemDll.h"  

#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
	// 时间差值数据
	class SYSTEM_DEFAULT_DECLARE DeltaTimeValueData
	{
	public:
		using ClassType = DeltaTimeValueData;

	public:
		DeltaTimeValueData() noexcept;
		DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept;
		explicit DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept;

		const DeltaTimeValue GetDeltaTimeValue() const noexcept;
		void SetValue(int64_t second, int32_t microsecond) noexcept;
		int64_t GetSecond() const noexcept;
		int32_t GetMicrosecond() const noexcept;

		void Correction() noexcept;

	public:
		DeltaTimeValue m_DeltaTimeValue;
	};

	DeltaTimeValueData SYSTEM_DEFAULT_DECLARE operator -(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept;
}

#endif // SYSTEM_TIME_DELTA_TIME_VALUE_H