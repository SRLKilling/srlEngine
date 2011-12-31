#include <srlEngine.hpp>

using namespace srl;

int main() {

    win::Window* mWindow = new win::Window();
	mWindow->display();
	
	gl::Ext::getInstance()->initAvailableExtensions();
	
	gui::Font* mMainFont = new gui::Font("C:\\Windows\\Fonts\\arial.ttf");
	mMainFont->enableTable(0);
	mMainFont->renderFont();
	
	/*srl::Button* mOk =  new srl::Button("OK");
	srl::Button* mNon = new srl::Button("NON");
	srl::HLayout* mLayout = new srl::HLayout();
	mLayout->addElement(mOk);
	mLayout->addElement(mNon);*/
	
	//srl::HLayout* mLayout = new srl::HLayout();
	
	//Spam::mGui->setLayout(mLayout);
	
	//srl::rublyb::init();
	//srl::rublyb::doMain("main.rb");
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	
		
	gl::Context::getCurrent()->setOrthogonalProj(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);
	gl::Context::getCurrent()->useOrthogonal();
	gl::Context::getCurrent()->setModelviewMatrix(srl::mat4::identity());
	gl::Context::getCurrent()->translate(0.0, 600.0, 0.0);
	gl::Context::getCurrent()->scale(1.0, -1.0, 1.0);
	
	gui::GUI* mGui = new gui::GUI(mWindow);
	mGui->setProgram(new gl::Program("shaders/gui.glsl") );
	
	//gui::Window* win = new gui::Window();
	//mGui->addWindow(win);
	
	gui::Label* label = new gui::Label("Salut");
	label->setFont(mMainFont);
	
    win::Event event;
	while(mWindow->isRunning()) {
        while(mWindow->getEvent(&event)) {
            if(event.mType == win::Event::Quit)
                mWindow->destroy();
				
			mGui->eventProcessing(event);
        }
		
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		mGui->render();
		label->render();
			
        mWindow->display();
    }
	
    return 0;
}
