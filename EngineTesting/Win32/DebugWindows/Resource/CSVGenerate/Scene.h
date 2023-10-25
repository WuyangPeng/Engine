/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
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

        using CSVRow = CoreTools::CSVRow;
        using String = System::String;

    public:
        explicit Scene(const CSVRow& csvRow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey() const noexcept;

        NODISCARD int GetId() const noexcept;

        NODISCARD int GetNextId() const noexcept;

        NODISCARD int GetReward() const noexcept;

        NODISCARD String GetSceneName() const;

        NODISCARD double GetLength() const noexcept;

        NODISCARD CoreTools::IntVector2 GetPosition() const noexcept;

    private:
        int id;  // Id
        int nextId;  // ��һ��Id
        int reward;  // ���ؽ���
        String sceneName;  // ��������
        double length;  // ��������
        CoreTools::IntVector2 position;  // λ��
    };
}

#endif  // C_S_V_CONFIGURE_SCENE_H
