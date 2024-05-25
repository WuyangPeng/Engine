/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:30)

#include "DefaultTestingNoObjectPtr.h"
#include "TestingNoObjectPtrImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, DefaultTestingNoObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, DefaultTestingNoObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CoreTools::DefaultTestingNoObjectPtr::DefaultTestingNoObjectPtr(const std::string& name, LoadConstructor loadConstructor)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(loadConstructor);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DefaultTestingNoObjectPtr::ObjectSharedPtr CoreTools::DefaultTestingNoObjectPtr::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name, LoadConstructor::ConstructorLoader);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingNoObjectPtr);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(CoreTools, DefaultTestingNoObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::DefaultTestingNoObjectPtr::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}