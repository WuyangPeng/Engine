///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/13 23:00)

#include "AbstractObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, AbstractObject);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(CoreTools, AbstractObject);

CoreTools::AbstractObject::AbstractObject(const std::string& name)
    : ParentType{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::AbstractObject::~AbstractObject() = default;

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AbstractObject);
