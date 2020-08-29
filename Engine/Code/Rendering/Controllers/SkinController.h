// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:38)

#ifndef RENDERING_CONTROLLERS_SKIN_CONTROLLER_H
#define RENDERING_CONTROLLERS_SKIN_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "Rendering/SceneGraph/Node.h"
#include "Mathematics/Algebra/APoint.h" 

RENDERING_EXPORT_SHARED_PTR(SkinControllerImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SkinController : public Controller
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(SkinController);
		using ParentType = Controller;
		using APoint = Mathematics::APointf;

	public:
		// 顶点和骨骼的数目在对象的生存期是固定的。
		SkinController(int numVertices, int numBones);
		  ~SkinController();
		SkinController(SkinController&&) = default;
		  SkinController& operator=(SkinController&&) = default;
		  
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SkinController); 

		int GetNumVertices() const noexcept;
		int GetNumBones() const noexcept;

		const ConstNodeSmartPointer GetBones(int bonesIndex) const;
		float GetWeights(int bonesIndex, int verticesIndex) const;
		const APoint GetOffsets(int bonesIndex, int verticesIndex) const;

		// 调用构造函数后，您必须使用这些函数设置数据。
		void SetBones(int bonesIndex, const ConstNodeSmartPointer& node);
		void SetWeights(int bonesIndex, int verticesIndex, float weights);
		void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets);

		void SetBones(const std::vector<ConstNodeSmartPointer>& bones);
		void SetWeights(int bonesIndex, const std::vector<float>& weights);
		void SetOffsets(int bonesIndex, const std::vector<APoint>& offsets);
		
		// 动画更新。应用程序时间以毫秒为单位。
		 bool Update(double applicationTime) override;

		 ControllerInterfaceSmartPointer Clone() const override;

		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;
		
	private:
		IMPL_TYPE_DECLARE(SkinController);
	};
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(SkinController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fifth, SkinController); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_SKIN_CONTROLLER_H
