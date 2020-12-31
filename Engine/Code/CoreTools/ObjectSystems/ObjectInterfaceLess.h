//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 10:05)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectInterfaceSmartPointerLess final
    {
    public:
        using ClassType = ObjectInterfaceSmartPointerLess;

    public:
        [[nodiscard]] bool operator()(const ConstObjectInterfaceSharedPtr& lhs, const ConstObjectInterfaceSharedPtr& rhs) noexcept;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_LESS_H
