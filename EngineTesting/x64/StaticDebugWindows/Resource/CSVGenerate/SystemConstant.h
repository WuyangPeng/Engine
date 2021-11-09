/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SYSTEM_CONSTANT_H
#define C_S_V_CONFIGURE_SYSTEM_CONSTANT_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"

namespace CSVConfigure
{
    class SystemConstant final
    {
    public:
        using ClassType = SystemConstant;

    public:
        explicit SystemConstant(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetID() const noexcept;

        NODISCARD int GetNextID() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD System::String GetSkillName() const;

        NODISCARD VectorType GetVectorType() const noexcept;

        NODISCARD CoreTools::IntVector3 GetPosition() const noexcept;

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String skillName;  // ��������
        VectorType vectorType;  // ��������
        CoreTools::IntVector3 position;  // λ��
    };
}

#endif  // C_S_V_CONFIGURE_SYSTEM_CONSTANT_H
