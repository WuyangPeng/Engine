// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:21)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
	template<typename Reference, void(*PF)(Reference)>
	class StaticPropertySetExternal
	{
	public:
		static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

		using ReferenceType = Reference;
		using ClassType = StaticPropertySetExternal<ReferenceType, PF>;

	public:
		CLASS_INVARIANT_DECLARE;

		StaticPropertySetExternal& operator =(ReferenceType value);
	};
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H