///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 17:19)

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
        InitTermRegisterFactory(Factory initializa, Factory terminate);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_REGISTER_FACTORY_H
