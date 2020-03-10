// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_H

#include "SubclassSmartPointerTraits.h"
#include "SecondSubclassSmartPointer.h"
#include "ConstThirdSubclassSmartPointer.h"
#include "CoreTools/Helper/ThirdSubclassSmartPointerMacro.h"

#include <type_traits>	 

SUBCLASS_SMART_POINTER_STATEMENT(Third, Second)
SUBCLASS_SMART_POINTER_STATEMENT(Fourth, Third)
SUBCLASS_SMART_POINTER_STATEMENT(Fifth, Fourth)
SUBCLASS_SMART_POINTER_STATEMENT(Sixth, Fifth)
SUBCLASS_SMART_POINTER_STATEMENT(Seventh, Sixth)
SUBCLASS_SMART_POINTER_STATEMENT(Eighth, Seventh)
SUBCLASS_SMART_POINTER_STATEMENT(Ninth, Eighth)
SUBCLASS_SMART_POINTER_STATEMENT(Tenth, Ninth)

#endif // CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_H
