///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:11)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    // �����û����ȷ�İ�����
    // CORE_TOOLS_REGISTER_STREAM(ErrorObject);

    class ErrorObject final : public Object
    {
    public:
        using ClassType = ErrorObject;
        using ParentType = Object;

    public:
        explicit ErrorObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ErrorObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H
