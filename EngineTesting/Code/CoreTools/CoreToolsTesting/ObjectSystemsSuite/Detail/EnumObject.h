/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:48)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumObjectEnum.h"
#include "CoreTools/ObjectSystems/NullObject.h"

/// enum值对象，这个类用于演示Object使用enum值和enum值的数组。
namespace CoreTools
{
    class EnumObject final : public NullObject
    {
    public:
        using ClassType = EnumObject;
        using ParentType = NullObject;

    public:
        explicit EnumObject(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(EnumObject);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        static constexpr auto bufferSize = 5;

        using EnumArrayType = std::vector<EnumObjectEnum>;

    private:
        void AllocationArray0(EnumObjectEnum value);
        void AllocationArray1(EnumObjectEnum value);
        NODISCARD bool IsLoadValidity() const;

    private:
        EnumObjectEnum enumValue;
        EnumArrayType enumArray0;
        EnumArrayType enumArray1;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(EnumObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(EnumObject);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_ENUM_OBJECT_H
