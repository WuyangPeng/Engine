// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:40)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE FileBufferImpl
	{
	public:
		using ClassType = FileBufferImpl;

	public:
		explicit FileBufferImpl(size_t count);

		CLASS_INVARIANT_DECLARE;

		const char* GetBufferBegin() const noexcept;
		size_t GetSize() const noexcept;

		char* GetBufferBegin() noexcept;

	private:
		using BufferType = std::vector<char>;

	private:
		BufferType m_Buffer;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
