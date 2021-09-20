//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/21 10:21)

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

        [[nodiscard]] ObjectInterfaceSharedPtr GetObjectInterface(uint64_t uniqueID);
        [[nodiscard]] int GetOrderedSize() const;

        void Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& object);

        void Sort();

        [[nodiscard]] LinkSequentialContainerConstIter begin() const noexcept;
        [[nodiscard]] LinkSequentialContainerConstIter end() const noexcept;
        [[nodiscard]] LinkSequentialContainerIter begin() noexcept;
        [[nodiscard]] LinkSequentialContainerIter end() noexcept;

    private:
        using LinkAssociatedContainer = std::map<uint64_t, ObjectInterfaceSharedPtr>;

    private:
        // �洢ͼ�μ��ع����еĶ������
        LinkAssociatedContainer m_Linked;
        LinkSequentialContainer m_Ordered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
