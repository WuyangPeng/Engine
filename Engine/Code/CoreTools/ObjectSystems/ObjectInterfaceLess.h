// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ObjectInterfaceSmartPointerLess
	{
	public:
		using ClassType = ObjectInterfaceSmartPointerLess;

	public:
                bool operator()(const ConstObjectInterfaceSmartPointer& lhs, const ConstObjectInterfaceSmartPointer& rhs) noexcept;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H
