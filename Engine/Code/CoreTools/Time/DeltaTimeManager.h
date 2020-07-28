// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:55)

#ifndef CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H 
#define CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(DeltaTimeManagerImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE DeltaTimeManager
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(DeltaTimeManager);

	public:
		DeltaTimeManager();

		CLASS_INVARIANT_DECLARE;

		void ResetCurrentTime();
		uint64_t GetElapsedTimeInMicroseconds() const noexcept;
		uint64_t GetElapsedTimeInSeconds() const noexcept;
		uint64_t GetNowTimeInMicroseconds() const noexcept;
		uint64_t GetNowTimeInSeconds() const noexcept;

	private:
		IMPL_TYPE_DECLARE(DeltaTimeManager);
	};
}

#endif // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
