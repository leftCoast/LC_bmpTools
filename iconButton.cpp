#include <iconButton.h>


iconButton::iconButton(int xLoc,int yLoc,const char* path,int pix)
	: bmpObj(xLoc,yLoc,pix,pix,path) { setEventSet(fullClick); }
	
	
iconButton::~iconButton(void) { }


// For buttons fullClick is best. If on modals they don't bleed through events to the
// background. This is written like this so that anything that sets events will trigger
// the drawing.
void iconButton::setEventSet(eventSet inEventSet) {
	
	if (inEventSet==noEvents) {
		setGreyedOut(true);
	} else {
		setGreyedOut(false);
	}
	setNeedRefresh();
	bmpObj::setEventSet(inEventSet);
}


// If you know you want this active or not? Use this. It'll do the whole process.
void iconButton::setActive(bool trueFalse) {
				
	if (trueFalse) {
		setEventSet(fullClick);
	} else {
		setEventSet(noEvents);
	}
}


bool iconButton::getActive(void) { return !(getEventSet()==noEvents); }
