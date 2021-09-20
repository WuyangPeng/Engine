///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/LinearAlgebraAndItsApplications/LinearAlgebraAndItsApplicationsExport.h"

#include "LinearAlgebraAndItsApplications.h"

#ifndef BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC

    #include "DllLib.h"

#else  // BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC

namespace LinearAlgebraAndItsApplications
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC
