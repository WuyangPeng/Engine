//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 11:19)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>
#include "CoreTools/Contract/ImplStaticAssertHelper.h"

 
EXPORT_SHARED_PTR(CoreTools, ObjectNameImpl, CORE_TOOLS_DEFAULT_DECLARE);
namespace CoreTools
{
    // Object�������
    class CORE_TOOLS_DEFAULT_DECLARE ObjectName final
    {
    public:
    public:
        void Swap(ObjectName& rhs) noexcept;

    public:
        TYPE_DECLARE(ObjectName);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~ObjectName() noexcept = default;
        ObjectName(const ObjectName& rhs);
        ObjectName& operator=(const ObjectName& rhs);
        ObjectName(ObjectName&& rhs) noexcept;
        ObjectName& operator=(ObjectName&& rhs) noexcept;

    public:
        explicit ObjectName(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::string GetName() const;
        [[nodiscard]] bool IsExactly(const ObjectName& name) const noexcept;

        void SetName(const std::string& name);

        void SwapObjectName(ObjectName& name) noexcept;

    private:
        using ObjectNameImplPtr = std::shared_ptr<ImplType>;

    private:
        ObjectNameImplPtr impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
