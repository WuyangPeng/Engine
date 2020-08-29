// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:41)

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
		// 这类和Camera类的唯一区别是,你可以显式地指定深度的类型。
		// Camera类被迫使用默认的深度类型(即符合当前启用图形API)。
		Projector(DepthType depthType, bool isPerspective = true,float epsilon = Math::GetZeroTolerance());
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Projector);

		// 索引0矩阵映射 x' = (1 + x) / 2 和 y' = (1 - y) / 2。
		// 索引1矩阵映射 x' = (1 + x) / 2 和 y' = (1 + y) / 2。		
		static const Matrix GetBiasScaleMatrix(int index);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Projector);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Projector); 
}

#endif // RENDERING_SCENE_GRAPH_PROJECTOR_H
