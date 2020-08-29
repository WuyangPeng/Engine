// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:38)

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
		// ����͹�������Ŀ�ڶ�����������ǹ̶��ġ�
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

		// ���ù��캯����������ʹ����Щ�����������ݡ�
		void SetBones(int bonesIndex, const ConstNodeSmartPointer& node);
		void SetWeights(int bonesIndex, int verticesIndex, float weights);
		void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets);

		void SetBones(const std::vector<ConstNodeSmartPointer>& bones);
		void SetWeights(int bonesIndex, const std::vector<float>& weights);
		void SetOffsets(int bonesIndex, const std::vector<APoint>& offsets);
		
		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
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
