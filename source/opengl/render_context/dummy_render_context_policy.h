#ifndef _H_PUNK_OPENGL_DUMMY_RENDER_CONTEXT
#define _H_PUNK_OPENGL_DUMMY_RENDER_CONTEXT

#include "../../config.h"
#include "../../utility/model/vertex_component.h"
#include "shaders/shader.h"

namespace OpenGL
{
	class PUNK_ENGINE DummyRenderPolicy
	{
	public:
		struct PUNK_ENGINE DummyParameters
		{
			virtual ~DummyParameters() {}
		};

	protected:
		std::auto_ptr<Shader> m_vertex_shader;
		std::auto_ptr<Shader> m_fragment_shader;
		std::auto_ptr<Shader> m_geometry_shader;

		unsigned m_program;
		bool m_was_modified;
		Utility::VertexAttributes m_vertex_attributes;
	
	public:
		DummyRenderPolicy();
		virtual void InitUniforms();
		virtual void BindParameters(const DummyParameters& params);
		virtual Utility::VertexAttributes GetRequiredAttributesSet() const;
		virtual void Begin();
		virtual void End();
		virtual void Init();
		bool SetUniformVector4f(const char * name, const float* value);
		bool SetUniformVector4f( int loc, const float* value );
		bool SetUniformVector3f(const char * name, const float* value );
		bool SetUniformVector3f(int loc, const float* value);
		bool SetUniformVector2f(const char * name, const float* value );
		bool SetUniformVector2f(int loc, const float* value );
		bool SetUniformFloat(const char * name, float value);
		bool SetUniformFloat(int loc, float value);
		bool SetUniformInt(const char * name, int value);
		bool SetUniformInt(int loc, int value);
		bool SetUniformMatrix3f(const char * name, const float* value);
		bool SetUniformMatrix3f( int loc, const float* value);
		bool SetUniformMatrix4f(const char * name, const float* value);
		bool SetUniformMatrix4f( int loc, const float* value);
		bool SetUniformArrayMatrix4f(int loc, int count, const float* value);
		int  GetUniformLocation(const char * name);
		void GetUniformVector(const char * name, float* out);
		bool SetTexture(const char * name, int texUnit);
		bool SetTexture(int loc, int texUnit);
		bool BindAttributeTo(int loc, const char * name);
		bool SetAttribute(const char * name, const float* value);
		bool SetAttribute(int index, const float* value);
		int IndexForAttrName(const char * name);
		void GetAttribute(const char * name, float* out);
		void GetAttribute(int index, float* out);
		virtual ~DummyRenderPolicy();
	};
}
#endif	//	_H_PUNK_OPENGL_DUMMY_RENDER_CONTEXT