// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_H

#include "CoreTools/CoreToolsDll.h"

#include "MemoryToolsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(BufferPoolImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BufferPool : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BufferPool);

	public:
		BufferPool();

		CLASS_INVARIANT_DECLARE;

		Buffer* Get();
		void Release(Buffer* ptr);
		Buffer* GetBuffer(int minSize);

		void FreeAll();

		int GetAvailableCount() const;
		int GetAllocatedCount() const noexcept;
		int GetTotalCount() const;

	private:
		IMPL_TYPE_DECLARE(BufferPool);
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_H

