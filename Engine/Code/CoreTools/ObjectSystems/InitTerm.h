/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:14)

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
        static void ExecuteInitializer();
        static void AddTerminator(Terminator function);
        static void ExecuteTerminator();

    private:
        NODISCARD static InitTermContainer& GetInitializer() noexcept;
        NODISCARD static InitTermContainer& GetTerminator() noexcept;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
