///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:11)

// bool值对象，这个类用于演示Object使用bool值和bool值的数组。
#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/NullObject.h"

namespace CoreTools
{
    class BoolObject final : public NullObject
    {
    public:
        using ClassType = BoolObject;
        using ParentType = NullObject;

    public:
        explicit BoolObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BoolObject);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void AllocationArray0(bool value);
        void AllocationArray1(bool value);

        NODISCARD bool IsLoadValidity() const;

    private:
        static constexpr auto bufferSize = 5;

        bool boolValue;
        std::vector<bool> boolArray0;
        std::vector<bool> boolArray1;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(BoolObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BoolObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
