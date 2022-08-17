///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 13:49)

// boolֵ���������������ʾObjectʹ��boolֵ��boolֵ�����顣
#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/NullObject.h"

namespace CoreTools
{
    class BoolObject : public NullObject
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(BoolObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BoolObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BOOL_OBJECT_H
