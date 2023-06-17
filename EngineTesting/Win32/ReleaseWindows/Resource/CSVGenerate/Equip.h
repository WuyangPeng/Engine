/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_EQUIP_H
#define C_S_V_CONFIGURE_EQUIP_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "EquipBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace CSVConfigure
{
    class Equip final : public EquipBase
    {
    public:
        using ClassType = Equip;
        using ParentType = EquipBase;

    public:
        explicit Equip(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetNextId() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD System::String GetEquipName() const override;

        NODISCARD System::TChar GetLogo() const noexcept override;

        NODISCARD CoreTools::Vector3 GetPosition() const noexcept override;

        NODISCARD std::deque<bool> GetMask() const override;
        NODISCARD int GetMaskCount() const override;
        NODISCARD bool GetMask(int index) const override;
        NODISCARD std::deque<bool>::const_iterator GetMaskBegin() const noexcept override;
        NODISCARD std::deque<bool>::const_iterator GetMaskEnd() const noexcept override;

        NODISCARD int GetHeroId() const noexcept override;
        NODISCARD std::shared_ptr<const HeroMappingType> GetHeroId(const CSVConfigureContainer& csvContainer) const override;

    private:
        int id;  // Id
        int nextId;  // 下一关ID
        int reward;  // 过关奖励
        System::String equipName;  // 装备名称
        System::TChar logo;  // 标识
        CoreTools::Vector3 position;  // 位置
        std::deque<bool> mask;  // 掩码
        int heroId;  // 英雄Id
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_H
