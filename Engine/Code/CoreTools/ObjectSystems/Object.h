//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 9:57)

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        ~Object() noexcept = 0;
        Object(const Object& rhs) = default;
        virtual Object& operator=(const Object& rhs) = default;
        Object(Object&& rhs) noexcept = default;
        virtual Object& operator=(Object&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
        CORE_TOOLS_NAMES_DECLARE;

    public:
        // ��������
        [[nodiscard]] std::string GetName() const;
        void SetName(const std::string& name);

    protected:
        virtual void Swap(Object& rhs) noexcept;

    private:
        ObjectSharedPtr ObjectSharedFromThis();
        ConstObjectSharedPtr ObjectSharedFromThis() const;

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
