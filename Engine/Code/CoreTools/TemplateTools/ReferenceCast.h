// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:39)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H  

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template <typename T>
	class ReferenceCast
	{
	public:
		using ClassType = ReferenceCast<T>;

	public:
		explicit ReferenceCast(T& value) noexcept;

		CLASS_INVARIANT_DECLARE;

		operator T&() const noexcept;

	private:
		T& m_Value;

		ReferenceCast& operator=(const ReferenceCast&) = delete;
	};

	template <>
	class ReferenceCast<int>
	{
	public:
		using ClassType = ReferenceCast<int>;

	public:
		explicit ReferenceCast(int value) noexcept;

		CLASS_INVARIANT_DECLARE;

		operator int() const noexcept;

	private:
		int m_Value;
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H

