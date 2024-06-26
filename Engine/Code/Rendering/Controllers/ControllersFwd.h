/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 16:22)

#ifndef RENDERING_RENDERING_CONTROLLERS_FWD_H
#define RENDERING_RENDERING_CONTROLLERS_FWD_H

namespace Rendering
{
    enum class ControllerRepeatType;

    class ControllerInterface;
    class Controller;
    class ControlledObject;
    class TransformController;
    class SkinController;
    class PointController;
    class ParticleController;
    class ControllerKeyInfo;
    class MorphController;
    class KeyframeController;
    class IKGoal;
    class IKJoint;
    class IKController;
    class BlendTransformController;
}

#endif  // RENDERING_RENDERING_CONTROLLERS_FWD_H