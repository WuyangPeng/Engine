// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_H
#define CORE_TOOLS_THREADING_SEMAPHORE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(SemaphoreImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Semaphore : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Semaphore);

	public:
		Semaphore(int initialCount, int maximumCount);

		CLASS_INVARIANT_DECLARE;

		void Release(int releaseCount);
		void Wait();

		int GetCurrentCount() const noexcept;
		int GetMaximumCount() const noexcept;

	private:
		IMPL_TYPE_DECLARE(Semaphore);
	};
}

#endif // CORE_TOOLS_THREADING_SEMAPHORE_H
