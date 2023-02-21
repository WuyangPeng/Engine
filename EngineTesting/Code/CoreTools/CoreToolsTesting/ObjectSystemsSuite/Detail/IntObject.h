///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 14:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/NullObject.h"

// int值对象，这个类用于演示Object使用int值和int值的数组。
namespace CoreTools
{
    class IntObject : public NullObject
    {
    public:
        using ClassType = IntObject;
        using ParentType = NullObject;

    public:
        explicit IntObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IntObject);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void AllocationArray0(int value);
        void AllocationArray1(int value);
        NODISCARD bool IsLoadValidity() const;

    private:
        static constexpr auto bufferSize = 5;

        int intValue;
        std::vector<int> intArray0;
        std::vector<int> intArray1;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(IntObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IntObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H
