/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 18:16)

#include "ControllerTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ControllerTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControllerTest);

Rendering::ControllerTest::ControllerTest(const std::string& name, Constructor constructor)
    : ParentType{ name }
{
    System::UnusedFunction(constructor);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControllerTest::ControllerTestSharedPtr Rendering::ControllerTest::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, Constructor::Default);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerTest)

Rendering::ControllerInterfaceSharedPtr Rendering::ControllerTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ControllerTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}
