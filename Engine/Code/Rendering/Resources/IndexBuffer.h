// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:51)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
	{
	public:
		using ClassType = IndexBuffer;
		using ParentType = Buffer;
		using IndexBufferSharedPtr = std::shared_ptr<ClassType>;
		using ConstIndexBufferSharedPtr = std::shared_ptr<const ClassType>;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		IndexBuffer ();
		IndexBuffer (int numIndices, int indexSize,BufferUsage usage = BufferUsage::Static);
		  ~IndexBuffer (); 
		  IndexBuffer(const IndexBuffer&) = default;
		  IndexBuffer& operator=(const IndexBuffer&) = default;
		   IndexBuffer( IndexBuffer&&) = default;
		  IndexBuffer& operator=( IndexBuffer&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer); 

		// ������ƫ������ʹ������Ⱦ�����ơ�
		// ����������������ڶ������ͼԪ��������������ʱ����,
		// ÿ����Ԫʹ��һ������������
		// �����������,Ӧ�ó������ÿһ������Ԫ�ض�̬����SetNumElements��SetOffset��
		void SetOffset (int offset) noexcept;
		int GetOffset () const noexcept;

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile);

		virtual IndexBufferSharedPtr Clone() const;

		void InitIndexBuffer();
		void InitIndexBufferInParticles();
		void InitIndexBufferInRectangle(int index, int firstRectangleIndex, int secondRectangleIndex, int thirdRectangleIndex,int fourthRectangleIndex);
		void InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1);
		void InitIndexBuffer(const std::vector<int> indices);

		void SetIndexBuffer(int index, int original, int current);
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		int m_Offset;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(IndexBuffer);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( IndexBuffer); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_INDEX_BUFFER_H

