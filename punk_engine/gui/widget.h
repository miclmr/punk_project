#ifndef _H_PUNK_GUI_WIDGET
#define _H_PUNK_GUI_WIDGET

#include <vector>
#include "../system/system.h"
#include "../system/string.h"
#include "config.h"
#include "../system/driver/video/driver.h"

namespace GUI
{
	class LIB_GUI Widget
	{
	public:

		enum ColorType {ACTIVE_COLOR = 1, INACTIVE_COLOR, TEXT_ACTIVE_COLOR, TEXT_INACTIVE_COLOR};

	protected:

		float m_width;
		float m_height;
		float m_x, m_y;

		int m_fontSize;
		float m_activeColor[4];
		float m_inactiveColor[4];
		float m_textActiveColor[4];
		float m_textInactiveColor[4];
		float m_color[4];
		float m_textColor[4];
		bool m_isVisible;
		bool m_isEnabled;
		bool m_isCursorIn;
		bool m_leftButtonDown;
		bool m_rightButtonDown;
		bool m_middleButtonDown;
		bool m_moveable;
		bool m_isFocused;

		System::string m_text;
		System::string m_font;

		//Widget* m_parent;
		
		//std::vector<Widget*> m_children;

		System::Descriptor m_text_texture;
		System::Descriptor m_background_texture;

	
		/******************************************************************/
		/*			LIST OF HANDLERS
		/******************************************************************/
	protected:

		System::Handler m_OnLeftClick;
		System::Handler m_OnRightClick;
		System::Handler m_OnMiddleClick;
		System::Handler m_OnMouseEnter;
		System::Handler m_OnMouseLeave;
		System::Handler m_OnChar;
		System::Handler m_OnKeyDown;
		System::Handler m_OnKeyUp;
		System::Handler m_OnWheel;

	protected:
		//virtual void RenderTextToTexture();

	public:

		Widget(float x = 0, float y = 0, float width = 1, float height = 1);
		
		void RemoveChild(Widget* child);
		void AddChild(Widget* child);

		virtual ~Widget();

		virtual void Render(OpenGL::Driver* driver);

		void SetWidth(float width);
		void SetHeight(float height);
		float GetWidth() const;
		float GetHeight() const;
		float GetX() const;
		float GetY() const;
		void SetX(float x);
		void SetY(float y);
		bool IsVisible() const;
		bool IsEnabled() const;
		void Show(bool isVisible);
		void Enable(bool isEnabled);
	//	void SetParent(Widget* parent);
		//Widget* GetParent();
		//const Widget* GetParent() const;
		void FixPosition(bool isFixed);
		bool IsFixedPosition() const;
		void SetSize(float x, float y, float width, float height);
		void SetColor(ColorType type, float r, float g, float b, float a);
		void SetText(const System::string& text);
		void SetFont(const char* fontName);
		void SetTextSize(int size);
		void SetBackGroundTexture(System::Descriptor texture);

		const System::string& GetText() const;
		void SetFocuse(bool isFocused);


		virtual bool EventHandler(System::Event* event);

		bool IsPointIn(float x, float y);

		bool SendChildren(System::Event* event);  

		Widget* GetFocused(float x, float y);

		System::Descriptor GetBackGround() const;
		void SetBackGround(System::Descriptor desc);

		System::Descriptor GetTextTexture() const;
		void SetTextTexture(System::Descriptor desc);

		void Store(System::Buffer& buffer) {}
		void Restore(System::Buffer& buffer) {}
		

		/*********************************************************************/
		/*	Handlers
		/*********************************************************************/
		void OnLeftClick(System::Handler onLeftClick);
		void OnRightClick(System::Handler onRightClick);
		void OnMiddleClick(System::Handler onMiddleClick);
		void OnMouseEnter(System::Handler onMouseEnter);
		void OnMouseLeave(System::Handler onMouseLeave);
		void OnChar(System::Handler onChar);
		void OnKeyDown(System::Handler onKeyDown);
		void OnKeyUp(System::Handler onKeyUp);
		void OnWheel(System::Handler onWheel);
	};
}

#endif