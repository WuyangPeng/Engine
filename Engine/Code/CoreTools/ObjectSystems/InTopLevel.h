//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 9:49)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "ObjectInterface.h"
#include "ObjectType.h"

CORE_TOOLS_EXPORT_SHARED_PTR(InTopLevelImpl);

namespace CoreTools
{
    // �����صĶ������
    class CORE_TOOLS_DEFAULT_DECLARE InTopLevel final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(InTopLevel);

    public:
        explicit InTopLevel(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsTopLevel(const ObjectInterfaceSharedPtr& object) const;
        [[nodiscard]] int GetTopLevelSize() const;

        [[nodiscard]] ObjectContainerConstIter begin() const noexcept;
        [[nodiscard]] ObjectContainerConstIter end() const noexcept;

        [[nodiscard]] ObjectContainerIter begin();
        [[nodiscard]] ObjectContainerIter end();

        // �Զ���Ķ�����б��档
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        IMPL_TYPE_DECLARE(OutTopLevel);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H
