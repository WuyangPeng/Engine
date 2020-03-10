// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:06)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_H
#define CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_H

#include "CoreTools/CoreToolsDll.h"

#include "Flags/ResourceManagerFlags.h"
#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/PragmaWarning/PosixTime.h"

CORE_TOOLS_EXPORT_SHARED_PTR(BaseResourceImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BaseResource
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(BaseResource);

	public:
		explicit BaseResource(PriorityType priority);
		virtual ~BaseResource();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		PriorityType GetPriority() const noexcept;
		boost::posix_time::ptime GetLastAccessTime() const;
		bool IsLocked() const noexcept;

		void SetPriority(PriorityType priority) noexcept;
		void SetCurrentTime();
		void Lock() noexcept;
		void Unlock() noexcept;

		virtual uint32_t GetSize() const = 0;
		virtual bool IsDisposed() const = 0;

		virtual void Recreate() = 0;
		virtual void Dispose() = 0;

		virtual void SetData(int32_t index, uint8_t value) = 0;
		virtual uint8_t GetData(int32_t index) const = 0;

	private:
		IMPL_TYPE_DECLARE(BaseResource);
	};

	bool operator < (const BaseResource& lhs, const BaseResource& rhs);
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_BASE_RESOURCE_H