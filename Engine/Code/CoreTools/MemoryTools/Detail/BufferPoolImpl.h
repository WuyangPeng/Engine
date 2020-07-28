// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:39)

#ifndef CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/MemoryTools/Pool.h" 
#include "CoreTools/MemoryTools/MemoryToolsFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BufferPoolImpl : public Pool<Buffer>
	{
	public:
		using ClassType = BufferPoolImpl;
		using ParentType = Pool<Buffer>;

	public:
		BufferPoolImpl() noexcept;
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		Buffer* Get() override;

		void Release(Buffer* ptr) override;

		Buffer* GetBuffer(int minSize);

	private:
		bool ConformCondition(Buffer* ptr) noexcept override;
		Buffer* DoGet() override;

	private:
		int m_MinSize;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_BUFER_POOL_IMPL_H

