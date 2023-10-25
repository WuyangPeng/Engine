/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Scene.h"
#include "SceneContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::SceneContainer::SceneContainer(const CSVContent& csvContent)
    : scene{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SceneContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("scene表开始载入……"));

    Load(csvContent);

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("scene表结束载入……"));
}

void CSVConfigure::SceneContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        auto sceneBase = std::make_shared<Scene>(csvRow);

        if (!scene.emplace(sceneBase->GetKey(), sceneBase).second)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("scene表存在重复主键："), sceneBase->GetKey(), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }

}



CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SceneContainer)

CSVConfigure::SceneContainer::ConstSceneSharedPtr CSVConfigure::SceneContainer::GetFirstScene() const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (scene.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene表为空。"s))
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
        THROW_EXCEPTION(SYSTEM_TEXT("scene表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CSVConfigure::SceneContainer::MappingContainer CSVConfigure::SceneContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scene;
}

int CSVConfigure::SceneContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(scene.size());
}

