/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:29)

#ifndef CORE_TOOLS_HELPER_SUITE_STREAM_OBJECT_H
#define CORE_TOOLS_HELPER_SUITE_STREAM_OBJECT_H

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
        StreamObject(const std::string& name, LoadConstructor loadConstructor);

        NODISCARD static StreamObjectSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_FINAL_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StreamObject);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool GetBoolValue() const noexcept;

    private:
        bool boolValue;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StreamObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StreamObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_STREAM_OBJECT_H
