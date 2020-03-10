// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:20)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
	template<typename Value, typename ConstReference>
	class SimplePropertyGetExternal
	{
	public:
		static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
		static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

		using ValueType = Value;
		using ConstReferenceType = ConstReference;
		using ClassType = SimplePropertyGetExternal<ValueType, ConstReferenceType>;

	public:
		explicit SimplePropertyGetExternal(const ValueType& value);

		CLASS_INVARIANT_DECLARE;

		operator ConstReferenceType () const noexcept;

		SimplePropertyGetExternal& operator=(const SimplePropertyGetExternal& rhs) = delete;

	private:
		const ValueType& m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_H