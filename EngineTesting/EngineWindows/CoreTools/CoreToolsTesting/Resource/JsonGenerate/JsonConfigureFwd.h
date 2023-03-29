/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef JSON_CONFIGURE_FWD_H
#define JSON_CONFIGURE_FWD_H

#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace JsonConfigure
{
    class MonstersContainer;

    namespace Monsters
    {
        class Data;
        class Direction;
        class Elements;
        class RodeRandom;
        class Scale;
        class SpawnPosition;
        class TargetPosition;
        class UserData;
    }

    class PartsContainer;

    namespace Parts
    {
        class Data;
        class NextPosition;
        class Scenes;
        class Up;
    }

    class RoadContainer;

    namespace Road
    {
        class Data;
    }

    class RunScenesContainer;

    namespace RunScenes
    {
        class AnchorPosition;
        class Bounds;
        class CameraLock;
        class CenterPosition;
        class Data;
        class NextLinkPosition;
        class Offset;
        class RopeStart;
        class Size;
        class StartPosition;
        class Terrains;
    }


    class JsonConfigureContainer;
}

#endif  // JSON_CONFIGURE_FWD_H
