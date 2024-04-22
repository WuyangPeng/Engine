/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:14)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H
#define CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "InitTerm.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE InitTermRegisterFactory final
    {
    public:
        using ClassType = InitTermRegisterFactory;

        using Factory = void (*)();

    public:
        InitTermRegisterFactory(Factory initializer, Factory terminate);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H
