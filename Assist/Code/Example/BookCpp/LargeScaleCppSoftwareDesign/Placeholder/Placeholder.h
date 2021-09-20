///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:53)

#ifndef LARGE_SCALE_CPP_SOFTWARE_DESIGN_PLACEHOLDER_PLACEHOLDER_H
#define LARGE_SCALE_CPP_SOFTWARE_DESIGN_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/LargeScaleCppSoftwareDesign/LargeScaleCppSoftwareDesignDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace LargeScaleCppSoftwareDesign
{
    class LARGE_SCALE_CPP_SOFTWARE_DESIGN_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // LARGE_SCALE_CPP_SOFTWARE_DESIGN_PLACEHOLDER_PLACEHOLDER_H
