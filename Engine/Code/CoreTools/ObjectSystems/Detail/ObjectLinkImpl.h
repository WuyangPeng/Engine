///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:24)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ObjectLinkImpl final
    {
    public:
        using ClassType = ObjectLinkImpl;
        using LinkSequentialContainer = std::vector<ObjectInterfaceSharedPtr>;
        using LinkSequentialContainerIter = LinkSequentialContainer::iterator;
        using LinkSequentialContainerConstIter = LinkSequentialContainer::const_iterator;

    public:
        ObjectLinkImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr GetObjectInterface(uint64_t uniqueID);
        NODISCARD int GetOrderedSize() const;

        void Insert(int64_t uniqueId, const ObjectInterfaceSharedPtr& object);

        void Sort();

        NODISCARD LinkSequentialContainerConstIter begin() const noexcept;
        NODISCARD LinkSequentialContainerConstIter end() const noexcept;
        NODISCARD LinkSequentialContainerIter begin() noexcept;
        NODISCARD LinkSequentialContainerIter end() noexcept;

    private:
        using LinkAssociatedContainer = std::map<int64_t, ObjectInterfaceSharedPtr>;

    private:
        // �洢ͼ�μ��ع����еĶ������
        LinkAssociatedContainer linked;
        LinkSequentialContainer ordered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
