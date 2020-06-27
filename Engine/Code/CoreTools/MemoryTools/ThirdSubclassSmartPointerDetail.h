// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 11:57)

#ifndef CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_DETAIL_H

#include "ThirdSubclassSmartPointer.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <boost/type_traits/is_same.hpp>

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26434)   
SUBCLASS_SMART_POINTER_DEFINE(Third)
SUBCLASS_SMART_POINTER_DEFINE(Fourth)
SUBCLASS_SMART_POINTER_DEFINE(Fifth)
SUBCLASS_SMART_POINTER_DEFINE(Sixth)
SUBCLASS_SMART_POINTER_DEFINE(Seventh)
SUBCLASS_SMART_POINTER_DEFINE(Eighth)
SUBCLASS_SMART_POINTER_DEFINE(Ninth)
SUBCLASS_SMART_POINTER_DEFINE(Tenth)
#include STSTEM_WARNING_POP

#endif // CORE_TOOLS_MEMORY_TOOLS_THIRD_SUBCLASS_SMART_POINTER_DETAIL_H
