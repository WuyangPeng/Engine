// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:44)

#ifndef RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
#define RENDERING_SCENE_GRAPH_SCREEN_TARGET_H

#include "Rendering/RenderingDll.h"
 
#include "Camera.h"
#include "TrianglesMesh.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ScreenTarget
	{
	public:
		using ClassType = ScreenTarget;
		using APoint = Mathematics::FloatAPoint;
		using AVector = Mathematics::FloatAVector;
		using Vector2D = Mathematics::Vector2Df;

	public:
		// 创建一个空间相机在渲染目标中使用。
		static const CameraSharedPtr CreateCamera ();
		
		// 使用指定的尺寸创建一个矩形空间内的渲染目标。
		// 顶点格式必须包含三元数组的位置和在单位0的二元数组纹理坐标。
		// 这些属性被函数填充。任何其他属性不被处理。
		// 矩形[xmin,xmax] x [ymin,ymax]必须包含在[0,1] x [0,1]。
		static const TrianglesMeshSharedPtr CreateRectangle(const VertexFormatSharedPtr& vertexFormat,int renderTargetWidth, int renderTargetHeight,
															   float xMin, float xMax,float yMin, float yMax,float zValue);
		
		// 返回矩形空间内位置。
		static std::vector<APoint> CreatePositions(int renderTargetWidth,int renderTargetHeight,float xMin,float xMax, float yMin, float yMax, float zValue);
		
		// 返回矩形空间纹理坐标。
		static std::vector<Vector2D> CreateTextureCoords();
		
	private:
		static bool ValidSizes(int renderTargetWidth, int renderTargetHeight);
		static bool ValidFormat(const VertexFormatSharedPtr& vertexFormat);
	};
}

#endif // RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
