///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/29 16:35)

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
