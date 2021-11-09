/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SCENE_H
#define C_S_V_CONFIGURE_SCENE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"

namespace CSVConfigure
{
    class Scene final
    {
    public:
        using ClassType = Scene;

    public:
        explicit Scene(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetID() const noexcept;

        NODISCARD int GetNextID() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD System::String GetSceneName() const;

        NODISCARD double GetLength() const noexcept;

        NODISCARD CoreTools::IntVector2 GetPosition() const noexcept;

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String sceneName;  // ��������
        double length;  // ��������
        CoreTools::IntVector2 position;  // λ��
    };
}

#endif  // C_S_V_CONFIGURE_SCENE_H
