/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_HERO_H
#define C_S_V_CONFIGURE_HERO_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/Vector4.h"

#include <vector>

namespace CSVConfigure
{
    class Hero final
    {
    public:
        using ClassType = Hero;

    public:
        explicit Hero(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetID() const noexcept;

        NODISCARD int GetNextID() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD System::String GetHeroName() const;

        NODISCARD int64_t GetUniqueIdentifier() const noexcept;

        NODISCARD CoreTools::Vector4 GetPosition() const noexcept;

        NODISCARD std::vector<System::TChar> GetDescribe() const;
        NODISCARD int GetDescribeCount() const;
        NODISCARD bool GetDescribe(int index) const;
        NODISCARD std::vector<System::TChar>::const_iterator GetDescribeBegin() const noexcept;
        NODISCARD std::vector<System::TChar>::const_iterator GetDescribeEnd() const noexcept;

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String heroName;  // Ӣ������
        int64_t uniqueIdentifier;  // Ψһ��ʶ��
        CoreTools::Vector4 position;  // λ��
        std::vector<System::TChar> describe;  // ����
    };
}

#endif  // C_S_V_CONFIGURE_HERO_H
