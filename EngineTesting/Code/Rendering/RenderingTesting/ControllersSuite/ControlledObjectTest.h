///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 19:54)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H

#include "Rendering/Controllers/ControlledObject.h"

namespace Rendering
{
    class ControlledObjectTest : public ControlledObject
    {
    public:
        using ClassType = ControlledObjectTest;
        using ParentType = ControlledObject;

    public:
        explicit ControlledObjectTest(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControlledObjectTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ControlledObjectTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H