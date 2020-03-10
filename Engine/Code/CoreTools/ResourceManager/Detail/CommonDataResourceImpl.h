// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:05)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_IMPL_H
#define CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CommonDataResourceImpl
	{
	public:
		using ClassType = CommonDataResourceImpl;

	public:
		explicit CommonDataResourceImpl(uint32_t size);

		CLASS_INVARIANT_DECLARE;

		uint32_t GetSize() const noexcept;
		bool IsDisposed() const noexcept;

		void Recreate();
		void Dispose() noexcept;

		void SetData(int index, uint8_t value);
		uint8_t GetData(int index) const;

	private:
		using DataType = std::vector<uint8_t>;

	private:
		uint32_t m_DataSize;
		DataType m_Data;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_COMMON_DATA_RESOURCE_IMPL_H