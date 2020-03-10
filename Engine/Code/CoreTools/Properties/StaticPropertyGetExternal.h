// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:21)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
	template<typename ConstReference, ConstReference(*PF)()>
	class StaticPropertyGetExternal
	{
	public:
		static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
		static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

		using ConstReferenceType = ConstReference;
		using ClassType = StaticPropertyGetExternal<ConstReferenceType, PF>;

	public:
		CLASS_INVARIANT_DECLARE;

		operator ConstReferenceType () const;

		StaticPropertyGetExternal& operator=(const StaticPropertyGetExternal& rhs) = delete;
	};
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H