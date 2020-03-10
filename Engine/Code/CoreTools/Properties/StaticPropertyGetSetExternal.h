// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:21)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<typename GetReference, typename SetReference, GetReference(*FG)(void), void(*FS)(SetReference)>
	class StaticPropertyGetSetExternal
	{
	public:
		using GetReferenceType = GetReference;
		using SetReferenceType = SetReference;
		using ClassType = StaticPropertyGetSetExternal<GetReferenceType, SetReferenceType, FG, FS>;

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		operator GetReferenceType() const;
		ClassType& operator =(SetReferenceType value);
	};
}

#endif // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_H