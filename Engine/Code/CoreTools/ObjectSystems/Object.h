///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/07 0:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectName.h"
#include "CoreTools/Helper/NameMacro.h"

#include <string>
#include <vector>

namespace CoreTools
{
    // 根类对象系统的根类。
    // 它提供了一个面向对象库的一些基本服务，这是一个抽象类。
    class CORE_TOOLS_DEFAULT_DECLARE Object : public ObjectInterface
    {
    public:
        using ClassType = Object;
        using ParentType = ObjectInterface;
        CORE_TOOLS_SHARED_PTR_DECLARE(Object);

    public:
        explicit Object(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
        CORE_TOOLS_NAMES_DECLARE;

    public:
        // 对象名字
        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD virtual bool IsNullObject() const noexcept;

        NODISCARD static const ObjectSharedPtr& GetNullObject();

    private:
        NODISCARD ObjectSharedPtr ObjectSharedFromThis();
        NODISCARD ConstObjectSharedPtr ObjectSharedFromThis() const;

    private:
        ObjectName objectName;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Object);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Object);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
