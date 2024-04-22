/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:48)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    /// 这个类没有正确的包含：
    /// CORE_TOOLS_REGISTER_STREAM(ErrorObject);

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
