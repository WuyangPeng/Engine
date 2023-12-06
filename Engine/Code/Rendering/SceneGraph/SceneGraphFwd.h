/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/04 14:02)

#ifndef RENDERING_RENDERING_SCENE_GRAPH_FWD_H
#define RENDERING_RENDERING_SCENE_GRAPH_FWD_H

namespace Rendering
{
    enum class DepthType;
    enum class ViewFrustum;
    enum class CullingMode;
    enum class VisualPrimitiveType;
    enum class VisualUpdateType;

    class CameraFrustumData;
    class PickLine;
    class ViewVolume;
    class Camera;

    class CameraManager;
    class Spatial;
    class VisibleSet;
    class Culler;
    class Node;
    class Light;
    class CameraNode;
    class Material;
    class TriangleIndex;
    class TrianglePosition;
    class Visual;
    class Polypoint;
    class Polysegment;
    class Triangles;
    class TrianglesMesh;
    class TrianglesStrip;
    class TrianglesFan;
    class Particles;
    class Projector;
    class PickRecord;
    class Picker;
    class ScreenTarget;
    class StandardMesh;
    class ProjectionViewWorldUpdater;
}

#endif  // RENDERING_RENDERING_SCENE_GRAPH_FWD_H