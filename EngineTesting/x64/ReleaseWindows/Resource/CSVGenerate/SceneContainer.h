/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_SCENE_CONTAINER_H
#define C_S_V_CONFIGURE_SCENE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <unordered_map>
#include <vector>

namespace CSVConfigure
{
    class SceneContainer final
    {
    public:
        using ClassType = SceneContainer;

        using ConstSceneSharedPtr = std::shared_ptr<const SceneMappingType>;
        using MappingContainer = std::unordered_map<int, ConstSceneSharedPtr>;
        using Container = std::vector<ConstSceneSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit SceneContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSceneSharedPtr GetFirstScene() const;
        NODISCARD ConstSceneSharedPtr GetScene(int key) const;
        NODISCARD MappingContainer GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstSceneSharedPtr GetFirstScene(Function function) const;

        template <typename Function>
        NODISCARD Container GetScene(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);

    private:
        MappingContainer scene;
    };
}

#endif  // C_S_V_CONFIGURE_SCENE_CONTAINER_H
