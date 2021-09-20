///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:54)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_OBJECT_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class StreamObject final : public Object
    {
    public:
        using ClassType = StreamObject;
        using ParentType = Object;
        using StreamObjectSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit StreamObject(const std::string& name);

        NODISCARD static StreamObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_FINAL_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StreamObject);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const final;

        NODISCARD bool GetBoolValue() const noexcept;

    private:
        bool boolValue;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(StreamObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StreamObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_OBJECT_H
