///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 17:20)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectName.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <string>
#include <vector>

namespace CoreTools
{
    // �������ϵͳ�ĸ��ࡣ
    // ���ṩ��һ�����������һЩ������������һ�������ࡣ
    class CORE_TOOLS_DEFAULT_DECLARE Object : public ObjectInterface
    {
    public:
        using ClassType = Object;
        using ParentType = ObjectInterface;
        CORE_TOOLS_SHARED_PTR_DECLARE(Object);

    public:
        explicit Object(const std::string& name);

        ~Object() noexcept = 0;
        Object(const Object& rhs) = default;
        Object& operator=(const Object& rhs) = default;
        Object(Object&& rhs) noexcept = default;
        Object& operator=(Object&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
        CORE_TOOLS_NAMES_DECLARE;

    public:
        // ��������
        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

    private:
        NODISCARD ObjectSharedPtr ObjectSharedFromThis();
        NODISCARD ConstObjectSharedPtr ObjectSharedFromThis() const;

    private:
        ObjectName m_Name;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Object);

#include STSTEM_WARNING_POP

    using ObjectSharedPtr = Object::ObjectSharedPtr;
    using ConstObjectSharedPtr = Object::ConstObjectSharedPtr;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
