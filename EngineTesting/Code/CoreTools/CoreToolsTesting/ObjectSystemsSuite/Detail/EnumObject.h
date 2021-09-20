// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 13:26)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumObjectEnum.h"
#include "NullObject.h"

// enum值对象，这个类用于演示Object使用enum值和enum值的数组。
namespace CoreTools
{
    class EnumObject : public NullObject
    {
    public:
        using ClassType = EnumObject;
        using ParentType = NullObject;

    public:
        EnumObject();
        virtual ~EnumObject();

        EnumObject(const EnumObject& rhs);
        EnumObject& operator=(const EnumObject& rhs);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(EnumObject);

        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void AllocationFirstArray(EnumObjectEnum value);
        void AllocationSecondArray(EnumObjectEnum value);
        void Release();
        void Swap(EnumObject& rhs);
        bool IsLoadValidity() const;

    private:
        static constexpr auto sm_BufferSize = 5;

        EnumObjectEnum m_EnumValue;
        EnumObjectEnum* m_EnumArray1;
        EnumObjectEnum* m_EnumArray2;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(EnumObject);
    #include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(EnumObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H
