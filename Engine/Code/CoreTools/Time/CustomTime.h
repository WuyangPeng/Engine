// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:55)

#ifndef CORE_TOOLS_TIME_CUSTOM_TIME_H 
#define CORE_TOOLS_TIME_CUSTOM_TIME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CustomTime
	{
	public:
		using ClassType = CustomTime;
		using String = System::String;

	public:
		CustomTime();

		CLASS_INVARIANT_DECLARE;

		void ResetCustomTime() noexcept;
		int64_t GetThisElapsedTime() noexcept;
		int64_t GetNowTime() noexcept;

		int64_t GetThisElapsedMillisecondTime() noexcept;
		int64_t GetNowMillisecondTime() noexcept;

		static String GetSystemTimeDescribe();
		static String GetSystemTimeDescribe(const String& dateFormat);

	private:
		void MarkTimeThisTick() noexcept;

	private:
		int64_t m_StartTime;
		int64_t m_CurrentTime;
		int64_t m_TimeLastTick;
	};
}

#endif // CORE_TOOLS_TIME_CUSTOM_TIME_H
