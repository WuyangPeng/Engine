// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONST_THIRD_SUBCLASS_SMART_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONST_THIRD_SUBCLASS_SMART_POINTER_H

#include "SubclassSmartPointerTraits.h"
#include "ConstSecondSubclassSmartPointer.h"
#include "CoreTools/Helper/ThirdSubclassSmartPointerMacro.h"

#include <type_traits>

CONST_SUBCLASS_SMART_POINTER_STATEMENT(Third, Second)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Fourth, Third)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Fifth, Fourth)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Sixth, Fifth)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Seventh, Sixth)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Eighth, Seventh)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Ninth, Eighth)
CONST_SUBCLASS_SMART_POINTER_STATEMENT(Tenth, Ninth)

#endif // CORE_TOOLS_MEMORY_TOOLS_CONST_THIRD_SUBCLASS_SMART_POINTER_H
