/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
#define DATABASE_GENERATE_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager final : public Framework::CameraSystemsManagerInterface
    {
    public:
        using ClassType = CameraSystemsManager;
        using ParentType = CameraSystemsManagerInterface;

    public:
        CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
