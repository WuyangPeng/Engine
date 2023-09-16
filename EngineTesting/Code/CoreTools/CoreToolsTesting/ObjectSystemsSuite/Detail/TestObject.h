///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.6 (2023/04/18 16:01)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class TestObject final : public Object
    {
    public:
        using ClassType = TestObject;
        using ParentType = Object;
        using TestObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static TestObjectSharedPtr Create();

        explicit TestObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TestObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TestObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TestObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H