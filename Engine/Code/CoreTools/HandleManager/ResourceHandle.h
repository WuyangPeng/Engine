// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:02)

#ifndef CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_H
#define CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/operators.hpp>
#include <iostream>

namespace CoreTools
{
	template <typename Tag>
	class ResourceHandle : private boost::equality_comparable<ResourceHandle<Tag>>
	{
	public:
		using ClassType = ResourceHandle<Tag>;
		using TagType = Tag;

	public:
		explicit ResourceHandle(uint32_t index);

		CLASS_INVARIANT_DECLARE;

		uint32_t GetIndex() const noexcept;
		uint32_t GetMagic() const noexcept;
		uint64_t GetHandle() const noexcept;

	private:
		static uint32_t GenerateMagic();

	private:
		static constexpr uint32_t sm_MaxBitsIndex{ 32 };
		static constexpr uint32_t sm_MaxBitsMagic{ 32 };
		static constexpr uint64_t sm_MaxIndex{ ((1ULL) << sm_MaxBitsIndex) - 1 };
		static constexpr uint64_t sm_MaxMagic{ ((1ULL) << sm_MaxBitsMagic) - 1 };

		static_assert(sm_MaxBitsIndex + sm_MaxBitsMagic <= 64, "sm_MaxBitsIndex + sm_MaxBitsMagic must be less equal 64.");

		uint32_t m_Index : sm_MaxBitsIndex;
		uint32_t m_Magic : sm_MaxBitsMagic;
	};

	template <typename T>
	bool operator ==(const ResourceHandle<T>& lhs, const ResourceHandle<T>& rhs) noexcept;

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const ResourceHandle<T>& resourceHandle);
}

#endif // CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_H

