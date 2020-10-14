// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE MemoryInformation
	{
	public:
		using ClassType = MemoryInformation;

	public:
		MemoryInformation(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed);

		CLASS_INVARIANT_DECLARE;

		size_t GetBytesNumber() const noexcept;
		int GetDimensionsNumber() const noexcept;
		const FunctionDescribed& GetFunctionDescribed() const noexcept;
		uint64_t GetUniqueID() const noexcept;

	private:
		size_t m_BytesNumber;
		int m_DimensionsNumber;
		FunctionDescribed m_FunctionDescribed;
		uint64_t m_UniqueID;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_MEMORY_INFORMATION_H
