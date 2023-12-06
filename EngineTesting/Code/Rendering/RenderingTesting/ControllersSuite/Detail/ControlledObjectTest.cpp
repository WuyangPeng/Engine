///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:04)

#include "ControlledObjectTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ControlledObjectTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControlledObjectTest);

Rendering::ControlledObjectTest::ControlledObjectTestSharedPtr Rendering::ControlledObjectTest::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, Constructor::Default);
}

Rendering::ControlledObjectTest::ControlledObjectTest(const std::string& name, Constructor constructor)
    : ParentType{ name }
{
    System::UnusedFunction(constructor);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControlledObjectTest)

Rendering::ControlledObjectTest::ControllerSharedPtr Rendering::ControlledObjectTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ControlledObjectTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}
