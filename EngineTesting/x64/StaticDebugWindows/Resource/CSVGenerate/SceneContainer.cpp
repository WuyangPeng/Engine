/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "Scene.h"
#include "SceneContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

using std::make_shared;

CSVConfigure::SceneContainer::SceneContainer(const CoreTools::CSVContent& csvContent)
    : scene{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SceneContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        auto sceneBase = make_shared<Scene>(csvRow);

        if (!scene.emplace(sceneBase->GetKey(), sceneBase).second)
        {

            LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
                << SYSTEM_TEXT("scene表存在重复主键：")
                << sceneBase->GetKey()
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SceneContainer)

CSVConfigure::SceneContainer::ConstSceneSharedPtr CSVConfigure::SceneContainer::GetFirstScene() const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (scene.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene表为空。"s));
    }
    else
    {
        return scene.begin()->second;
    }
}

CSVConfigure::SceneContainer::ConstSceneSharedPtr CSVConfigure::SceneContainer::GetScene(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = scene.find(key);

    if (iter != scene.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s));
    }
}

CSVConfigure::SceneContainer::MappingContainer CSVConfigure::SceneContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scene;
}

