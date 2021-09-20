///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 16:33)

#ifndef CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H
#define CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class AbstractObject : public Object
    {
    public:
        using ClassType = AbstractObject;
        using ParentType = Object;

    public:
        explicit AbstractObject(const std::string& name);
        virtual ~AbstractObject() = 0;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        AbstractObject(const AbstractObject& rhs) = default;
        virtual AbstractObject& operator=(const AbstractObject& rhs) = default;
        AbstractObject(AbstractObject&& rhs) noexcept = default;
        virtual AbstractObject& operator=(AbstractObject&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(AbstractObject);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(AbstractObject);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(AbstractObject);
    CORE_TOOLS_WEAK_PTR_DECLARE(AbstractObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_ABSTRACT_OBJECT_H