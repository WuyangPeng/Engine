/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:15)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE NullObject : public Object
    {
    public:
        using ClassType = NullObject;
        using ParentType = Object;

    public:
        explicit NullObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(NullObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool IsNullObject() const noexcept override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(NullObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(NullObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_NULL_OBJECT_H
