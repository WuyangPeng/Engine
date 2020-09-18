//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/11 10:35)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTerm
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
