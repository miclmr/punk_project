#ifndef _H_PUNK_OPENGL_DRIVER_WIN32
#define _H_PUNK_OPENGL_DRIVER_WIN32

#ifdef __gnu_linux__
#include "../gl/module.h"
#endif
#include <map>
#include <list>

#include "video_memory.h"
#include "../../common/video_driver.h"
#include "../render_targets/module.h"

namespace GPU
{
    struct PUNK_ENGINE_LOCAL VideoDriverImpl
	{
		//	video driver interface
        void SetFontBuilder(Utility::FontBuilder* value);
        Utility::FontBuilder* GetFontBuilder();
		void SetFullScreen(bool flag);
		bool Start(const VideoDriverDesc& desc);
		void Restart();
		void Shutdown();				
		System::Window* GetWindow();
		void SetViewport(float x, float y, float width, float height);
		void SetRenderTarget(Texture2D* color_buffer, Texture2D* depth_buffer);
		void SetClearColor(const Math::vec4& color);
		void SetClearDepth(float value);
		void Clear(bool color, bool depth, bool stencil);
        const Config& GetConfig() const;        
        bool IsSupported(const char* extension);
        void InitExtensions();
#ifdef __gnu_linux__
        void InitGlxFunctions();
#endif

		//	constructoion part
		VideoDriverImpl(VideoDriver* driver);
		~VideoDriverImpl();	

		//	implementation part
		void SwapBuffers();
		void OnResize(System::Event* e);
		void OnKeyDown(System::Event* e);

        OpenGL::VideoMemory* GetVideoMemory();
        const OpenGL::VideoMemory* GetVideoMemory() const;

	private:

		int m_shader_version;
		int m_opengl_version;

#ifdef _WIN32
		HGLRC m_opengl_context;
#elif defined __gnu_linux__
        __GLXcontextRec* ctx;
#endif

		VideoDriverDesc m_desc;
        VideoDriver* m_driver;
        OpenGL::VideoMemory* m_memory;
		std::unique_ptr<OpenGL::RenderTarget> m_rt;
        Utility::FontBuilder* m_font_builder;

	private:
		void Init();
		void Clear();
		void ReadConfig();
		void InitShaderPrograms();
		void SubscribeForSystemMessages();
		void InitInternalVertexBuffers();
	};
}

#endif	//	_H_PUNK_OPENGL_DRIVER_WIN32
