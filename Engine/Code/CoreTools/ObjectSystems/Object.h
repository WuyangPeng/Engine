///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/07 0:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectName.h"
#include "CoreTools/Helper/NameMacro.h"

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

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
        CORE_TOOLS_NAMES_DECLARE;

    public:
        // ��������
        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD virtual bool IsNullObject() const noexcept;

        NODISCARD static const ObjectSharedPtr& GetNullObject();

    private:
        NODISCARD ObjectSharedPtr ObjectSharedFromThis();
        NODISCARD ConstObjectSharedPtr ObjectSharedFromThis() const;

    private:
        ObjectName objectName;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Object);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Object);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
