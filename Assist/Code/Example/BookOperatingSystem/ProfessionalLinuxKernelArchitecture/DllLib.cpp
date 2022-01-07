///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:53)

#include "Example/BookOperatingSystem/ProfessionalLinuxKernelArchitecture/ProfessionalLinuxKernelArchitectureExport.h"

#include "ProfessionalLinuxKernelArchitecture.h"

#ifndef BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

namespace ProfessionalLinuxKernelArchitecture
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC
