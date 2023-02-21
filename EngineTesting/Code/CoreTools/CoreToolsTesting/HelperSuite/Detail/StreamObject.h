///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/15 21:17)

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

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const final;

        NODISCARD bool GetBoolValue() const noexcept;

    private:
        bool boolValue;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StreamObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StreamObject);
}

#endif  // CORE_TOOLS_HELPER_SUITE_STREAM_OBJECT_H
