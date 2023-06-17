/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_EQUIP_BASE_H
#define C_S_V_CONFIGURE_EQUIP_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/Vector3.h"

#include <deque>
#include <memory>

namespace CSVConfigure
{
    class EquipBase
    {
    public:
        using ClassType = EquipBase;

    public:
        EquipBase() noexcept = default;
        explicit EquipBase(int key) noexcept;

        virtual ~EquipBase() noexcept = default;
        EquipBase(const EquipBase& rhs) noexcept = default;
        EquipBase& operator=(const EquipBase& rhs) noexcept = default;
        EquipBase(EquipBase&& rhs) noexcept = default;
        EquipBase& operator=(EquipBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetNextId() const noexcept;

        NODISCARD virtual int GetReward() const noexcept;

        NODISCARD virtual System::String GetEquipName() const;

        NODISCARD virtual System::TChar GetLogo() const noexcept;

        NODISCARD virtual CoreTools::Vector3 GetPosition() const noexcept;

        NODISCARD virtual std::deque<bool> GetMask() const;
        NODISCARD virtual int GetMaskCount() const;
        NODISCARD virtual bool GetMask(int index) const;
        NODISCARD virtual std::deque<bool>::const_iterator GetMaskBegin() const;
        NODISCARD virtual std::deque<bool>::const_iterator GetMaskEnd() const;

        NODISCARD virtual int GetHeroId() const noexcept;
        NODISCARD virtual std::shared_ptr<const HeroMappingType> GetHeroId(const CSVConfigureContainer& csvContainer) const;

    private:
        int key{};
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_BASE_H
