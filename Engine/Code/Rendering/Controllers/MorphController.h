// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:36)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "ControllerKeyInfo.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_EXPORT_SHARED_PTR(MorphControllerImpl); 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE MorphController : public Controller
	{
	public:
            COPY_UNSHARE_CLASSES_TYPE_DECLARE(MorphController, = default);
		using ParentType = Controller;
		using AVector = Mathematics::FloatAVector;
		using APoint = Mathematics::FloatAPoint;

	public:
		// �������Ŀ�����ε�Ŀ�꣬���̶�����������ڵļ���
		// ���캯����һЩ�����������Ĺ�����
		// ÿ��Ŀ�궥�㣬ʱ�䣬��Ȩ�ض���������Ӧ�ĳ�Ա���ʷ��䡣

		// numVertices: ÿ��Ŀ��Ķ�������������е�Ŀ�������ͬ�����Ķ��㡣

		// numTargets:  ���ε�Ŀ����

		// numKeys:  ������Ŀ��ÿ����������һ���ض���ʱ�䡣

		MorphController(int numVertices, int numTargets, int numKeys);
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MorphController); 

		// ���ù��캯����������ʹ����Щ�������ö������飬ʱ���Ȩ�ء�
		int GetNumVertices () const noexcept;
		int GetNumTargets () const noexcept;
		int GetNumKeys () const noexcept;
		const APoint GetVertices(int target, int vertices) const;	 
		float GetTimes(int key) const;
		float GetWeights(int key, int target) const;

		void SetVertices(int target, int vertices, const APoint& point);
		void SetTimes(int key,float times);
		void SetWeights(int key, int target,float weights);

		// �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
		 bool Update(double applicationTime) override;
		 void SetObject(ControllerInterface* object) override;
		 void SetObjectInCopy(ControllerInterface* object) override;

		 ControllerInterfaceSharedPtr Clone() const override;
                 ObjectInterfaceSharedPtr CloneObject() const override;
	protected:
		// ���ұ߽��ϵļ���
		const ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;
 
	private:
		IMPL_TYPE_DECLARE(MorphController);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(MorphController);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( MorphController); 
}
#include STSTEM_WARNING_POP

#endif // RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
