// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:44)

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
		// ����һ���ռ��������ȾĿ����ʹ�á�
		static const CameraSharedPtr CreateCamera ();
		
		// ʹ��ָ���ĳߴ紴��һ�����οռ��ڵ���ȾĿ�ꡣ
		// �����ʽ���������Ԫ�����λ�ú��ڵ�λ0�Ķ�Ԫ�����������ꡣ
		// ��Щ���Ա�������䡣�κ��������Բ�������
		// ����[xmin,xmax] x [ymin,ymax]���������[0,1] x [0,1]��
		static const TrianglesMeshSharedPtr CreateRectangle(const VertexFormatSharedPtr& vertexFormat,int renderTargetWidth, int renderTargetHeight,
															   float xMin, float xMax,float yMin, float yMax,float zValue);
		
		// ���ؾ��οռ���λ�á�
		static std::vector<APoint> CreatePositions(int renderTargetWidth,int renderTargetHeight,float xMin,float xMax, float yMin, float yMax, float zValue);
		
		// ���ؾ��οռ��������ꡣ
		static std::vector<Vector2D> CreateTextureCoords();
		
	private:
		static bool ValidSizes(int renderTargetWidth, int renderTargetHeight);
		static bool ValidFormat(const VertexFormatSharedPtr& vertexFormat);
	};
}

#endif // RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
