// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 11:22)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"
#include "VertexFormatType.h"
#include "VertexFormatElement.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(VertexFormatImpl);

namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE VertexFormat : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(VertexFormat);
		using ParentType = Object;
		using VertexFormatSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
	    using ConstVertexFormatSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;
		using AttributeType = VertexFormatFlags::AttributeType;
		using AttributeUsage = VertexFormatFlags::AttributeUsage;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:		
		virtual ~VertexFormat ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexFormat) 		
		// �����������ڴ���һ�������ʽͨ��ָ�������������ԡ�
		// �����������ֻ��һ��ͨ�õ�������Ϊ��(��������δʵ���κ���ֵ)��
		static VertexFormatSmartPointer Create(const std::vector<VertexFormatType> triple);

		static VertexFormatSmartPointer	Create(const std::vector<VertexFormatElement> triple);

		static VertexFormatSmartPointer LoadFromFile(ReadFileManager& manager);
		
		// ֧���ӳٹ��졣���ù��캯��֮�󣬱���ͨ��ʹ�� SetAttribute 'numAttributes'�������������ԡ�
		// �����ʱ������SetStride������һ���źţ�����������ɡ�Ȼ�󴴽���ص���Ⱦ��Դ��

		// ע�⣺VertexBufferAccessor�����Ķ�/д���������Ե�ƫ�ơ�
		// VertexFormat::Create��֤��һ�㣬����ҲӦ����ȷ��ʹ��SetAttribute��
		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset, 
						   AttributeType type,AttributeUsage usage,unsigned int usageIndex);
						
		int GetNumAttributes () const;
		
		unsigned int GetStreamIndex (int attribute) const;
		unsigned int GetOffset (int attribute) const;
		AttributeType GetAttributeType (int attribute) const;
		AttributeUsage GetAttributeUsage (int attribute) const;
		unsigned int GetUsageIndex (int attribute) const;		
		
		int GetStride () const;
		
		// ����ָ�����Ե�ʹ�������������ָ��ʹ������Ŀǰ�������ɫͨ������������ʹ�á�
		// �����Ե�ʹ�ó����ڸ�ʽ�У�����ֵ������i��0 <= i < GetNumAttributes()��
		// ������Ե�ʹ�ò������ڸ�ʽ�У�����ֵ��-1��
		int GetIndex (AttributeUsage usage, unsigned int usageIndex = 0) const;
		
		// ���Ե�һ�����������ֽ�����
		static int GetComponentSize (AttributeType type);
		
		// ���Բ�����������
		static int GetNumComponents (AttributeType type);
		
		// ���Ե�����������ֽ�������
		static int GetTypeSize (AttributeType type);

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile); 	

		virtual VertexFormatSmartPointer Clone() const;

		void SetStride(int stride);

	private:
		explicit VertexFormat(int numAttributes);		

		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset,const VertexFormatType& vertexFormatType);

		void SetAttribute(int attribute,const VertexFormatElement& vertexFormatElement);				

	private:
		IMPL_TYPE_DECLARE(VertexFormat);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VertexFormat);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VertexFormat); 
}

#endif // RENDERING_RESOURCES_VERTEX_FORMAT_H
