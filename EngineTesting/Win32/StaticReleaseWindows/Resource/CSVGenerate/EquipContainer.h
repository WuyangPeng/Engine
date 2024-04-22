/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_EQUIP_CONTAINER_H
#define C_S_V_CONFIGURE_EQUIP_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CSVConfigure
{
    class EquipContainer final
    {
    public:
        using ClassType = EquipContainer;

        using ConstEquipSharedPtr = std::shared_ptr<const EquipMappingType>;
        using Container = std::vector<ConstEquipSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit EquipContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstEquipSharedPtr GetFirstEquip(int key) const;
        NODISCARD Container GetEquip(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstEquipSharedPtr GetFirstEquip(Function function) const;

        template <typename Function>
        NODISCARD Container GetEquip(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);

    private:
        Container equip;
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_CONTAINER_H