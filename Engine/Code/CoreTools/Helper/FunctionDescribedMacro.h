// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 09:36)

#ifndef CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H
#define CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H

#include "CoreTools/ClassInvariant/FunctionDescribed.h"

#define CORE_TOOLS_FUNCTION_DESCRIBED \
	    CoreTools::FunctionDescribed{ __func__,__FILE__, __LINE__ }

#endif // CORE_TOOLS_HELPER_FUNCTION_DESCRIBED_MACRO_H