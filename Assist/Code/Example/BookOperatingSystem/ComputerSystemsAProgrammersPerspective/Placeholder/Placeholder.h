///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/06 21:23)

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_PLACEHOLDER_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_PLACEHOLDER_H

#include "Example/BookOperatingSystem/ComputerSystemsAProgrammersPerspective/ComputerSystemsAProgrammersPerspectiveDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ComputerSystemsAProgrammersPerspective
{
    class COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_PLACEHOLDER_H
