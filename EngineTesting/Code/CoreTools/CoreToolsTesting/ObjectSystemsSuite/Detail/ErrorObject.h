// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 13:27)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    // 这个类没有正确的包含：
    // CORE_TOOLS_REGISTER_STREAM(ErrorObject);

    class ErrorObject : public Object
    {
    public:
        using ClassType = ErrorObject;
        using ParentType = Object;

    public:
        ErrorObject();
        virtual ~ErrorObject();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ErrorObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        ObjectInterfaceSharedPtr CloneObject() const override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_ERROR_OBJECT_H
