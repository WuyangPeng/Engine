// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 11:00)

#ifndef CORE_TOOLS_HELPER_SUBCLASS_SMART_PIINTER_MACRO_H
#define CORE_TOOLS_HELPER_SUBCLASS_SMART_PIINTER_MACRO_H

#include "CoreTools/MemoryTools/SubclassSmartPointer.h"

#define CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(sequence,className) \
	    using SYSTEM_CONCATENATOR(className,SmartPointer) = std::shared_ptr<className>; \
		using SYSTEM_MULTIPLE_CONCATENATOR(Const,className,SmartPointer) = std::shared_ptr<const className>;

#define CORE_TOOLS_SHARED_PTR_DECLARE(className) \
	    using SYSTEM_CONCATENATOR(className,SharedPtr) = std::shared_ptr<className>; \
		using SYSTEM_MULTIPLE_CONCATENATOR(Const,className,SharedPtr) = std::shared_ptr<const className>;

#endif // CORE_TOOLS_HELPER_SUBCLASS_SMART_PIINTER_MACRO_H
