#include "bmpFlasher.h"


bmpFlasher::bmpFlasher(int inX,int inY, int width,int height,const char* onBmp,const char* offBmp)
	: flasher(inX,inY,width,height,&black) { 
 
	mReady	= false;
	mOnBmp	= NULL;
	mOffBmp	= NULL;
	setup(onBmp,offBmp);
}

    
bmpFlasher::bmpFlasher(rect* inRect,const char* onBmpPath,const char* offBmpPath)
	: flasher(inRect,&black) { 
  
	mReady	= false;
	mOnBmp	= NULL;
	mOffBmp	= NULL;
	setup(onBmpPath,offBmpPath);
}  

    
bmpFlasher::~bmpFlasher(void) {

  if (mOnBmp) delete(mOnBmp);
  if (mOffBmp) delete(mOffBmp);
}


void bmpFlasher::setup(const char* onBmpPath,const char* offBmpPath) {

	if (onBmpPath && offBmpPath) {				// Sanity the'll try to slip NULLs opast you!
		mOnBmp = new bmpObj(this,onBmpPath);	// Create the objects..
		mOffBmp = new bmpObj(this,offBmpPath);	//
	}														//
  	mReady = mOnBmp && mOffBmp;					// Set our succoss, or not.
}


void bmpFlasher::drawSelf(void) {

	if (mReady) {							// All ducks in row?
		if (mFlash) {						// We want it on?
			mOnBmp->setLocation(x,y);	// Just in case. 
			mOnBmp->draw();				// Do it.
		} else {								// Or off?
			mOffBmp->setLocation(x,y);	// Just in case. 
      	mOffBmp->draw();				// Do it.
		}
	}
}
