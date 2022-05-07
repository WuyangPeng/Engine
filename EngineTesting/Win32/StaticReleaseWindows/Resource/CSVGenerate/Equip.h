/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

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

        NODISCARD int GetID() const noexcept override;

        NODISCARD int GetNextID() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD System::String GetEquipName() const override;

        NODISCARD System::TChar GetLogo() const noexcept override;

        NODISCARD CoreTools::Vector3 GetPosition() const noexcept override;

        NODISCARD std::deque<bool> GetMask() const override;
        NODISCARD int GetMaskCount() const override;
        NODISCARD bool GetMask(int index) const override;
        NODISCARD std::deque<bool>::const_iterator GetMaskBegin() const noexcept override;
        NODISCARD std::deque<bool>::const_iterator GetMaskEnd() const noexcept override;

        NODISCARD int GetHeroID() const noexcept override;
        NODISCARD std::shared_ptr<const Hero> GetHeroID(const CSVConfigureContainer& csvContainer) const override;

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String equipName;  // װ������
        System::TChar logo;  // ��ʶ
        CoreTools::Vector3 position;  // λ��
        std::deque<bool> mask;  // ����
        int heroID;  // Ӣ��ID
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_H