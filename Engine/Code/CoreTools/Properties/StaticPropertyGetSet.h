// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:21)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<typename Value, typename GetReference, typename SetReference, typename Container,
			 GetReference(*FG)(void), void(*FS)(SetReference)>
	class StaticPropertyGetSet
	{
	public:
		using ValueType = Value;
		using GetReferenceType = GetReference;
		using SetReferenceType = SetReference;
		using ContainerType = Container;
		using ClassType = StaticPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FG, FS>;

	public:
		StaticPropertyGetSet();
		explicit StaticPropertyGetSet(SetReferenceType value);

		CLASS_INVARIANT_DECLARE;

	public:
		operator GetReferenceType() const;
		ClassType& operator =(SetReferenceType value);

	private:
		ValueType m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H