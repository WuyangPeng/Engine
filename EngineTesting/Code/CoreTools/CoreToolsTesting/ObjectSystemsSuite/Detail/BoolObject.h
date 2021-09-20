// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 13:26)

// bool值对象，这个类用于演示Object使用bool值和bool值的数组。
#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "NullObject.h"

namespace CoreTools
{
    class BoolObject : public NullObject
    {
    public:
        using ClassType = BoolObject;
        using ParentType = NullObject;

    public:
        BoolObject();
        virtual ~BoolObject();

        BoolObject(const BoolObject& rhs);
        BoolObject& operator=(const BoolObject& rhs);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BoolObject);

        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void AllocationFirstArray(bool value) noexcept;
        void AllocationSecondArray(bool value);
        void Release();
        void Swap(BoolObject& rhs);
        bool IsLoadValidity() const;

    private:
        static constexpr auto sm_BufferSize = 5;

        bool m_BoolValue;
        bool* m_BoolArray1;
        bool* m_BoolArray2;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(BoolObject);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(BoolObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
