//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 20:59)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTerm final
    {
    public:
        using ClassType = InitTerm;
        using Initializer = void (*)();
        using Terminator = void (*)();

    public:
        static void AddInitializer(Initializer function);
        static void ExecuteInitializers();
        static void AddTerminator(Terminator function);
        static void ExecuteTerminators();

    private:
        [[nodiscard]] static InitTermContainer& GetInitializer() noexcept;
        [[nodiscard]] static InitTermContainer& GetTerminator() noexcept;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
