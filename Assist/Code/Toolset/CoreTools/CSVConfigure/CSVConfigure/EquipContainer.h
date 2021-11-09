/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

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
        using ConstEquipBaseSharedPtr = std::shared_ptr<const EquipBase>;
        using Container = std::vector<ConstEquipBaseSharedPtr>;

    public:
        explicit EquipContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstEquipBaseSharedPtr GetFirstEquip(int key) const;
        NODISCARD Container GetEquip(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstEquipBaseSharedPtr GetFirstEquip(Function function) const;

        template <typename Function>
        NODISCARD Container GetEquip(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container equip;
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_CONTAINER_H
