// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:41)

#ifndef RENDERING_SCENE_GRAPH_PROJECTOR_H
#define RENDERING_SCENE_GRAPH_PROJECTOR_H

#include "Camera.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Projector : public Camera		
	{
	public:
		using ClassType = Projector;
		using ParentType = Camera;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
        using ProjectorSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstProjectorSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>;
		using Matrix = Mathematics::Matrixf;

	public:
		// �����Camera���Ψһ������,�������ʽ��ָ����ȵ����͡�
		// Camera�౻��ʹ��Ĭ�ϵ��������(�����ϵ�ǰ����ͼ��API)��
		Projector(DepthType depthType, bool isPerspective = true,float epsilon = Math::GetZeroTolerance());
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Projector);

		// ����0����ӳ�� x' = (1 + x) / 2 �� y' = (1 - y) / 2��
		// ����1����ӳ�� x' = (1 + x) / 2 �� y' = (1 + y) / 2��		
		static const Matrix GetBiasScaleMatrix(int index);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Projector);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Projector); 
}

#endif // RENDERING_SCENE_GRAPH_PROJECTOR_H
