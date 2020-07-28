// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:15)

#ifndef CORE_TOOLS_THREADING_TRY_SCOPED_MUTEX_H
#define CORE_TOOLS_THREADING_TRY_SCOPED_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadingFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE TryScopedMutex : private boost::noncopyable
	{
	public:
		using ClassType = TryScopedMutex;
		using MasterType = DllMutex;

	public:
		explicit TryScopedMutex(MasterType& mutex);
		~TryScopedMutex();

		TryScopedMutex(const TryScopedMutex&) = delete;
		TryScopedMutex& operator=(const TryScopedMutex&) = delete;
		TryScopedMutex(TryScopedMutex&&) noexcept = delete;
		TryScopedMutex& operator=(TryScopedMutex&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		bool IsSuccess() const noexcept;

	private:
		MasterType& m_Mutex;
		bool m_IsSuccess;
	};
}

#endif // CORE_TOOLS_THREADING_SCOPED_MUTEX_H
