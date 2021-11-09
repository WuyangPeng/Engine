///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:15)

#ifndef ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_H
#define ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_H

#include "Example/BookOperatingSystem/AdvancedCorbaProgrammingWithCpp/AdvancedCorbaProgrammingWithCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AdvancedCorbaProgrammingWithCpp
{
    class ADVANCED_CORBA_PROGRAMMING_WITH_CPP_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ADVANCED_CORBA_PROGRAMMING_WITH_CPP_PLACEHOLDER_H
