// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:20)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace CoreTools
{
	template<typename T, typename Reference, void (T::*PF)(Reference)>
	class PropertySetExternal : private boost::noncopyable
	{
	public:
		static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

		using ReferenceType = Reference;
		using ClassType = PropertySetExternal<T, ReferenceType, PF>;

	public:
		explicit PropertySetExternal(T& object);

		CLASS_INVARIANT_DECLARE;

		PropertySetExternal& operator =(ReferenceType value);

	private:
		T& m_Object;
	};
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H