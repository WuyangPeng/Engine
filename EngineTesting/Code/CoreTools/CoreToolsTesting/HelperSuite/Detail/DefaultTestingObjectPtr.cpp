///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:37)

#include "DefaultTestingObjectPtr.h"
#include "TestingNoObjectPtrImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, DefaultTestingObjectPtr);

CORE_TOOLS_RTTI_DEFINE(CoreTools, DefaultTestingObjectPtr);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, DefaultTestingObjectPtr);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, DefaultTestingObjectPtr);

CoreTools::DefaultTestingObjectPtr::DefaultTestingObjectPtr(const std::string& name)
    : ParentType{ name }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::DefaultTestingObjectPtr::ObjectSharedPtr CoreTools::DefaultTestingObjectPtr::Create(const std::string& name)
{
    return std::make_shared<ClassType>(name);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingObjectPtr);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(CoreTools, DefaultTestingObjectPtr);

CoreTools::ObjectInterfaceSharedPtr CoreTools::DefaultTestingObjectPtr::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
