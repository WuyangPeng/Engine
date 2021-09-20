// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 13:27)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "NullObject.h"

// intֵ���������������ʾObjectʹ��intֵ��intֵ�����顣
namespace CoreTools
{
    class IntObject : public NullObject
    {
    public:
        using ClassType = IntObject;
        using ParentType = NullObject;

    public:
        IntObject();
        virtual ~IntObject();

        IntObject(const IntObject& rhs);
        IntObject& operator=(const IntObject& rhs);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IntObject);
        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void AllocationFirstArray(int value);
        void AllocationSecondArray(int value);
        void Release();
        void Swap(IntObject& rhs);
        bool IsLoadValidity() const;

    private:
        static constexpr auto bufferSize = 5;

        int m_IntValue;
        int* m_IntArray1;
        int* m_IntArray2;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(IntObject);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(IntObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_INT_OBJECT_H
