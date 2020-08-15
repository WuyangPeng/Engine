// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_SCOPED_MUTEX_H
#define CORE_TOOLS_THREADING_SCOPED_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadingFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{ 
	class CORE_TOOLS_DEFAULT_DECLARE ScopedMutex : private boost::noncopyable
	{
	public:
		using ClassType = ScopedMutex;
		using MasterType = DllMutex;

	public:
		explicit ScopedMutex(MasterType& mutex);
		~ScopedMutex();
		ScopedMutex(const ScopedMutex&) = delete;
		ScopedMutex operator=(const ScopedMutex&) = delete;
		ScopedMutex(ScopedMutex&&) noexcept = delete;
		ScopedMutex operator=(ScopedMutex&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		MasterType& m_Mutex;
	};
}

#endif // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
