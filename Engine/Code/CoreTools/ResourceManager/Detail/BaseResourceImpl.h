// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.1 (2019/06/28 14:03)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_IMPL_H
#define CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/ResourceManager/ResourceManagerFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BaseResourceImpl
	{
	public:
		using ClassType = BaseResourceImpl;

	public:
		explicit BaseResourceImpl(PriorityType priority);

		CLASS_INVARIANT_DECLARE;

		PriorityType GetPriority() const noexcept;
		boost::posix_time::ptime GetLastAccessTime() const;
		bool IsLocked() const noexcept;

		void SetPriority(PriorityType priority) noexcept;
		void SetCurrentTime();
		void Lock() noexcept;
		void Unlock() noexcept;

	private:
		PriorityType m_Priority;
		int m_ReferenceCount;
		boost::posix_time::ptime m_LastAccessTime;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_IMPL_H