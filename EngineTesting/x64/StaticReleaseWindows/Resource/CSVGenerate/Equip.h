/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
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

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Equip(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetNextId() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD String GetEquipName() const override;

        NODISCARD System::TChar GetLogo() const noexcept override;

        NODISCARD CoreTools::Vector3 GetPosition() const noexcept override;

        NODISCARD BoolContainer GetMask() const override;
        NODISCARD int GetMaskCount() const override;
        NODISCARD bool GetMask(int index) const override;
        NODISCARD BoolContainerConstIter GetMaskBegin() const noexcept override;
        NODISCARD BoolContainerConstIter GetMaskEnd() const noexcept override;

        NODISCARD int GetHeroId() const noexcept override;
        NODISCARD ConstHeroSharedPtr GetHeroId(const CSVConfigureContainer& csvContainer) const override;

    private:
        int id;  // Id
        int nextId;  // ��һ��ID
        int reward;  // ���ؽ���
        String equipName;  // װ������
        System::TChar logo;  // ��ʶ
        CoreTools::Vector3 position;  // λ��
        BoolContainer mask;  // ����
        int heroId;  // Ӣ��Id
    };
}

#endif  // C_S_V_CONFIGURE_EQUIP_H
