///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:58)

#ifndef BEGINNING_LINUX_PROGRAMMING_PLACEHOLDER_H
#define BEGINNING_LINUX_PROGRAMMING_PLACEHOLDER_H

#include "Example/BookOperatingSystem/BeginningLinuxProgramming/BeginningLinuxProgrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BeginningLinuxProgramming
{
    class BEGINNING_LINUX_PROGRAMMING_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BEGINNING_LINUX_PROGRAMMING_PLACEHOLDER_H
