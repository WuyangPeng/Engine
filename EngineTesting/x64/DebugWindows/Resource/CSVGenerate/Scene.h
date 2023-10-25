/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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
        int nextId;  // 下一级Id
        int reward;  // 过关奖励
        String sceneName;  // 场景名称
        double length;  // 场景长度
        CoreTools::IntVector2 position;  // 位置
    };
}

#endif  // C_S_V_CONFIGURE_SCENE_H
