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
EXPORT_SHARED_PTR(Rendering, SkinControllerImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SkinController : public Controller
	{
	public:
            void Swap(SkinController& rhs) noexcept;
          
              public:
                  TYPE_DECLARE(SkinController);
                  using ClassShareType = CoreTools::CopyUnsharedClasses;
                  ~SkinController() noexcept= default;
                  SkinController(const SkinController& rhs);
                  SkinController& operator=(const SkinController& rhs);
                  SkinController(SkinController&& rhs) noexcept;
                  SkinController& operator=(SkinController&& rhs) noexcept;
		using ParentType = Controller;
		using APoint = Mathematics::FloatAPoint;

	public:
		// ����͹�������Ŀ�ڶ�����������ǹ̶��ġ�
		SkinController(int numVertices, int numBones);
	 
		  
		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SkinController); 

		int GetNumVertices() const noexcept;
		int GetNumBones() const noexcept;

		const ConstNodeSharedPtr GetBones(int bonesIndex) const;
		float GetWeights(int bonesIndex, int verticesIndex) const;
		const APoint GetOffsets(int bonesIndex, int verticesIndex) const;

		// ���ù��캯����������ʹ����Щ�����������ݡ�
		void SetBones(int bonesIndex, const ConstNodeSharedPtr& node);
		void SetWeights(int bonesIndex, int verticesIndex, float weights);
		void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets);

		void SetBones(const std::vector<ConstNodeSharedPtr>& bones);
		void SetWeights(int bonesIndex, const std::vector<float>& weights);
		void SetOffsets(int bonesIndex, const std::vector<APoint>& offsets);
		
		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		 bool Update(double applicationTime) override;

		 ControllerInterfaceSharedPtr Clone() const override;

		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;
                 ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
	
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(SkinController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( SkinController); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_SKIN_CONTROLLER_H
