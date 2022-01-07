///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 16:06)

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
        NODISCARD static InitTermContainer& GetInitializer() noexcept;
        NODISCARD static InitTermContainer& GetTerminator() noexcept;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
