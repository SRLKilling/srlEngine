/*************************************************************************************
*                                  SRL ENGINE                                        *
*                                                                                    *
*                                                                                    *
*    Copyright (C) 2010 Pecatte Baptiste                                             *
*                                                                                    *
*    This program is free software; you can redistribute it and/or                   *
*    modify it under the terms of the GNU Lesser General Public                      *
*    License as published by the Free Software Foundation; either                    *
*    version 2.1 of the License, or (at your option) any later version.              *
*                                                                                    *
*    This program is distributed in the hope that it will be useful,                 *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU                *
*    Lesser General Public License for more details.                                 *
*                                                                                    *
*    You should have received a copy of the GNU Lesser General Public                *
*    License along with this program; if not, write to the Free Software             *
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA    *
*                                                                                    *
**************************************************************************************/


#ifndef DefineHeaderEvent
#define DefineHeaderEvent

#include <SRL/Environment.hpp>
#include <SRL/maths/ivec2.hpp>

namespace srl {

	namespace win {

		class SRLAPI Event {
			public:
				enum Type {
					NoType,

					KeyPressed,
					KeyReleased,

					CharacterEvent,

					MouseButtonPressed,
					MouseButtonReleased,

					MouseMoved,
					MouseEnterWindow,
					MouseLeaveWindow,

					WindowFocused,
					WindowLostFocus,
					WindowResized,
					WindowMoved,

					Quit,
					Destroyed
				};

				enum Sender {
					NoSender,

					// Special
					CloseButton,

					// Mouse
					LeftButton,
					RightButton,
					MiddleButton,
					MouseButton1,
					MouseButton2,

					// Space
					Space,

					// Modifier
					RightShift, LeftShift,
					RightAlt, LeftAlt,
					Meta, Hyper, Super,
					AltGr,
					RightControl,
					LeftControl,
					LeftSystemKey,
					RightSystemKey

				};

				Event(ivec2 MousePos=ivec2(), Type type = NoType, Sender sender = NoSender);
				~Event();
				
				bool operator==(Event e);
				bool operator!=(Event e);

				Type mType;
				Sender mSender;
				ivec2 mMousePos;
				char mCharacter;
		};
	
	};
	
};

#endif // CLASS_EVENT_DECLARED
