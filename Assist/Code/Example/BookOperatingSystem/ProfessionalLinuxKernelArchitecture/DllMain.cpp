///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/21 20:53)

#include "Example/BookOperatingSystem/ProfessionalLinuxKernelArchitecture/ProfessionalLinuxKernelArchitectureExport.h"

#include "ProfessionalLinuxKernelArchitectureFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

DLL_MAIN_FUNCTION(ProfessionalLinuxKernelArchitecture);

#else  // !BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

CORE_TOOLS_MUTEX_INIT(ProfessionalLinuxKernelArchitecture);

#endif  // BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC
